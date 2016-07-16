
#ifndef _NODEMGR_H_
#define _NODEMGR_H_

#include "node/node.h"
#include "container/buffer.h"
#include "net/ae.h"
#include <vector>
#include <google/protobuf/message.h>
#include <map>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}


class Node;


class NodeMgr {//tolua_export
public:
    static aeEventLoop* loop;
    static lua_State* L;
    static std::map<int, Node*> node_map_;
    static std::vector<Node*> node_vector_;
    static std::vector<Node*> temp_node_vector_;

    static void main(int argc, char** argv);

    static void lua_dofile(const char* filepath);
    static void lua_reglib(int (*p)(lua_State* L));


    static void update(uint64_t cur_tick);

    /*
     * 查找节点
     */
    static Node* find_node(int nodeid);//tolua_export

    /*
     * 创建节点
     */
    static Node* create_temp_node();
    static Node* create_node_local(int nodeid);//tolua_export
    static Node* create_node_remote(int nodeid);//tolua_export

    //将实体传输到目标节点
    static void transfer_gameobject(GameObject* src_object, int dst_nodeid);

    static void create_gameobject_remote(GameObject* src_object, int dst_nodeid, const char* filepath);

};//tolua_export

#endif
