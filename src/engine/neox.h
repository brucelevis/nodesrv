
#include "lualib/pblua/pblua.h"
#include "lualib/json/json.h"
#include "lualib/json/ljson.h"
#include "lualib/srvapp/srvapp.h"
#include "lualib/string/lstring.h"
#include "lualib/port/pb_port.h"
#include "lualib/port/rmi_port.h"
#include "lualib/port/websock_port.h"
#include "lualib/redis/lredis.h"
#include "lualib/mysql/lmysql.h"

#include "os/los.h"
#include "net/ae.h"
#include "net/lae.h"
#include "net/port.h"
#include "net/lport.h"
#include "net/lsocket.h"
#include "net/httpclient.h"
#include "msg/msg.h"
#include "date/date.h"
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

class Neox {//tolua_export
    public:
        static uint64_t delta;//tolua_export
        static int frame_rate;//tolua_export
        static int main(int argc, char** argv);//tolua_export

        static Node* create_node_remote(int nodeid);//tolua_export

        // 在本地服务器上创建实体
        static GameObject* create_gameobject_local(int nodeid, const char* filepath = "");//tolua_export

        // 主循环
        static void loop();//tolua_export

};//tolua_export
