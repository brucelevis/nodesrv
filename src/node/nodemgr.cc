#include "node/nodemgr.h"
#include "entity/entity.h"

#include <stdio.h>


namespace NodeMgr
{

    std::map<int, Node*> node_map_;
    std::vector<Node*> node_vector_;
    std::vector<Node*> temp_node_vector_;

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
        //if (find_node(nodeid))
        //{
            //return 0;
        //}
        //Node *node = new Node(nodeid);
        //if (node)
        //{
            //node->set_local(false);
        //}
        //printf("nodemgr add node id(%d) addr(%lld)\n", node->get_id(), (long long)node);
        //node_map_[node->get_id()] = node;
        //node_vector_.push_back(node);
        //node->create();
        //return node;
        return NULL;
    }


    Node* create_node_local(int nodeid, const char* mainfile)
    {
        if (find_node(nodeid))
        {
            return 0;
        }
        Node *node = new Node(nodeid);
        if (node)
        {
            node->set_local(true);
        }
        printf("nodemgr add node id(%d) addr(%lld)\n", node->get_id(), (long long)node);
        node_map_[nodeid] = node;
        node_vector_.push_back(node);
        node->main(mainfile);
        return node;
    }

    void del_node(Node* node)
    {

    }
    
    void update(long long cur_tick)
    {
        for (int i = node_vector_.size() - 1; i >= 0; --i)
        {
            Node* node = node_vector_[i];
//            printf("node[%d] addr(%lld) update\n", node->get_id(), (long long)node);
            node->update(cur_tick);
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

    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t len)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->send_entity_msg(src_entity, dst_entityid, msgid, data, len);
    }

    void forward_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t len)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->forward_entity_msg(src_entity, dst_entityid, msgid, data, len);
    }

    void create_entity_remote(Entity* src_entity, int dst_nodeid, const char* filepath)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            printf("node[%d] not found\n", dst_nodeid);
            return;
        }
        node->create_entity_remote(src_entity, filepath);
    }

    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, ::google::protobuf::Message* msg)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->send_entity_msg(src_entity, dst_entityid, msgid, msg);
    }

    void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, int msgid, Buffer* buffer)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->send_entity_msg(src_entity, dst_entityid, msgid, buffer);
    }

    void transfer_entity(Entity* src_entity, int dst_nodeid)
    {
        Node* node = find_node(dst_nodeid);
        if (!node)
        {
            return;
        }
        node->transfer_entity(src_entity);
    }
};
