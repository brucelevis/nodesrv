
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
        int send(int sockfd, const char* data, size_t size);
        int send_str(int sockfd, const char* data);
//tolua_end
    public:
        void ev_accept(int listenfd);
        void ev_writable(int listenfd);
        void ev_readable(int listenfd);
    private:
        int dispatch(char* data, size_t datalen);
        void real_close(int sockfd, const char* reason);
    private:
        int listenfd_;
DECLAR(NetComponent);
};//tolua_export

#endif
