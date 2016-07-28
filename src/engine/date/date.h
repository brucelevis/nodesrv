#ifndef __DATE_H__
#define __DATE_H__

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}

class Date { //tolua_export
    public:

        static int msectime(lua_State *L);//tolua_export

        static int gettimeofday(lua_State *L);//tolua_export

        static int issameday(lua_State *L);//tolua_export

        static int issamemonth(lua_State *L);//tolua_export

        static int issameweek(lua_State *L);//tolua_export

        static int strftime(lua_State *L);//tolua_export

        static int time(lua_State *L);//tolua_export
};//tolua_export

#endif
