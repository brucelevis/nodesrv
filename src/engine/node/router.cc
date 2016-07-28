
#include "node/router.h"
#include "node/node.h"

std::map<int, Node*> Router::object_map;

Node* Router::center_node;

Node* Router::find_route(int objid)
{
    std::map<int, Node*>::iterator it;
    it = object_map.find(objid);
    if (it != object_map.end())
    {
        Node* node = it->second;
        if (node->is_disconnect())
        {
            return center_node;
        }
        return node;
    }
    return center_node;
}

Node* Router::where(int objid)
{
    std::map<int, Node*>::iterator it;
    it = object_map.find(objid);
    if (it != object_map.end())
    {
        return it->second;
    }
    return NULL;
}

void Router::update_route(Node* node, int objid, int expire_time)
{
    object_map[objid] = node;
}
