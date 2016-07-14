#include "httpcomponent.h"

#include "node/entity.h"
#include "node/node.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"
#include "encrypt/base64.h"
#include "encrypt/sha1.h"
#include "encrypt/md5.h"
extern "C" {
    #include "http_parser.h"
}

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

IMPLEMENT(HttpComponent)


typedef struct tagFrameHeader
{
    uint8_t opcode:4;
    uint8_t rsv:3;
    uint8_t fin:1;
    uint8_t payload_len:7;
    uint8_t mask:1;
}FrameHeader;


#define MAX_SOCKFD 10240

typedef struct tagHttpSession
{
    int sockfd; 
    unsigned int sid;
    int is_upgrade;
} HttpSession;

static HttpSession session_arr[MAX_SOCKFD];
static uint16_t sessionid_counter = 0;

static HttpSession* session_find(unsigned int sid)
{
    int sockfd = sid >> 16;
    if (sockfd <= 0 || sockfd >= MAX_SOCKFD)
    {
        return NULL;
    }
    HttpSession* session = &session_arr[sockfd];
    if (session->sid != sid)
    {
        return NULL;
    }
    return session;
}

static HttpSession* session_get(int sockfd)
{
    if (sockfd < 0 || sockfd >= MAX_SOCKFD)
    {
        return NULL;
    }
    HttpSession* session = &session_arr[sockfd];
    if (session->sockfd != sockfd)
    {
        return NULL;
    }
    return session;
}

HttpComponent::HttpComponent():Component()
{
}

HttpComponent::~HttpComponent()
{

}

int HttpComponent::session_init(int sockfd)
{
    if (sockfd < 0 || sockfd >= MAX_SOCKFD)
    {
        return 0;
    }
    HttpSession* session = &session_arr[sockfd];
    memset(session, 0, sizeof(HttpSession));
    session->sockfd = sockfd;
    session->sid = sockfd << 16 | sessionid_counter++;
    return session->sid;
}

void HttpComponent::session_destory(int sockfd)
{

}

int HttpComponent::recv(Message* msg)
{
    switch(msg->header.id)
    {
        case MSG_CLOSE_CONNECTION:
            {
                return recv_close_connection(msg);
            }
            break;
        case MSG_NEW_CONNECTION:
            {
                return recv_new_connection(msg);
            }
            break;
        case MSG_NET_RAW_DATA:
            {
                return recv_net_raw_data(msg);
            }
            break;
    }
    return 0;
}

static int on_message_begin(http_parser *p)
{
    printf("on_message_begin\n");
    return 0;
}

static int on_headers_complete(http_parser *p)
{
    printf("on_headers_complete\n");
    return 0;
}
static int on_message_complete(http_parser *p)
{
    printf("on_message_complete\n");
    return 0;
}
static int on_chunk_complete(http_parser *p)
{
    printf("on_chunk_complete\n");
    return 0;
}
static int on_chunk_header(http_parser *p)
{
    printf("on_chunk_header\n");
    return 0;
}

static int on_header_field(http_parser *p, const char *buf, size_t len)
{
    printf("on_header_field\n");
    http_request* request = (http_request *)p->data;
    if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    {
        return 1;
    }
    request->headers[request->header_count].field.buf = buf;
    request->headers[request->header_count].field.len = len;
    return 0;
}
static int on_header_value(http_parser *p, const char *buf, size_t len)
{
    printf("on_header_value\n");
    http_request* request = (http_request *)p->data;
    if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    {
        return 1;
    }
    request->headers[request->header_count].value.buf = buf;
    request->headers[request->header_count].value.len = len;
    request->header_count++;
    return 0;
}
static int on_url(http_parser *p, const char *buf, size_t len)
{
    printf("on_url\n");
    http_request* request = (http_request *)p->data;
    request->url.buf = buf;
    request->url.len = len;
    return 0;
}
static int on_status(http_parser *p, const char *buf, size_t len)
{
    printf("on_status\n");
    return 0;
}
static int on_body(http_parser *p, const char *buf, size_t len)
{
    printf("on_body\n");
    http_request* request = (http_request *)p->data;
    request->body.buf = buf;
    request->body.len = len;
    return 0;
}

int HttpComponent::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    printf("HttpComponent recv_new_connection %d\n", sockfd);
    int sid = session_init(sockfd);

    Message* msg2 = alloc_msg();
    msg2->header.src_nodeid = 0;
    msg2->header.src_entityid = 0;
    msg2->header.dst_entityid = 0;
    msg2->header.dst_nodeid = 0;
    msg2->header.id = MSG_NEW_SESSION;
    msg2->sid = sid;
    this->entity->recv(msg2);
    return 0;
}

int HttpComponent::recv_close_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    printf("HttpComponent recv_close_connection %d\n", sockfd);
    HttpSession* session = session_get(sockfd);
    if (session)
    {
        Message* msg2 = alloc_msg();
        msg2->header.src_nodeid = 0;
        msg2->header.src_entityid = 0;
        msg2->header.dst_entityid = 0;
        msg2->header.dst_nodeid = 0;
        msg2->header.id = MSG_CLOSE_SESSION;
        msg2->sid = session->sid;
        this->entity->recv(msg2);
    }
    session_destory(sockfd);


    return 0;
}

int HttpComponent::decode_one_frame(int sockfd, const char* data, size_t datalen)
{
    if(datalen < 2)
    {
        return 0;
    }
    FrameHeader* frame_header = (FrameHeader*)data;
    printf("fin(%d) rsv(%d) mask(%d) opcode(%d) payload_len(%d)\n", 
            frame_header->fin, frame_header->rsv, frame_header->mask, frame_header->opcode, frame_header->payload_len);
    //接下来开始计算真实的长度
    uint64_t framelen = 2;
    uint64_t real_payload_len = frame_header->payload_len;
    //掩码
    unsigned char *mask = 0;
    //负载
    char *payload_data = 0;
    if (frame_header->payload_len == 126)
    {
        framelen = 4;
    }
    else if (frame_header->payload_len == 127)
    {
        framelen = 9;
    }
    if (frame_header->mask == 1)
    {
        mask = (unsigned char *)data + framelen;
        framelen += 4;
    }
    //负载
    payload_data = (char *)data + framelen;

    //测试数据长度
    if (datalen < framelen)
    {
        return 0;
    }

    //解释负载长度
    if (frame_header->payload_len == 126)
    {
        //2个字节的长度
        real_payload_len = ntohs(*((uint16_t*)(data + 2)));
    }
    else if (frame_header->payload_len == 127)
    {
        //暂时不支持8字节长度
        //TODO ntohl只能用于32位数
        //unsigned int* _real_len32 = (unsigned int*)(&real_payload_len);
        //_real_len32[0] = ntohl(*((unsigned int*)(data + 4)));
        //_real_len32[1] = ntohl(*((unsigned int*)(data + 2)));
        real_payload_len = ntohl(*((uint64_t*)(data + 2)));
    }
    framelen += real_payload_len;
    //测试数据长度
    if (datalen < framelen)
    {
        return 0;
    }
    printf("real_payload_len(%ld)\n", real_payload_len);
    //用掩码修改数据
    if (frame_header->mask == 1)
    {
        for (uint64_t i = 0; i < real_payload_len; i++)
        {
            payload_data[i] = payload_data[i] ^ mask[i % 4];
        }
    }
    //LOG_DEBUG("%s", data);
    //LOG_DEBUG("payload %s", payload_data);
    //是否最后一帧了
    return frame_header->fin;
}

int HttpComponent::combine_all_frame(int sockfd, const char* data , size_t datalen)
{
    char* framedata = (char*)data;
    char* combine_payload_data = (char*)data;
    uint64_t packet_len = 0;
    uint64_t total_len = 0;
    int opcode = 0;
    for(;;)
    {
        FrameHeader* frame_header = (FrameHeader*)framedata;
        int fin = frame_header->fin;
        opcode = frame_header->opcode;
        uint64_t framelen = 2;
        uint64_t real_payload_len = frame_header->payload_len;
        char *payload_data = 0;
        //解释负载长度
        if (frame_header->payload_len == 126)
        {
            framelen = 4;
        }
        else if (frame_header->payload_len == 127)
        {
            framelen = 9;
        }
        if (frame_header->mask == 1)
        {
            framelen += 4;
        }
        //负载
        payload_data = (char *)framedata + framelen;
        if (frame_header->payload_len == 126)
        {
            //2个字节的长度
            real_payload_len = ntohs(*((uint16_t*)(framedata + 2)));
        }
        else if (frame_header->payload_len == 127)
        {
            //暂时不支持8字节长度
            //8个字节的长度
            //TODO ntohl只能用于32位数
            real_payload_len = ntohl(*((uint64_t*)(framedata+ 2)));

        }
        framelen += real_payload_len;

        //直接复制数据吧
        memcpy(combine_payload_data, payload_data, real_payload_len);
        total_len += framelen;
        packet_len += real_payload_len;
        framedata += framelen;
        combine_payload_data += real_payload_len;
        if (fin == 1)
        {
            break;
        }
    }
    *combine_payload_data = 0;
    dispatch_frame(sockfd, opcode, data, packet_len);
    return total_len;
}

int HttpComponent::dispatch_frame(int sockfd, int opcode, const char* data, size_t datalen)
{
    HttpSession* session = session_get(sockfd);
    //lua_State* L = get_lua_state(); 
    printf("websocket recv a frame sid(%d) opcode(%d) datalen(%ld)\n", session->sid, opcode, datalen);
    Message* msg = alloc_msg();
    msg->header.src_nodeid = 0;
    msg->header.src_entityid = 0;
    msg->header.dst_entityid = 0;
    msg->header.dst_nodeid = 0;
    msg->header.id = MSG_NET_PACKET;
    msg->sockfd = sockfd;
    msg->sid = session->sid;
    msg->payload.reset();
    msg->payload.write_buf(data, datalen);
    this->entity->recv(msg);
    return 0;
}

int HttpComponent::recv_net_raw_data(Message* msg)
{
    printf("HttpComponent recv_net_raw_data\n");

    const char* data = msg->payload.get_buffer();
    size_t datalen = msg->payload.size();
    int sockfd = msg->sockfd;

    HttpSession *session = session_get(sockfd);
    if (!session)
    {
        printf("HttpComponent session not found\n");
        return datalen;
    }
    if (session->is_upgrade)
    {
        printf("HttpComponent recv a frame\n");
        if(decode_one_frame(sockfd, data, datalen) == 0)
        {
            return 0;
        }
        //全部帧都到了
        return combine_all_frame(sockfd, data, datalen);
    }

    http_parser_settings settings;
    settings.on_message_begin = on_message_begin;
    settings.on_header_field = on_header_field;
    settings.on_header_value = on_header_value;
    settings.on_url = on_url;
    settings.on_status = on_status;
    settings.on_body = on_body;
    settings.on_headers_complete = on_headers_complete;
    settings.on_message_complete = on_message_complete;
    settings.on_chunk_header = on_chunk_header;
    settings.on_chunk_complete = on_chunk_complete;
    //http_parser parser;
    http_parser parser;
    http_parser_init(&parser, HTTP_REQUEST);

    http_request request;
    memset(&request, 0, sizeof(request));
    parser.data = &request;

    size_t parsed = http_parser_execute(&parser, &settings, (const char*)data, datalen);
    /*  
     *  Start up / continue the parser.
     *  Note we pass recved==0 to signal that EOF has been received.
     */
    //printf("parsed %d nread %d\n", parsed, parser.nread);
    if(parsed != datalen)
    {
        /*  Handle error. Usually just close the connection. */ 
        return datalen;
    }
    else if (parser.upgrade)
    {
        /*  handle new protocol */ 
        //printf("handle new proto %s\n", data);
        for (int i = 0; i < request.header_count; i++)
        {
            http_header* header = &request.headers[i];
            if(strncmp(header->field.buf, "Sec-WebSocket-Key", header->field.len))
            {
                continue;
            }

            //printf("Sec-WebSocket-Key: %s", header->value.buf);

            static unsigned char sha1_out[20];
            static unsigned char sec_websocket_key[128];
            static char sec_websocket_accept[128];
            static char datestr[128];

            SHA1_CTX context; 
            SHA1Init(&context); 
            //计算sha1
            memcpy(sec_websocket_key, header->value.buf, header->value.len);
            sec_websocket_key[header->value.len] = 0;
            strcat((char*)sec_websocket_key, "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
            SHA1Update(&context, sec_websocket_key, strlen((char *)sec_websocket_key)); 
            SHA1Final(sha1_out, &context); 

            //计算base64
            base64_encode(sha1_out, sizeof(sha1_out), sec_websocket_accept);

           // 计算日期
            time_t t = time(NULL);
            struct tm* tmp = localtime(&t);
            strftime(datestr, sizeof(datestr), "Date:%a, %d %b %Y %H:%M:%S GMT\r\n", tmp);

            //printf("Sec-WebSocket-Accept: %s\n", sec_websocket_accept);

            net_component->send_str(sockfd, "HTTP/1.1 101 Switching Protocols\r\n"
                         "Connection:Upgrade\r\n"
                         "Server:lujingwei002@qq.com\r\n"
                         "Upgrade:WebSocket\r\n"
                         "Access-Control-Allow-Credentials:true\r\n"
                         "Access-Control-Allow-Headers:content-type\r\n");
            net_component->send_str(sockfd, datestr);
            net_component->send_str(sockfd, "Sec-WebSocket-Accept:");
            net_component->send_str(sockfd, sec_websocket_accept);
            net_component->send_str(sockfd, "\r\n\r\n");
            session->is_upgrade = 1;
        }
        return datalen;
    } else
    {
        return datalen;
    }
}


void HttpComponent::awake()
{
    this->net_component = (NetComponent*)this->entity->get_component("NetComponent");
    this->entity->reg_msg(MSG_NEW_CONNECTION, this);
    this->entity->reg_msg(MSG_CLOSE_CONNECTION, this);
    this->entity->reg_msg(MSG_NET_RAW_DATA, this);
}

int HttpComponent::send_binary_frame(int sid, Buffer* buffer)
{
    return send_frame(sid, 2, buffer->get_buffer(), buffer->size());
}

int HttpComponent::send_binary_frame(int sid, const void* data, unsigned short datalen)
{
    return send_frame(sid, 2, data, datalen);
}

//发送字符串帧
int HttpComponent::send_string_frame(int sid, const char* str)
{
    return send_frame(sid, 1, str, strlen(str) + 1);
}

//发送帧
int HttpComponent::send_frame(int sid, int opcode, const void* data, unsigned short datalen)
{
    printf("Websocket.send_frame sid(%d) opcode(%d) datalen(%d)\n", sid, opcode, datalen);
    HttpSession* session = session_find(sid);
    if(!session)
    {
        printf("session not found\n");
        return 0;
    }
    int sockfd = session->sockfd;
    //统一使用2字长长度
    FrameHeader header;
    header.fin = 1;//结束帧
    header.rsv = 0;
    header.opcode = opcode;
    header.mask = 0;//没有掩码
    if (datalen >= 126)
    {
        header.payload_len = 126;
        unsigned short real_len = htons(datalen);
        net_component->send(sockfd, &header, sizeof(header));
        net_component->send(sockfd, &real_len, sizeof(real_len));
        net_component->send(sockfd, data, datalen);
    } else 
    {
        header.payload_len = datalen;
        net_component->send(sockfd, &header, sizeof(header));
        net_component->send(sockfd, data, datalen);
    }
    return 0;
}

