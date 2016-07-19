
#include "node/objectmgr.h"
#include "node/node.h"

namespace ObjectMgr
{
    std::map<int, Node*> object_map_;

    Node* center_node_;

    Node* find_route(int objid)
    {
        std::map<int, Node*>::iterator it;
        it = object_map_.find(objid);
        if (it != object_map_.end())
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

    Node* where(int objid)
    {
        std::map<int, Node*>::iterator it;
        it = object_map_.find(objid);
        if (it != object_map_.end())
        {
            return it->second;
        }
        return NULL;
    }

    void update_route(Node* node, int objid, int expire_time)
    {
        object_map_[objid] = node;
    }
};
