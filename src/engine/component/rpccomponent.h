
#ifndef _RPC_COMPONENT_H_
#define _RPC_COMPONENT_H_

#include "component/component.h"
#include "container/buffer.h"
#include <google/protobuf/message.h>
#include <google/protobuf/dynamic_message.h>



class RPCComponent;
/*
 * 兼容之前的代码
 * RPCComponent是与实体无关的, RPCComponent约定好挂在实体0上
 *
 * RPCMethod method;
 * method << "Login.PLAYER_EXIT" << uid;
 * method.invoke(this, nodeid, entityid);
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
        RPCMethod& operator <<(::google::protobuf::Message* msg);
};

//tolua_begin
class RPCComponent : public Component
{
    public:
        RPCComponent();
        ~RPCComponent();
//tolua_end
        //self:invoke(dst_nodeid, dst_entityid, 'Login.PLAYER_ENTER', 1, 2)
        int post(lua_State* L);
        void awake();
        int recv(Message* msg);
        int recv_rpc(Message* msg);
DECLAR(RPCComponent);
    public:
        RPCMethod method;
};//tolua_export


#endif
