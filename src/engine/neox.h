#include "entity/entity.h"
#include "entity/entityroute.h"
#include "msg/msg.h"
#include "node/node.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "log/llog.h"
#include "log/logger.h"
#include "log/filelogger.h"
#include "file/file.h"
#include "script/script.h"
#include "json/json.h"
#include "json/ljson.h"
#include "component/netcomponent.h"

#include <stdio.h>
#include <signal.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}

//tolua_begin
namespace Neox
{

    int init();

    int update(long long cur_tick);


    Node* create_node_remote(int nodeid);

    /*
     * 在本地服务器上创建实体
     *
     *
     */
    Entity* create_entity_local(int nodeid, const char* filepath = "");

    // 守护进程模型
    void fork_daemon();

    // 主循环
    void loop();
};
//tolua_end
