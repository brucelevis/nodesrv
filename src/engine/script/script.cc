
#include "script/script.h"
#include "lualib/pblua/pblua.h"
#include "log/llog.h"
#include "log/log.h"
#include "lualib/mysql/lmysql.h"
#include "lualib/redis/lredis.h"
#include "lualib/json/ljson.h"
#include "lualib/string/lstring.h"
#include "lualib/os/los.h"
#include "lualib/srvapp/srvapp.h"
#include "net/lsocket.h"


namespace Script
{
    extern "C"
    {
        int luaopen_neox(lua_State* tolua_S);
    }


    int lua_dofile(lua_State* L, const char* filepath)
    {
        if(luaL_dofile(L, filepath))
        {
            if (lua_isstring(L, -1))
            {
                LOG_ERROR("dofile error %s", lua_tostring(L, -1));
            }
        }
        return 0;
    }

    int64_t lua_getnumber(lua_State* L, const char *fieldname)
    {
        if(!lua_getvalue(L, fieldname))
        {
            return 0;
        }
        if(!lua_isnumber(L, -1))
        {
            lua_pop(L, 1);
            return 0;
        }
        int64_t result = (int64_t)lua_tonumber(L, -1);
        lua_pop(L, 1);
        return result;
    }

    void lua_reglib(lua_State* L, int (*p)(lua_State* L))
    {
        p(L);
    }

    const char* lua_getstring(lua_State* L, const char *fieldname)
    {
        if(!lua_getvalue(L, fieldname))
        {
            return NULL;
        }
        if(!lua_isstring(L, -1))
        {
            lua_pop(L, 1);
            return NULL;
        }
        const char* result = (const char*)lua_tostring(L, -1);
        lua_pop(L, 1);
        return result;
    }

    bool lua_getvalue(lua_State* L, const char *fieldname)
    {
        static char fieldbuf[128];
        strcpy(fieldbuf, fieldname);
        char *start = (char *)fieldbuf;
        char *class_name = start;
        char *pfunc = start;
        while(*pfunc != 0)
        {
            if(*pfunc == '.' && class_name == start)
            {
                *pfunc = 0;
                lua_getglobal(L, class_name);
                *pfunc = '.';
                if(lua_isnil(L, -1)){
                    lua_pop(L, 1);
                    return false;
                }
                class_name = pfunc + 1;
            }else if(*pfunc == '.')
            {
                *pfunc = 0;
                lua_pushstring(L, class_name);
                lua_gettable(L, -2);
                *pfunc = '.';
                if(lua_isnil(L, -1))
                {
                    lua_pop(L, 2);
                    return false;
                }
                lua_remove(L, -2);//弹出table
                class_name = pfunc + 1;
            }
            pfunc++;
        }
        if(class_name == start)
        {
            lua_getglobal(L, class_name);
            if(lua_isnil(L, -1))
            {
                lua_pop(L, 1);
                return false;
            }
            return (int64_t)lua_tonumber(L, -1);
        }else
        {
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            if(lua_isnil(L, -1))
            {
                lua_pop(L, 2);
                return false;
            }
            lua_remove(L, -2);//弹出table
        }
        return true;
    }

    int lua_pushfunction(lua_State* L, const char *func)
    {
        char *start = (char *)func;
        char *class_name = start;
        char *pfunc = start;
        while(*pfunc != 0)
        {
            if(*pfunc == '.' && class_name == start)
            {
                *pfunc = 0;
                lua_getglobal(L, class_name);
                *pfunc = '.';
                if(lua_isnil(L, -1)){
                    return 1;
                }
                class_name = pfunc + 1;
            }else if(*pfunc == '.')
            {
                *pfunc = 0;
                lua_pushstring(L, class_name);
                lua_gettable(L, -2);
                *pfunc = '.';
                if(lua_isnil(L, -1))
                {
                    return 2;
                }
                lua_remove(L, -2);//弹出table
                class_name = pfunc + 1;
            }
            pfunc++;
        }
        if(class_name == start)
        {
            lua_getglobal(L, class_name);
            if(lua_isnil(L, -1))
            {
                return 3;
            }
        }else
        {
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            if(lua_isnil(L, -1))
            {
                return 4;
            }
            lua_remove(L, -2);//弹出table
        }
        return 0;     
    }

    int lua_printstack(lua_State* L) 
    {
        lua_getglobal(L, "debug");  
        lua_getfield(L, -1, "traceback");  
        lua_pcall(L, 0, 1, 0);   
        const char* sz = lua_tostring(L, -1);  
        LOG_ERROR("%s", sz);
        return 0;
    }

    void lua_openlibs(lua_State* L)
    {
        luaopen_neox(L);
        luaopen_log(L);
        luaopen_pblua(L);
        luaopen_json(L);
        luaopen_cstring(L);
        luaopen_redis(L);
        luaopen_myos(L);
        luaopen_mysql(L);
        luaopen_srvapp(L);
        luaopen_socket(L);
    }
};


