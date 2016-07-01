#include "stdafx.h"

extern "C" 
{ 
    int luaopen_gatesrv (lua_State* tolua_S); 
}


int main(int argc, char **argv)
{
    //切换工作路径
    const char* self_dir = File::dirname(argv[0]);
    File::chdir(self_dir);
    Log::info("running dir is %s", File::getcwd());

    //守护进程
    Neox::fork_daemon();

    //创建主节点
    Node* node = NodeMgr::create_node_local(1); 
    node->lua_reglib(luaopen_gatesrv);
    node->main("main.lua");

    //主循环
    Neox::loop();
    return 0;
}
