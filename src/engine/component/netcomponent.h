
#ifndef _NET_COMPONENT_H_
#define _NET_COMPONENT_H_

#include "component/component.h"


class NetComponent : public Component{//tolua_export

    public:
        NetComponent();//tolua_export
        virtual ~NetComponent();//tolua_export
    public:
        virtual void update(long long cur_tick);//tolua_export
        int listen(const char* host, unsigned short port);//tolua_export
        int send(int sockfd, const void* data, size_t size);//tolua_export
        int send_str(int sockfd, const char* data);//tolua_export
        char* alloc_send_buf(int sockfd, size_t size);//tolua_export
        void flush_send_buf(int sockfd, char* buf, size_t size);//tolua_export
        virtual void awake();//tolua_export
    public:
        char host[64];//tolua_export
        int port;//tolua_export
    public:
        typedef int (Component::*EvReadableHandler)(int sockfd, const char* data, int datalen);
        void ev_accept(int listenfd);
        void ev_writable(int listenfd);
        void ev_readable(int listenfd);
    private:
        int dispatch(int sockfd, char* data, size_t datalen);
        void real_close(int sockfd, const char* reason);
    private:
        int listenfd_;
DECLAR(NetComponent);
};//tolua_export

#endif
