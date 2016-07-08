
#ifndef __SCRIPT_H__
#define __SCRIPT_H__

#include <unistd.h>
#include <stdint.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}


namespace Script
{
    int lua_dofile(lua_State* L, const char* filepath);
    bool lua_getvalue(lua_State* L, const char *fieldname);
    int64_t lua_getnumber(lua_State* L, const char *fieldname);
    const char* lua_getstring(lua_State* L, const char *fieldname);
    void lua_reglib(lua_State* L, int (*p)(lua_State* L));
    int lua_pushfunction(lua_State* L, const char *func);
    int lua_printstack(lua_State* L); 
    void lua_openlibs(lua_State* L);
};

#endif
