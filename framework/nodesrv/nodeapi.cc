#include "nodeapi.h"

extern "C"{
    int luaopen_nodeapi (lua_State* tolua_S);
}

namespace Nodeapi
{

    lua_State* L;
    int init()
    {
        //Net::init(); 
        //Script::init();
        //初始化lua
        L = lua_open();
        luaL_openlibs(L);
        luaopen_nodeapi(L);
        return 0;
    }

    Node* create_node_remote(int nodeid)
    {
        return NodeMgr::create_node_remote(nodeid);
    }

    Entity* create_entity_local(int nodeid, const char* filepath)
    {
        Node* node = NodeMgr::find_node(nodeid);
        if (!node)
        {
            return NULL;
        }
        return node->create_entity_local(filepath);
    }

    
    int update(long long cur_tick)
    {
        NodeMgr::update(cur_tick);
        return 0;
    }
};
