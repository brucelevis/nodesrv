#include "nodesrv.h"
#include <stdio.h>
#include <string.h>

extern "C" 
{ 
    int luaopen_gatesrv (lua_State* tolua_S); 
}


int main(int argc, char **argv)
{
    /*  
    char buf[1024];
    int count = readlink( "/proc/self/exe", buf, 1024);
    if(count < 0 || count >= 1024) 
    {
        return EXIT_FAILURE;
    }
    printf("safsfsaf\%s\n", buf);
    */
    Node* node = NodeMgr::create_node_local(1); 
    node->lua_reglib(luaopen_gatesrv);
    node->main("main.lua");
    for(;;)
    {
        sleep(1);
        NodeMgr::update(time(NULL));
    }
    return 0;
}
