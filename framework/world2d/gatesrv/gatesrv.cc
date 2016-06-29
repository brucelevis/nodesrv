#include "gatesrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(GateSrv)

GateSrv::GateSrv()
{

}

GateSrv::~GateSrv()
{

}

void GateSrv::awake()
{
    Log::log("GateSrv::awake");
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        Log::error("net component is nil");
        exit(1);
        return;
    }
    const char* ip = lua_getstring("Config.ip");
    uint16_t port = lua_getnumber("Config.port");
    net_component->listen(ip, port);
}
