#include "dbsrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(DbSrv)

extern "C" 
{ 
    int luaopen_dbsrv (lua_State* tolua_S); 
}

int luamain(lua_State* L)
{
    luaopen_dbsrv(L);
    return 0;
}


DbSrv::DbSrv()
{

}

DbSrv::~DbSrv()
{

}

void DbSrv::awake()
{
    Log::log("DbSrv::awake");
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        Log::error("net component is nil");
        exit(1);
        return;
    }
    net_component->listen("127.0.0.1", 9090);
}

