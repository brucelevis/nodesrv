
#ifndef _HTTP_COMPONENT_H_
#define _HTTP_COMPONENT_H_

#include "component/component.h"
#include "components/netcomponent.h"

typedef struct http_string
{
    const char* buf;
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
}http_request;

//tolua_begin
class HttpComponent : public Component
{
    public:
        HttpComponent();
        virtual ~HttpComponent();
        virtual int recv(MsgHeader* header, const void* data, size_t datalen);
        virtual void awake();
    public:
//tolua_end
        int recv_new_connection(MsgHeader* header, const void* data, size_t datalen);
        int recv_net_raw_data(MsgHeader* header, const void* data, size_t datalen);
        int send_str(int sockfd, const char* data);
        int _real_send(int sockfd, const void* data, size_t datalen);
    private:
        NetComponent* net_component;
//
DECLAR(HttpComponent);

};//tolua_export

#endif
