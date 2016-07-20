#include "httpcomponent.h"

#include "node/gameobject.h"
#include "log/log.h"
#include "net/http.h"
#include "node/node.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"
#include "encrypt/base64.h"
#include "encrypt/sha1.h"
#include "encrypt/md5.h"
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

int HttpComponent::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("HttpComponent recv_new_connection sockfd(%d)", sockfd);
    int sid = session_init(sockfd);
    Message* msg2 = alloc_msg();
    msg2->header.src_nodeid = 0;
    msg2->header.src_objectid = 0;
    msg2->header.dst_objectid = 0;
    msg2->header.dst_nodeid = 0;
    msg2->header.id = MSG_NEW_SESSION;
    msg2->sid = sid;
    this->gameobject->recv(msg2);
    return 0;
}

int HttpComponent::recv_close_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("HttpComponent recv_close_connection sockfd(%d)", sockfd);
    HttpSession* session = session_get(sockfd);
    if (!session)
    {
        return 0;
    }
    Message* msg2 = alloc_msg();
    msg2->header.src_nodeid = 0;
    msg2->header.src_objectid = 0;
    msg2->header.dst_objectid = 0;
    msg2->header.dst_nodeid = 0;
    msg2->header.id = MSG_CLOSE_SESSION;
    msg2->sid = session->sid;
    this->gameobject->recv(msg2);
    session_destory(sockfd);
    return 0;
}

int HttpComponent::dispatch_frame(int sockfd, http_frame_request& frame)
{
    HttpSession* session = session_get(sockfd);
    frame_header* header = &(frame.header);
    LOG_MSG("HttpComponent dispatch a frame sid(%d) opcode(%d) framelen(%ld)", session->sid, header->opcode, frame.frame_len);
    Message* msg = alloc_msg();
    msg->header.src_nodeid = 0;
    msg->header.src_objectid = 0;
    msg->header.dst_objectid = 0;
    msg->header.dst_nodeid = 0;
    msg->header.id = MSG_NET_PACKET;
    msg->sockfd = sockfd;
    msg->sid = session->sid;
    msg->payload.reset();
    msg->payload.write_buf(frame.payload, frame.payload_len);
    this->gameobject->recv(msg);
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

        lua_pushnil(L);
        lua_setglobal(L, "_POST");
        lua_newtable(L);
        lua_setglobal(L, "_POST");
        lua_getglobal(L, "_POST");
        for (int i = 0; i < request.post_count; i++)
        {
            http_header* post  = &request.post[i];
            lua_pushlstring(L, post->field.buf, post->field.len);
            lua_pushlstring(L, post->value.buf, post->value.len);
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
        http_frame_request frame;
        http_frame_parse(frame, data, datalen);
        if (frame.frame_len == 0)
        {
            return 0;
        }
        dispatch_frame(sockfd, frame);
        return frame.frame_len;
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
        //抽出消息头
        http_request& request = session->request;
        http_parse(request, data, datalen, header_len);
        session->header_len = header_len;
        session->content_length = request.content_length;
        session->is_upgrade = request.is_upgrade;
        if (datalen < session->content_length + header_len)
        {
            LOG_WARN("wait body");
            return header_len;
        }
        request.body.buf = data + header_len;
        request.body.len = datalen - header_len;
        http_post_parse(request, request.body.buf, request.body.len);
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
        http_post_parse(request, request.body.buf, request.body.len);
        dispatch_request(sockfd);
        return datalen;
    }
    return 0;
}


void HttpComponent::awake()
{
    this->net_component = (NetComponent*)this->gameobject->get_component("NetComponent");
    this->gameobject->reg_msg(MSG_NEW_CONNECTION, this);
    this->gameobject->reg_msg(MSG_CLOSE_CONNECTION, this);
    this->gameobject->reg_msg(MSG_NET_RAW_DATA, this);
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
    frame_header header;
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
