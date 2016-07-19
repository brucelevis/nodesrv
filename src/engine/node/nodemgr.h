
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


//tolua_begin
namespace NodeMgr
{
//tolua_end
    extern aeEventLoop* loop;
    extern lua_State* L;
    extern std::map<int, Node*> node_map_;
    extern std::vector<Node*> node_vector_;
    extern std::vector<Node*> temp_node_vector_;

    void main(int argc, char** argv);

    void lua_dofile(const char* filepath);
    void lua_reglib(int (*p)(lua_State* L));

//tolua_begin
    /*
     * 帧函数
     */
    void update(long long cur_tick);

    /*
     * 查找节点
     */
    Node* find_node(int nodeid);

    /*
     * 创建节点
     */
    Node* create_temp_node();
    Node* create_node_local(int nodeid);
    Node* create_node_remote(int nodeid);

    //将实体传输到目标节点
    void transfer_gameobject(GameObject* src_object, int dst_nodeid);

    void create_gameobject_remote(GameObject* src_object, int dst_nodeid, const char* filepath);

};
//tolua_end

#endif
