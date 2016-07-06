
#include "lualib/pblua/pblua.h"
#include "lualib/json/json.h"
#include "lualib/json/ljson.h"
#include "lualib/srvapp/srvapp.h"
#include "lualib/system/lsystem.h"
#include "lualib/string/lstring.h"
#include "lualib/port/pb_port.h"
#include "lualib/port/rmi_port.h"
#include "lualib/port/websock_port.h"
#include "lualib/redis/lredis.h"
#include "lualib/mysql/lmysql.h"

#include "net/ae.h"
#include "net/lae.h"
#include "net/port.h"
#include "net/lport.h"
#include "msg/msg.h"
#include "node/entity.h"
#include "node/entityroute.h"
#include "node/node.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "log/llog.h"
#include "log/logger.h"
#include "log/filelogger.h"
#include "file/file.h"
#include "script/script.h"
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

    // 在本地服务器上创建实体
    Entity* create_entity_local(int nodeid, const char* filepath = "");

    // 守护进程模型
    void fork_daemon();

    // 主循环
    void loop();
//tolua_end

    void lua_openlibs(lua_State* L);

//tolua_begin
};
//tolua_end
