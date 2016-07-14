#include "httpcomponent.h"

#include "node/entity.h"
#include "log/log.h"
#include "net/http.h"
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

#define CRLF2 "\r\n\r\n"
#define CRLF "\r\n"

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
    uint32_t header_len;
    uint32_t content_length;
    http_request request;
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

/*  
static int on_message_begin(http_parser *p)
{
    LOG_DEBUG("on_message_begin");
    return 0;
}

static int on_headers_complete(http_parser *p)
{
    LOG_DEBUG("on_headers_complete");
    return 0;
}
static int on_message_complete(http_parser *p)
{
    LOG_DEBUG("on_message_complete");
    return 0;
}
static int on_chunk_complete(http_parser *p)
{
    LOG_DEBUG("on_chunk_complete");
    return 0;
}
static int on_chunk_header(http_parser *p)
{
    LOG_DEBUG("on_chunk_header");
    return 0;
}

static int on_header_field(http_parser *p, const char *buf, size_t len)
{
    LOG_DEBUG("on_header_field");

    //http_request* request = (http_request *)p->data;
    //if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    //{
        //return 1;
    //}
    //request->headers[request->header_count].field.buf = buf;
    //request->headers[request->header_count].field.len = len;
    return 0;
}
static int on_header_value(http_parser *p, const char *buf, size_t len)
{
    LOG_DEBUG("on_header_value");
    //http_request* request = (http_request *)p->data;
    //if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    //{
        //return 1;
    //}
    //request->headers[request->header_count].value.buf = buf;
    //request->headers[request->header_count].value.len = len;
    //request->header_count++;
    return 0;
}
static int on_url(http_parser *p, const char *buf, size_t len)
{
    LOG_DEBUG("on_url");
    //http_request* request = (http_request *)p->data;
    //request->url.buf = buf;
    //request->url.len = len;
    return 0;
}
static int on_status(http_parser *p, const char *buf, size_t len)
{
    LOG_DEBUG("on_status");
    return 0;
}
static int on_body(http_parser *p, const char *buf, size_t len)
{
    LOG_DEBUG("on_body");
    //http_request* request = (http_request *)p->data;
    //request->body.buf = buf;
    //request->body.len = len;
    return 0;
}
*/

int HttpComponent::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("HttpComponent recv_new_connection sockfd(%d)", sockfd);
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
    LOG_DEBUG("HttpComponent recv_close_connection sockfd(%d)", sockfd);
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
    LOG_DEBUG("fin(%d) rsv(%d) mask(%d) opcode(%d) payload_len(%d)", 
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
    LOG_DEBUG("real_payload_len(%ld)", real_payload_len);
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
    LOG_MSG("HttpComponent dispatch a frame sid(%d) opcode(%d) datalen(%ld)", session->sid, opcode, datalen);
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

int HttpComponent::dispatch_request(int sockfd)
{
    LOG_INFO("dispatch_request");

    HttpSession *session = session_get(sockfd);
    if (!session)
    {
        LOG_ERROR("HttpComponent session not found\n");
        return 0;
    }
    if (session->is_upgrade)
    {
        http_request& request = session->request;
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
        }
    } else 
    {
        //默认交给lua处理
        //开始设置环境
        lua_State* L = get_lua_state();


        http_request& request = session->request;

        lua_pushnil(L);
        lua_setglobal(L, "_HEADER");
        lua_newtable(L);
        lua_setglobal(L, "_HEADER");
        lua_getglobal(L, "_HEADER");
        for (int i = 0; i < request.header_count; i++)
        {
            http_header* header = &request.headers[i];
            lua_pushlstring(L, header->field.buf, header->field.len);
            lua_pushlstring(L, header->value.buf, header->value.len);
            lua_settable(L, -3);
        }

         lua_pushnil(L);
        lua_setglobal(L, "_COOKIE");
        lua_newtable(L);
        lua_setglobal(L, "_COOKIE");
        lua_getglobal(L, "_COOKIE");
        for (int i = 0; i < request.cookie_count; i++)
        {
            http_header* cookie = &request.cookie[i];
            lua_pushlstring(L, cookie->field.buf, cookie->field.len);
            lua_pushlstring(L, cookie->value.buf, cookie->value.len);
            lua_settable(L, -3);
        }

        lua_pushnil(L);
        lua_setglobal(L, "_GET");
        lua_newtable(L);
        lua_setglobal(L, "_GET");
        lua_getglobal(L, "_GET");
        for (int i = 0; i < request.get_count; i++)
        {
            http_header* get = &request.get[i];
            lua_pushlstring(L, get->field.buf, get->field.len);
            lua_pushlstring(L, get->value.buf, get->value.len);
            lua_settable(L, -3);
        }

        lua_pushlstring(L, request.url.buf, request.url.len);
        lua_setglobal(L, "_REQUEST_URL");

        lua_pushlstring(L, request.query_string.buf, request.query_string.len);
        lua_setglobal(L, "_QUERY_STRING");

        lua_pushlstring(L, request.method.buf, request.method.len);
        lua_setglobal(L, "_METHOD");

        lua_pushnil(L);
        lua_setglobal(L, "_CONTENT");
        if (request.body.len != 0)
        {
            lua_pushlstring(L, request.body.buf, request.body.len);
            lua_setglobal(L, "_CONTENT");
        }
        lua_pushfunction("_REQUEST");
        tolua_pushusertype(L, this, "HttpComponent");
        lua_pushnumber(L, session->sid);
        if (lua_pcall(L, 2, 0, 0) != 0)
        {
            printf("HttpComponent dispatch request error %s\n", lua_tostring(L, -1));
            lua_printstack();
        }
        lua_pop(L, lua_gettop(L));
    }
    //重置
    session->header_len = 0;
    return 0;
}

int HttpComponent::recv_net_raw_data(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("HttpComponent recv_net_raw_data sockfd(%d)\n", sockfd);

    char* data = (char*)msg->data;
    size_t datalen = msg->datalen;

    HttpSession *session = session_get(sockfd);
    if (!session)
    {
        LOG_ERROR("HttpComponent session not found\n");
        return datalen;
    }
    if (session->is_upgrade)
    {
        LOG_DEBUG("HttpComponent recv a frame\n");
        if(decode_one_frame(sockfd, data, datalen) == 0)
        {
            return 0;
        }
        //全部帧都到了
        return combine_all_frame(sockfd, data, datalen);
    } else if (session->header_len == 0)
    {
        //接收请求头
        uint32_t header_len = 0;
        //搜索\r\n\r\n
        for (uint32_t i = 0; i < datalen; i++)
        {
            if(strncmp(data + i, CRLF2, 4) == 0)
            {
                //找到
                header_len = i + 4;
                break;
            }
        }
        //消息头末找到
        if (header_len == 0)
        {
            return 0;
        }
        session->header_len = header_len;
    
        //抽出消息头
        http_request& request = session->request;
        request.header_count = 0;
        char* header_field = data;
        char* header_value = NULL;
        for (uint32_t i = 0; i < header_len; i++)
        {
            //寻找field
            if (header_value == NULL)
            {
                if (data[i] == ':' || data[i] == ' ')
                {
                    request.headers[request.header_count].field.buf = header_field;
                    request.headers[request.header_count].field.len = data + i - header_field;
                    uint32_t k = i + 1;
                    for (; k < header_len; k++)
                    {
                        if (data[k] != ':' && data[k] != ' ')
                        {
                            header_value = data + k;
                            break;
                        }
                    }
                    i = k + 1;
                }
            } else
            {
                if (data[i] == '\r')
                {
                    request.headers[request.header_count].value.buf = header_value;
                    request.headers[request.header_count].value.len = data + i - header_value;
                    request.header_count++;
                    if (request.header_count >= MAX_HTTP_HEADER_COUNT)
                    {
                        break;
                    }
                    header_field = data + i + 2;
                    header_value = NULL;
                }
            }
        }
        //分析header
        request.cookie_count = 0;
        for (int i = 0; i < request.header_count; i++)
        {
            http_header& header = request.headers[i];

            char c1 = header.value.buf[header.value.len];
            header.value.buf[header.value.len] = 0;
            char c2 = header.field.buf[header.field.len];
            header.field.buf[header.field.len] = 0;

            LOG_MSG("header %s", header.field.buf);
            LOG_MSG("header %s", header.value.buf);
            if(strncmp(header.field.buf, "Content-Length", 14) == 0)
            {
                session->content_length = atoi(header.value.buf);
            }
            if(strcmp(header.field.buf, "Upgrade") == 0)
            {
                LOG_DEBUG("Upgrade");
                session->is_upgrade = 1;
            }
            if(strcmp(header.field.buf, "Cookie") ==  0)
            {
                request.cookie[request.cookie_count].field.buf = header.value.buf;
                for(int i = 0; i < header.value.len; i++)
                {
                    if(header.value.buf[i] == '=')
                    {
                        request.cookie[request.cookie_count].field.len = header.value.buf + i - request.cookie[request.cookie_count].field.buf;;
                        request.cookie[request.cookie_count].value.buf = header.value.buf + i + 1;
                    }
                    if(header.value.buf[i] == ';')
                    {
                        request.cookie[request.cookie_count].value.len = header.value.buf + i - request.cookie[request.cookie_count].value.buf;;
                        request.cookie_count++;
                        if (request.cookie_count >= MAX_HTTP_COOKIE_COUNT)
                        {
                            break;
                        }
                        request.cookie[request.cookie_count].field.buf = header.value.buf + i + 2;
                    }
                    if(i == header.value.len - 1)
                    {
                        request.cookie[request.cookie_count].value.len = header.value.buf + i + 1 - request.cookie[request.cookie_count].value.buf;;
                        request.cookie_count++;
                    }
                }
            }
            if(i == 0)
            {
                request.method.buf = header.field.buf;
                request.method.len = header.field.len;

                request.url.buf = header.value.buf;
                request.query_string.len = 0;
                bool has_query_string = false;
                for(uint32_t k = 0; k < header.value.len; k++)
                {
                    if (header.value.buf[k] == '?')
                    {
                        request.url.len = k;
                        request.query_string.buf = header.value.buf + k + 1;
                        has_query_string = true;
                    }
                    if (header.value.buf[k] == ' ')
                    {
                        if (has_query_string)
                        {
                            request.query_string.len = header.value.buf + k - request.query_string.buf;
                        } else 
                        {
                            request.url.len = k;
                        }
                    }
                }
            }
            header.value.buf[header.value.len] = c1;
            header.field.buf[header.field.len] = c2;
        }
        //分析header
        request.get_count = 0;
        request.get[request.get_count].field.buf = request.query_string.buf;
        for(int i = 0; i < request.query_string.len; i++)
        {
            if(request.query_string.buf[i] == '=')
            {
                request.get[request.get_count].field.len = request.query_string.buf + i - request.get[request.get_count].field.buf;;
                request.get[request.get_count].value.buf = request.query_string.buf + i + 1;
            }
            if(request.query_string.buf[i] == '&')
            {
                request.get[request.get_count].value.len = request.query_string.buf + i - request.get[request.get_count].value.buf;;
                request.get_count++;
                if (request.get_count >= MAX_HTTP_GET_COUNT)
                {
                    break;
                }
                request.get[request.get_count].field.buf = request.query_string.buf + i + 1;
            }
            if(i == request.query_string.len - 1)
            {
                request.get[request.get_count].value.len = request.query_string.buf + i + 1 - request.get[request.get_count].value.buf;;
                request.get_count++;
            }
        }
        for (int i = 0; i < request.get_count; i++)
        {
            http_header& get = request.get[i];
            get.field.len = Http::urldecode(get.field.buf, get.field.len, get.field.buf, get.field.len);
            get.value.len = Http::urldecode(get.value.buf, get.value.len, get.value.buf, get.value.len);
        }



        if (datalen < session->content_length + header_len)
        {
            LOG_WARN("wait body");
            return header_len;
        }
        request.body.buf = data + header_len;
        request.body.len = datalen - header_len;
        dispatch_request(sockfd);
        return header_len;
    } else 
    {
        if (datalen < session->content_length)
        {
            return 0;
        }
        http_request& request = session->request;
        request.body.buf = data;
        request.body.len = datalen;
        dispatch_request(sockfd);
        return datalen;
    }
    return 0;
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

int HttpComponent::send_string(lua_State* L)
{
    if (!lua_isnumber(L, 2))
    {
        LOG_ERROR("arg error");
        return 0;
    }
    if (!lua_isstring(L, 3))
    {
        LOG_ERROR("arg error");
        return 0;
    }
    int sid = (int)lua_tonumber(L, 2);
    HttpSession* session = session_find(sid);
    if (!session)
    {
        LOG_ERROR("session(%d) not found", sid);
        return 0;
    }
    int sockfd = session->sockfd;
    size_t str_len = 0;
    const char* data = (const char*)lua_tolstring(L, 3, &str_len);
    net_component->send(sockfd, data, str_len);
    return 0;
}

int HttpComponent::send_string(int sid, const char* str)
{
    HttpSession* session = session_find(sid);
    if (!session)
    {
        LOG_ERROR("session(%d) not found", sid);
        return 0;
    }
    int sockfd = session->sockfd;
    return net_component->send(sockfd, str, sizeof(str));
}

//发送帧
int HttpComponent::send_frame(int sid, int opcode, const void* data, unsigned short datalen)
{
    LOG_MSG("HttpComponent::send_frame sid(%d) opcode(%d) datalen(%d)", sid, opcode, datalen);
    HttpSession* session = session_find(sid);
    if(!session)
    {
        LOG_ERROR("session not found\n");
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

int HttpComponent::send_buffer(int sid, Buffer* buffer)
{
    HttpSession* session = session_find(sid);
    if (!session)
    {
        LOG_ERROR("session(%d) not found", sid);
        return 0;
    }
    int sockfd = session->sockfd;
    return net_component->send(sockfd, buffer->get_buffer(), buffer->size());
}
