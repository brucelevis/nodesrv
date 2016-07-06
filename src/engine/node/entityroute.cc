
#include "node/entityroute.h"
#include "node/node.h"

namespace EntityRoute
{
    std::map<int, Node*> entity_map_;

    Node* center_node_;

    Node* find_route(int entityid)
    {
        std::map<int, Node*>::iterator it;
        it = entity_map_.find(entityid);
        if (it != entity_map_.end())
        {
            Node* node = it->second;
            if (node->is_disconnect())
            {
                return center_node_;
            }
            return node;
        }
        return center_node_;
    }

    Node* where(int entityid)
    {
        std::map<int, Node*>::iterator it;
        it = entity_map_.find(entityid);
        if (it != entity_map_.end())
        {
            return it->second;
        }
        return NULL;
    }

    void update_route(Node* node, int entityid, int expire_time)
    {
        entity_map_[entityid] = node;
    }
};
