#ifndef _GATESRV_H_
#define _GATESRV_H_

#include "component/component.h"
#include "component/netcomponent.h"
#include <map>

//tolua_begin
class GateSrv: public Component
{
    public:
        GateSrv();
        virtual ~GateSrv();
        virtual void awake();
        virtual int recv(Message* msg);
        int reply(lua_State *L);

//tolua_end
    private:
        void listen();
        int recv_new_connection(Message* msg);
        int recv_close_connection(Message* msg);
        int recv_net_raw_data(Message* msg);
        void send_msg(lua_State* L);
DECLAR(GateSrv);

    private:
        NetComponent* net_component;
};//tolua_export

#endif


