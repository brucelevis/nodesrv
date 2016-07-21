#include "stdafx.h"

extern "C" 
{ 
    int luaopen_client (lua_State* tolua_S); 
}


int main(int argc, char **argv)
{
    Neox::main(argc, argv);
    NodeMgr::lua_reglib(luaopen_client);
    NodeMgr::lua_dofile("client.lua");
    //主循环
    Neox::loop();
    return 0;
}
