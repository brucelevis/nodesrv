
#ifndef _HTTP_COMPONENT_H_
#define _HTTP_COMPONENT_H_

#include "component/component.h"
#include "component/netcomponent.h"
#include "net/http_parser.h"

class HttpComponent : public Component {//tolua_export
    public:
        HttpComponent();//tolua_export
        virtual ~HttpComponent();//tolua_export
        virtual int recv(Message* msg);//tolua_export
        virtual void awake();//tolua_export
        int send_binary_frame(int sid, const void* data, unsigned short datalen);//tolua_export
        int send_binary_frame(int sid, Buffer* buffer);//tolua_export
        int send_string_frame(int sid, const char* str);//tolua_export
        int send_string(int sid, const char* str);//tolua_export
        int send_string(lua_State* L);//tolua_export
        int send_buffer(int sid, Buffer* buffer);//tolua_export
    public:
        int recv_new_connection(Message* msg);
        int recv_close_connection(Message* msg);
        int recv_net_raw_data(Message* msg);
        int send_str(int sockfd, const char* data);
        int _real_send(int sockfd, const void* data, size_t datalen);
        int session_init(int sockfd);
        void session_destory(int sockfd);
        int combine_all_frame(int sockfd, const char* data , size_t datalen);
        int dispatch_frame(int sockfd, http_frame_request& frame);
        int send_frame(int sid, int opcode, const void* data, unsigned short datalen);
        int dispatch_request(int sockfd);
    private:
        NetComponent* net_component;
DECLAR(HttpComponent);

};//tolua_export

#endif
