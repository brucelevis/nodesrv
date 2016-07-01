#include "log/llog.h"
#include "log/log.h"

static int lfatal(lua_State* L)
{
    const char* str = (const char*)lua_tostring(L, 1);
    Log::fatal("%s", str);
    return 0;
}
static int lerror(lua_State* L)
{
    const char* str = (const char*)lua_tostring(L, 1);
    Log::error("%s", str);
    return 0;
}
static int lwarn(lua_State* L)
{
    const char* str = (const char*)lua_tostring(L, 1);
    Log::warn("%s", str);
    return 0;
}
static int linfo(lua_State* L)
{
    const char* str = (const char*)lua_tostring(L, 1);
    Log::info("%s", str);
    return 0;
}
static int ldebug(lua_State* L)
{
    const char* str = (const char*)lua_tostring(L, 1);
    Log::debug("%s", str);
    return 0;
}

static luaL_Reg lua_lib[] = 
{
    {"fatal", lfatal},
    {"error", lerror},
    {"warn", lwarn},
    {"info", linfo},
    {"debug", ldebug},
    {NULL, NULL}
};

int luaopen_log(lua_State *L)
{
    luaL_register(L, "Log", lua_lib);
    return 1;
}

