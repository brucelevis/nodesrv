#include "node/nodemgr.h"
#include "node/gameobject.h"
#include "log/log.h"
#include "script/script.h"

#include <stdio.h>


namespace NodeMgr
{

    lua_State* L;
    aeEventLoop* loop;
    std::map<int, Node*> node_map_;
    std::vector<Node*> node_vector_;
    std::vector<Node*> temp_node_vector_;


    void main(int argc, char** argv)
    {
        loop = aeCreateEventLoop(10240);
        L = lua_open();
        luaL_openlibs(L);
        Script::lua_openlibs(L);

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

    Node* find_node(int nodeid)
    {
        std::map<int, Node*>::iterator it;
        it = node_map_.find(nodeid);
        if (it != node_map_.end())
        {
            return it->second;
        }
        return NULL;
    }

    Node* create_node_remote(int nodeid)
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


    Node* create_node_local(int nodeid)
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

    void del_node(Node* node)
    {

    }
    
    void update(long long cur_tick)
    {
        for (;;)
        {
            usleep(1000);
            aeOnce(loop);
            for (int i = node_vector_.size() - 1; i >= 0; --i)
            {
                Node* node = node_vector_[i];
                //LOG_DEBUG("node[%d] addr(%lld) update", node->get_id(), (long long)node);
                node->update(cur_tick);
            }
        }
    }


    Node* create_temp_node()
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

    void create_gameobject_remote(GameObject* src_object, int dst_nodeid, const char* filepath)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            LOG_ERROR("node[%d] not found", dst_nodeid);
            return;
        }
        node->create_gameobject_remote(src_object, filepath);
    }

    void transfer_gameobject(GameObject* src_object, int dst_nodeid)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->transfer_gameobject(src_object);
    }

    void lua_dofile(const char* filepath)
    {
        Script::lua_dofile(L, filepath);
    }

    void lua_reglib(int (*p)(lua_State* L))
    {
        Script::lua_reglib(L, p);
    }
};
