#ifndef _OBJECT_MGR_H_
#define _OBJECT_MGR_H_

#include <map>

class Node;
//实体路由表
namespace ObjectMgr
{
    extern std::map<int, Node*> object_map_;

    /*
     * 中心节点
     * 中心节点是选举出来的，如果不知道实体在哪里，可以通过中心节点转发
     */
    extern Node* center_node_;

    /*
     * 查找一个可到达实体的节点
     */
    Node* find_route(int objid);

    /*
     * 根据实体id查找实体所在的节点
     */
    Node* where(int objid);

    /*
     * 更新节点
     * node         节点
     * objid 实体id
     * expire_time  过期时间 
     */
    void update_route(Node* node, int objid, int expire_time = 0);
};

#endif
