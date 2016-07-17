#include "datasrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(DataSrv)

extern "C" 
{ 
    int luaopen_datasrv (lua_State* tolua_S); 
}

int luamain(lua_State* L)
{
    luaopen_datasrv(L);
    return 0;
}


DataSrv::DataSrv()
{

}

DataSrv::~DataSrv()
{

}

void DataSrv::awake()
{
    Log::info("DataSrv::awake");
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        Log::error("net component is nil");
        exit(1);
        return;
    }
    net_component->listen("127.0.0.1", 9090);
}

