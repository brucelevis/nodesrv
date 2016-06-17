#include "dbsrv.h"
#include "entity/entity.h"
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
    printf("DbSrv::awake()\n");
    /*
    NetComponent* net_component = (NetComponent*)this->entity->get_component("NetComponent");
    if (!net_component)
    {
        printf("net component is nil");
        exit(1);
        return;
    }
    net_component->listen("127.0.0.1", 9090);
    */
}
