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
}

