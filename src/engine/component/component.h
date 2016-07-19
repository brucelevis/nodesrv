#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <stdlib.h>

#include "msg/msg.h"
#include "node/gameobject.h"
#include "type/type.h"
#include "net/ae.h"

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


class GameObject;
class Node;

//tolua_begin
class Component
{
    public:
        Component();
        virtual ~Component();
        virtual void awake();
        virtual void destory();
        virtual void update(uint64_t cur_tick);
        virtual int recv(Message* msg);
        virtual int unreach(Message* msg);

        int lua_pushfunction(const char *func);
        int lua_printstack(); 
        const char* lua_getstring(const char *fieldname);
        int64_t lua_getnumber(const char *fieldname);

        GameObject *get_gameobject();
        void set_gameobject(GameObject* object);
        Node* get_node();

        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);

        int reg_msg(unsigned int id);
        int unreg_msg(unsigned int id);
        void send_gameobject_msg(int dst_nodeid, int dst_objectid, Message* msg);
        int get_component(lua_State* L);
        Message* alloc_msg();
        Component* get_component(const char* name);
    public:
        GameObject* gameobject;
//tolua_end
    public:
        template<class T>
        T* get_component();
    protected:
        lua_State* get_lua_state();
    DECLAR(Component)
};//tolua_export

template<class T>T* Component::get_component()
{
    return (T*)this->gameobject->get_component(T::type);
}

#endif
