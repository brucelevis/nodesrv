#ifndef _GATESRV_H_
#define _GATESRV_H_

#include "component/component.h"
#include "component/netcomponent.h"
#include <map>

//tolua_begin
class Client: public Component
{
    public:
        Client();
        virtual ~Client();
        virtual void awake();
        static int recv(lua_State* L);
        static int send(lua_State *L);
//tolua_end
    private:
DECLAR(Client);

    private:
        NetComponent* net_component;
};//tolua_export

#endif


