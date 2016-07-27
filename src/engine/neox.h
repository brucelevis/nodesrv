
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
#include "net/lsocket.h"
#include "net/httpclient.h"
#include "msg/msg.h"
#include "node/gameobject.h"
#include "node/router.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "log/llog.h"
#include "log/logger.h"
#include "log/filelogger.h"
#include "file/file.h"
#include "script/script.h"
#include "component/netcomponent.h"
#include "component/postcomponent.h"
#include "display/transform.h"

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
    int main(int argc, char** argv);

    Node* create_node_remote(int nodeid);

    // 在本地服务器上创建实体
    GameObject* create_gameobject_local(int nodeid, const char* filepath = "");

    // 守护进程模型
    void fork_daemon();

    // 主循环
    void loop();
//tolua_end

    extern int frame_rate;
    int lua_openlibs(lua_State* L);
    void lua_dofile(const char* filepath);
//tolua_begin
};
//tolua_end
