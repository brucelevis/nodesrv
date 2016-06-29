#include "entity/entity.h"
#include "entity/entityroute.h"
#include "msg/msg.h"
#include "node/node.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "component/netcomponent.h"

#include <stdio.h>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}

namespace Nodesrv
{

    int init();

    int update(long long cur_tick);


    Node* create_node_remote(int nodeid);

    void free_node(Node* node);

    /*
     * 连接节点
     * nodeid 节点id
     */
    void connect_node(int nodeid);


    /*
     * 查询节点的连接状态
     * node     节点id
     * return   断开|链接
     */
    int node_status(int nodeid);

    /*
     * 断开节点的链接
     *
     * node     节点id
     */
    void disconnect_node(int nodeid);


    /*
     * 在本地服务器上创建实体
     *
     *
     */
    Entity* create_entity_local(int nodeid, const char* filepath = "");

    /*
     * 在远程服务器上创建实体
     * nodeid       目标节点
     * entitytype   实体类型
    */
    void create_entity_remote(int nodeid, int entityid, int entitytype);

    /*
     * 将实体注册到目标节点上
     * nodeid       节点id
     * entityid     实体id
     */
    void regist_entity_remote(int nodeid, int entityid);

    /*
     * 将节点传输到远程节点
     *
     * from_nodeid  源节点
     * to_nodeid    目标节点
     * entityid     实体id
     */
    void transfer_entity(int from_nodeid, int to_nodeid, int entityid);

    extern lua_State* L;
};
