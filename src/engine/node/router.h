#ifndef _ROUTER_H_
#define _ROUTER_H_

#include <map>

class Node;
//实体路由表
class Router {//tolua_export

public:
    /*
     * 中心节点
     * 中心节点是选举出来的，如果不知道实体在哪里，可以通过中心节点转发
     */
    static Node* center_node;//tolua_export
    static std::map<int, Node*> object_map;


    /*
     * 查找一个可到达实体的节点
     */
    static Node* find_route(int objid);

    /*
     * 根据实体id查找实体所在的节点
     */
    static Node* where(int objid);

    /*
     * 更新节点
     * node         节点
     * objid 实体id
     * expire_time  过期时间 
     */
    static void update_route(Node* node, int objid, int expire_time = 0);
};//tolua_export

#endif
