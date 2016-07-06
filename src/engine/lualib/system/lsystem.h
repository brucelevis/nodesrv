#ifndef __SYSTEM_H__
#define __SYSTEM_H__

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}

int luaopen_system(lua_State *L);

#endif
