#ifndef _GATESRV_H_
#define _GATESRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class GateSrv: public Component
{
    public:
        GateSrv();
        virtual ~GateSrv();
        virtual void awake();
        virtual int recv(Message* msg);

//tolua_end
    private:
        void listen();
        int recv_new_session(Message* msg);
        int recv_close_session(Message* msg);
        int recv_net_packet(Message* msg);
DECLAR(GateSrv);

};//tolua_export

#endif


