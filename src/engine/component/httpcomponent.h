
#ifndef _HTTP_COMPONENT_H_
#define _HTTP_COMPONENT_H_

#include "component/component.h"
#include "component/netcomponent.h"

typedef struct http_string
{
    char* buf;
    size_t len;
}http_string;

typedef struct http_header
{
    http_string field; 
    http_string value;
}http_header;

#define MAX_HTTP_HEADER_COUNT 32
typedef struct http_request
{
    http_header headers[MAX_HTTP_HEADER_COUNT];
    unsigned char header_count;
    http_string url; 
    http_string body;
    http_string method;
}http_request;

//tolua_begin
class HttpComponent : public Component
{
    public:
        HttpComponent();
        virtual ~HttpComponent();
        virtual int recv(Message* msg);
        virtual void awake();
        int send_binary_frame(int sid, const void* data, unsigned short datalen);
        int send_binary_frame(int sid, Buffer* buffer);
        int send_string_frame(int sid, const char* str);
        int send_string(int sid, const char* str);
        int send_string(lua_State* L);
        int send_buffer(int sid, Buffer* buffer);
    public:
//tolua_end
        int recv_new_connection(Message* msg);
        int recv_close_connection(Message* msg);
        int recv_net_raw_data(Message* msg);
        int send_str(int sockfd, const char* data);
        int _real_send(int sockfd, const void* data, size_t datalen);
        int session_init(int sockfd);
        void session_destory(int sockfd);
        int combine_all_frame(int sockfd, const char* data , size_t datalen);
        int decode_one_frame(int sockfd, const char* data, size_t datalen);
        int dispatch_frame(int sockfd, int opcode, const char* data, size_t datalen);
        int send_frame(int sid, int opcode, const void* data, unsigned short datalen);
        int dispatch_request(int sockfd);
    private:
        NetComponent* net_component;
//
DECLAR(HttpComponent);

};//tolua_export

#endif
