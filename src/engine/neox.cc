#include "neox.h"

extern "C"{
    int luaopen_neox(lua_State* tolua_S);
}

int Neox::frame_rate = 100;
uint64_t Neox::delta = 0;

int Neox::main(int argc, char** argv)
{
    NodeMgr::main(argc, argv);
    //Net::init(); 
    //Script::init();
    //初始化lua
    return 0;
}

Node* Neox::create_node_remote(int nodeid)
{
    return NodeMgr::create_node_remote(nodeid);
}

GameObject* Neox::create_gameobject_local(int nodeid, const char* filepath)
{
    Node* node = NodeMgr::find_node(nodeid);
    if (!node)
    {
        return NULL;
    }
    return node->create_gameobject_local(filepath);
}

void Neox::loop()
{
    struct timeval t1;
    gettimeofday(&t1, NULL);
    struct timeval t2;
    gettimeofday(&t2, NULL);

    for (;;)
    {
        uint32_t usec_per_frame = 1000000 / frame_rate;
        gettimeofday(&t1, NULL);

        delta = (t1.tv_sec - t2.tv_sec) * 1000 + (t1.tv_usec - t2.tv_usec) / 1000;

        NodeMgr::update(delta);

        gettimeofday(&t2, NULL);

        delta = (t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec;
        //LOG_INFO("use %d sleep %d rate:%d", diff, usec_per_frame - diff, usec_per_frame);
        if (delta < usec_per_frame)
        {
            usleep(usec_per_frame - delta);
        } 
    }
}

