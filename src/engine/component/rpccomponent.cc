
#include "component/rpccomponent.h"
#include "node/nodemgr.h"
#include "log/log.h"

#include <string.h>

#define TYPE_NIL  1
#define TYPE_INT  2
#define TYPE_STR  3

IMPLEMENT(RPCComponent)

RPCMethod& RPCMethod::operator <<(const char* val)
{
    int str_len = strlen(val);
    buffer.write_int8(TYPE_STR);
    buffer.write_int16(str_len);
    buffer.write_buf(val, str_len + 1);
    return *this;
}


RPCMethod& RPCMethod::operator <<(int val)
{
    buffer.write_int8(TYPE_INT);
    buffer.write_int32(val);
    return *this;
}

void RPCMethod::reset()
{
    buffer.reset();
}

void RPCMethod::invoke(Component* component, int dst_nodeid, int dst_entityid)
{
    if (!component)
    {
        return;
    }
    //结束
    buffer.write_int8(0);
    NodeMgr::send_entity_msg(component->entity, dst_nodeid, dst_entityid, MSG_RPC, &buffer);
}

RPCComponent::RPCComponent()
{
}

RPCComponent::~RPCComponent()
{

}

void RPCComponent::awake()
{
    LOG_DEBUG("RPCComponent::awake");
    this->entity->reg_msg(MSG_RPC, this);
}

int RPCComponent::recv_rpc(MsgHeader* header, const void* data, size_t datalen)
{
    Buffer buffer(data, datalen);
    return 0;
}

int RPCComponent::recv(MsgHeader* header, const void* data, size_t datalen)
{
    switch(header->id)
    {
        case MSG_RPC:
            {
                return recv_rpc(header, data, datalen);
            }
            break;
    }
    return 0;
}

int RPCComponent::invoke(lua_State* L)
{
    if (!lua_isnumber(L, 1) || !lua_isnumber(L, 2) ||!lua_isstring(L, 3))
    {
        return 0;
    }
    int dst_nodeid = (int)lua_tonumber(L, 1);
    int dst_entityid = (int)lua_tonumber(L, 2);
    const char* func = (const char*)lua_tostring(L, 3);

    method.reset();
    method << func;
    int arg_count = lua_gettop(L);
    for (int i = 4; i <= arg_count; i++)
    {
        if (lua_isnumber(L, i))
        {
            method << (int)lua_isnumber(L, i);
        } else if(lua_isstring(L, i))
        {
            method << (const char*)lua_isstring(L, i);
        }
    }
    method.invoke(this, dst_nodeid, dst_entityid);
    lua_pushboolean(L, 1);
    return 1;
}

