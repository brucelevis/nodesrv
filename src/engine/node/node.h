
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

class Entity;

//节点
//tolua_begin
class Node
{
    public:
        Node(int nodeid);
        virtual ~Node();
        /*
         * 入口
         */
        void main();
        /*
         * 帧函数
         */
        void update(long long cur_tick);

        /*
         * 连接
         */
        int connect(const char *host, unsigned short port);
        /*
         * 侦听
         */
        int listen(const char* host, unsigned short port);

        /*
         * 查找实体
         */
        Entity* find_entity(int entityid);

        /*
         * 插入实体
         */
        int add_entity(Entity* entity);

        /*
         * 返回节点id
         */
        int get_id();
        bool is_local();
        void set_local(bool v);
        bool is_disconnect();
        Entity* create_entity_local(const char* filepath = NULL);
        void create_entity_remote(Entity* src_entity, const char* filepath);

        Message* alloc_msg();
        void destory_msg(Message* msg);

        void recv(Message* msg);
        void recv_entity_msg(Message* msg);
        void recv_node_reg(Message* msg);
        void recv_create_entity(Message* msg);

        void send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const Buffer* buffer);
        void send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, Message* msg);
        void send_entity_msg(Entity* src_entity, Message* msg);
        void forward_entity_msg(Message* msg);
        //兼容之前的post协议
        int post(lua_State* L);
        void run_background();
    public:
        int id;
        char name[64];
//tolua_end
//
    public:
        void send_node_reg();
        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);
        void transfer_entity(Entity* src_entity); 


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
        std::map<int, Entity*> entity_map_;
        std::vector<Entity*> entity_vector_;
        bool is_local_;
        pthread_t tid_;
        aeEventLoop* loop_;
        Buffer send_buf;
        std::queue<Message*> send_msg_queue;
};//tolua_export

#endif
