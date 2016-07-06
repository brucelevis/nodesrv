
#ifndef _NET_COMPONENT_H_
#define _NET_COMPONENT_H_

#include "component/component.h"


//tolua_begin
class NetComponent : public Component
{
    public:
        NetComponent();
        virtual ~NetComponent();
    public:
        virtual void update(long long cur_tick);
        int listen(const char* host, unsigned short port);
        int send(int sockfd, const void* data, size_t size);
        int send_str(int sockfd, const char* data);
        char* alloc_send_buf(int sockfd, size_t size);
        void flush_send_buf(int sockfd, char* buf, size_t size);
//tolua_end
    public:
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
