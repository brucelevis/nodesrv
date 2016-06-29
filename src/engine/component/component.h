#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <stdlib.h>

#include "msg/msg.h"
#include "entity/entity.h"
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
        virtual void destory();
        virtual void update(long long cur_tick);
        virtual int recv(Message* msg);
        virtual int recv(MsgHeader* header, const void* data, size_t datalen);
        virtual int unreach(MsgHeader* header, const void* data, size_t datalen);

        int lua_pushfunction(const char *func);
        int lua_printstack(); 
        const char* lua_getstring(const char *fieldname);
        int64_t lua_getnumber(const char *fieldname);

        Entity *get_entity();
        void set_entity(Entity* entity);
        Node* get_node();

        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);

        int reg_msg(unsigned int id);
        int unreg_msg(unsigned int id);
        void send_entity_msg(int dst_entityid, int msgid, const char* data, size_t size);
        void forward_entity_msg(int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t size);
        int get_component(lua_State* L);
        Component* get_component(const char* name);
    public:
        Entity* entity;
//tolua_end
    public:
        template<class T>
        T* get_component();
    protected:
        lua_State* get_lua_state();
    DECLAR(Component)
};//tolua_export

template<class T>
T* Component::get_component()
{
    return (T*)this->entity->get_component(T::type);
}

#endif
