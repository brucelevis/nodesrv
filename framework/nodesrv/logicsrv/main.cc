#include "stdafx.h"

extern "C" 
{ 
    int luaopen_logicsrv (lua_State* tolua_S); 
}


int main(int argc, char **argv)
{
    Neox::main(argc, argv);
    NodeMgr::lua_reglib(luaopen_logicsrv);
    NodeMgr::lua_dofile("srvapp.lua");
    //主循环
    Neox::loop();
    return 0;
}
