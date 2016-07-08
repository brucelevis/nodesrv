
#ifndef _RPC_COMPONENT_H_
#define _RPC_COMPONENT_H_

#include "component/component.h"
#include "container/buffer.h"


class RPCComponent;
/*
 * RPCMethod method;
 * method << "Login.PLAYER_EXIT" << uid;
 * method.invoke();
 */

class RPCMethod
{
    public:
        struct Option
        {
        };
    public:
        Option option;
        Buffer buffer;
    public:
        void reset();
        void invoke(Component* component, int dst_nodeid, int dst_entityid);
        RPCMethod& operator <<(int val);
        RPCMethod& operator <<(const char* val);
};

//tolua_begin
class RPCComponent : public Component
{
    public:
        RPCComponent();
        ~RPCComponent();
//tolua_end
        //self:invoke(dst_nodeid, dst_entityid, 'Login.PLAYER_ENTER', 1, 2)
        int invoke(lua_State* L);
        void awake();
        int recv(MsgHeader* header, const void* data, size_t datalen);
        int recv_rpc(MsgHeader* header, const void* data, size_t datalen);
DECLAR(RPCComponent);
    public:
        RPCMethod method;
};//tolua_export


#endif
