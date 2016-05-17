
#ifndef _NODEMGR_H_
#define _NODEMGR_H_

#include "node/node.h"
#include "container/buffer.h"
#include <vector>
#include <google/protobuf/message.h>
#include <map>

class Node;


//tolua_begin
namespace NodeMgr
{
//tolua_end
    extern std::map<int, Node*> node_map_;
    extern std::vector<Node*> node_vector_;
    extern std::vector<Node*> temp_node_vector_;

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
    Node* create_node_local(int nodeid, const char* mainfile);
    Node* create_node_remote(int nodeid);

    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, ::google::protobuf::Message* msg);
    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, Buffer* buffer);
    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t size);
    void forward_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t len);
    void send_create_entity(Entity* src_entity, int dst_nodeid, const char* filepath);
};
//tolua_end

#endif
