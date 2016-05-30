#ifndef _ENTITY_ROUTE_H_
#define _ENTITY_ROUTE_H_

#include <map>

class Node;
//实体路由表
namespace EntityRoute
{
    extern std::map<int, Node*> entity_map_;

    /*
     * 中心节点
     * 中心节点是选举出来的，如果不知道实体在哪里，可以通过中心节点转发
     */
    extern Node* center_node_;

    /*
     * 查找一个可到达实体的节点
     */
    Node* find_route(int entityid);

    /*
     * 根据实体id查找实体所在的节点
     */
    Node* where(int entityid);

    /*
     * 更新节点
     * node         节点
     * entityid     实体id
     * expire_time  过期时间 
     */
    void update_route(Node* node, int entityid, int expire_time = 0);
};

#endif
