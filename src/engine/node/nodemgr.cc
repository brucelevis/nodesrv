#include "node/nodemgr.h"
#include "node/gameobject.h"
#include "log/log.h"
#include "script/script.h"

#include <stdio.h>



lua_State* NodeMgr::L;
aeEventLoop* NodeMgr::loop;
std::map<int, Node*> NodeMgr::node_map_;
std::vector<Node*> NodeMgr::node_vector_;
std::vector<Node*> NodeMgr::temp_node_vector_;


void NodeMgr::main(int argc, char** argv)
{
    loop = aeCreateEventLoop(10240);
    L = lua_open();
    Script::lua_openlibs(L);
    luaL_openlibs(L);

    //参数压栈
    lua_newtable(L);
    lua_setglobal(L, "arg");
    lua_getglobal(L, "arg");
    for (int i = 1; i <= argc; i++)
    {
        lua_pushnumber(L, i);
        lua_pushstring(L, argv[i - 1]);
        lua_settable(L, -3);
    }
    lua_pop(L, 1);
}

Node* NodeMgr::find_node(int nodeid)
{
    std::map<int, Node*>::iterator it;
    it = node_map_.find(nodeid);
    if (it != node_map_.end())
    {
        return it->second;
    }
    return NULL;
}

Node* NodeMgr::create_node_remote(int nodeid)
{
    if (find_node(nodeid))
    {
        return 0;
    }
    Node *node = new Node(nodeid);
    if (node)
    {
        node->set_local(false);
    }
    Log::info("nodemgr add node id(%d) addr(%lld)", node->get_id(), (long long)node);
    node_map_[node->get_id()] = node;
    node_vector_.push_back(node);
    return node;
}


Node* NodeMgr::create_node_local(int nodeid)
{
    if (find_node(nodeid))
    {
        return 0;
    }
    Node *node= new Node(nodeid);
    if (node)
    {
        node->set_local(true);
    }
    Log::info("nodemgr add node id(%d) addr(%lld)", node->get_id(), (long long)node);
    node_map_[nodeid] = node;
    node_vector_.push_back(node);
    node->main();
    return node;
}

//static int update_proc(struct aeEventLoop *eventLoop, long long id, void *clientData)
//{
//return 0;
//}

void NodeMgr::update(uint64_t cur_tick)
{
    //收消息
    aeOnce(loop);

    for (int i = node_vector_.size() - 1; i >= 0; --i)
    {
        Node* node = node_vector_[i];
        //LOG_DEBUG("node[%d] addr(%lld) update", node->get_id(), (long long)node);
        node->update(cur_tick);
    }

    //发消息 
    aeOnce(loop);
} 


Node* NodeMgr::create_temp_node()
{
    //Node *node = new Node(0);
    //if (node)
    //{
    //node->set_local(true);
    //temp_node_vector_.push_back(node);
    //}
    //return node;
    return NULL;
}

void NodeMgr::create_gameobject_remote(GameObject* src_object, int dst_nodeid, const char* filepath)
{
    Node* node = find_node(dst_nodeid);
    if (!node)
    {
        LOG_ERROR("node[%d] not found", dst_nodeid);
        return;
    }
    node->create_gameobject_remote(src_object, filepath);
}

void NodeMgr::transfer_gameobject(GameObject* src_object, int dst_nodeid)
{
    Node* node = find_node(dst_nodeid);
    if (!node)
    {
        return;
    }
    node->transfer_gameobject(src_object);
}

void NodeMgr::lua_dofile(const char* filepath)
{
    Script::lua_dofile(L, filepath);
}

void NodeMgr::lua_reglib(int (*p)(lua_State* L))
{
    Script::lua_reglib(L, p);
}
