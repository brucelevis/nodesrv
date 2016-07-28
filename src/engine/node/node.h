
#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <map>
#include <vector>
#include <queue>
#include <pthread.h>
#include <google/protobuf/message.h>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}

#include "net/ae.h"
#include "msg/msg.h"
#include "container/buffer.h"

class GameObject;

//节点
class Node {//tolua_export
    public:
        Node(int nodeid);//tolua_export
        virtual ~Node();//tolua_export
        /*
         * 入口
         */
        void main();//tolua_export
        /*
         * 帧函数
         */
        void update(uint64_t cur_tick);//tolua_export

        /*
         * 连接
         */
        int connect(const char *host, unsigned short port);//tolua_export
        /*
         * 侦听
         */
        int listen(const char* host, unsigned short port);//tolua_export

        /*
         * 查找实体
         */
        GameObject* find_gameobject(int objid);//tolua_export

        /*
         * 插入实体
         */
        int add_gameobject(GameObject* object);//tolua_export

        /*
         * 返回节点id
         */
        uint32_t get_id();//tolua_export
        bool is_local();//tolua_export
        void set_local(bool v);//tolua_export
        bool is_disconnect();//tolua_export
        GameObject* create_gameobject_local(const char* filepath = NULL);//tolua_export
        void create_gameobject_remote(GameObject* src_object, const char* filepath);//tolua_export

        Message* alloc_msg();//tolua_export
        void destory_msg(Message* msg);//tolua_export
        void retain_msg(Message* msg);//tolua_export

        void recv(Message* msg);//tolua_export
        void recv_gameobject_msg(Message* msg);//tolua_export
        void recv_node_reg(Message* msg);//tolua_export
        void recv_create_gameobject(Message* msg);//tolua_export

        void send_gameobject_msg(GameObject* src_object, Message* msg);//tolua_export
        void forward_gameobject_msg(Message* msg);//tolua_export
        //兼容之前的post协议
        int post(lua_State* L);//tolua_export
        void run_background();//tolua_export

        int addtimer(lua_State *L);//tolua_export
    public:
        uint32_t id;//tolua_export
        char name[64];//tolua_export
    public:
        void send_node_reg();
        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);
        void transfer_gameobject(GameObject* src_object); 


        void ev_accept(int sockfd);
        void ev_writable(int sockfd);
        void ev_readable(int sockfd);

        int lua_printstack(); 
        int lua_pushfunction(const char *func);
        bool lua_getvalue(const char *fieldname);
        const char* lua_getstring(const char *fieldname);
        int64_t lua_getnumber(const char *fieldname);
        void lua_reglib(int (*p)(lua_State* L));
        int lua_dofile(const char* filepath);

    private:
        int dispatch(char *data, size_t datalen);
        int real_close(int sockfd, const char* err);
        int real_connect();
    public:
        lua_State* L;
    private:
        bool is_connect_;
        int sockfd_;
        int listenfd_;
        char ip_[64];
        unsigned short port_;
        std::map<int, GameObject*> gameobject_map_;
        GameObject* root_gameobject;
        bool is_local_;
        pthread_t tid_;
        aeEventLoop* loop_;
        Buffer send_buf;
        std::queue<Message*> send_msg_queue;
};//tolua_export

#endif
