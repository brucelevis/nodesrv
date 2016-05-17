#ifndef __RPC_H__
#define __RPC_H__

#include <stdint.h>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}

#include "container/buffer.h"

#define RPC_ARG_TNUMBER 1
#define RPC_ARG_TNIL 2
#define RPC_ARG_TSTRING 3
//tolua_begin
class RpcMessage
{
    public:
        static int encode(lua_State* L);
        static int decode(lua_State* L);
};
//tolua_end

#endif
