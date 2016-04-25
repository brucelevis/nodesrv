
#include "nodeapi.h"

#include <stdio.h>
#include <string.h>

extern "C" 
{ 
    int luaopen_gatesrv (lua_State* tolua_S); 
}

int luaopen_mylibs()
{
    lua_State* L = Nodeapi::L;
    luaopen_gatesrv(L);
    return 0;
}

int main(int argc, char **argv)
{

    Nodeapi::init();

    luaopen_mylibs();
     
    printf("create node local 1\n");
    NodeMgr::create_node_local(1, "main.lua");
    
    for(;;)
    {
        sleep(1);
        NodeMgr::update(time(NULL));
    }

    return 0;
}

