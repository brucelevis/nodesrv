#include "msg/rpc.h"

#include <string.h>

int RpcMessage::encode(lua_State* L)
{
    if (!lua_isstring(L, 1))
    {
        return 0;
    }
    Buffer* buffer = new Buffer();
    char* action_name = NULL;
    size_t action_name_len = 0;
    action_name =  (char*)lua_tolstring(L, 1, &action_name_len);
    buffer->write_utf8(action_name, action_name_len);

    int arg_num = lua_gettop(L) - 1;
    buffer->write_int8(arg_num);
    for (int i = 2; i <= lua_gettop(L); i++)
    {
        int type = lua_type(L, i);
        if (type == LUA_TNUMBER)
        {
            buffer->write_int8(RPC_ARG_TNUMBER);            
            buffer->write_int64((int64_t)lua_tonumber(L, i));
        } else if(type == LUA_TSTRING)
        {
            size_t str_len = 0;
            char* str = NULL;
            str = (char*)lua_tolstring(L, i, &str_len);
            buffer->write_utf8(str, str_len);
        } else if(type == LUA_TNIL)
        {
            buffer->write_int8(RPC_ARG_TNIL);            
        }
    }
    return 1;
}

int RpcMessage::decode(lua_State* L)
{
    return 0;
}
