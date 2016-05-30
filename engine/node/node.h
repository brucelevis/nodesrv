
#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <map>
#include <vector>
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
        void main(const char* mainfile);
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
         * 发送消息
         */
        int send(const char* data, size_t size);

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
        Entity* create_entity_local(const char* filepath = 0);
        void create_entity_remote(Entity* src_entity, const char* filepath);

        void recv(MsgHeader* header, const char* data, size_t size);
        void recv_entity_msg(MsgHeader* header, const char* data, size_t size);
        void recv_node_reg(MsgHeader* header, const char* data, size_t size);
        void recv_create_entity(MsgHeader* header, const char* data, size_t size);

        void send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const char* data, size_t size);
        void send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, Buffer* buffer);
        void send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, ::google::protobuf::Message* msg);
        void forward_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const char* data, size_t size);
        void forward_entity_msg(MsgHeader* header, const char* data, size_t size);

//tolua_end
        void send_node_reg();
        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);
        void transfer_entity(Entity* src_entity); 

        int dofile(const char* filepath);
        int pushluafunction(const char *func);
        int lua_printstack(); 
        void ev_accept(int sockfd);
        void ev_writable(int sockfd);
        void ev_readable(int sockfd);
    public:
        lua_State* L;
    private:
        int dispatch(char *data, size_t datalen);
        int real_close(const char* err);
        int real_connect();
    private:
        bool is_connect_;
        int sockfd_;
        int listenfd_;
        char ip_[64];
        unsigned short port_;
        int id;
        char name[64];
        std::map<int, Entity*> entity_map_;
        std::vector<Entity*> entity_vector_;
        bool is_local_;
        pthread_t tid_;
        aeEventLoop* loop_;
        char mainfile[128];
};//tolua_export

#endif
