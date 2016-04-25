#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <stdlib.h>

#include "msg/msg.h"
#include "type/type.h"
#include "net/ae.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


class Entity;
class Node;

//tolua_begin
class Component
{
    public:
        Component();
        virtual ~Component();
        virtual void awake();
        virtual void update(long long cur_tick);
        virtual int recv(MsgHeader* header, const char* data, size_t datalen);
        virtual int unreach(MsgHeader* header, const char* data, size_t datalen);
        int pushluafunction(const char *func);
        int lua_printstack(); 
        Entity *get_entity();
        void set_entity(Entity* entity);
        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);
        Node* get_node();

        void send_entity_msg(int dst_entityid, int msgid, const char* data, size_t size);
        void forward_entity_msg(int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t size);
//tolua_end

    public:
        Entity* entity;
    protected:
        lua_State* get_lua_state();
    DECLAR(Component)
};//tolua_export


#endif
