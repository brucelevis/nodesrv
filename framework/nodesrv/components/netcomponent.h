
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
        int connect(int sockfd);
        int real_connect();
        int connect(const char* host, unsigned short port);
        int listen(const char* host, unsigned short port);
        int send(const char* data, size_t size);
//tolua_end
    public:
        void ev_accept(int listenfd);
        void ev_writable(int listenfd);
        void ev_readable(int listenfd);
    private:
        int dispatch(char* data, size_t datalen);
        void real_close(const char* reason);
    private:
        bool is_connect_;
        int sockfd_;
        int listenfd_;
        char ip_[64];
        unsigned short port_;

DECLAR(NetComponent);

};//tolua_export

#endif
