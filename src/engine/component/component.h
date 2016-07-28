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

class Component {//tolua_export
    public:
        Component();//tolua_export
        virtual ~Component();//tolua_export
        virtual void awake();//tolua_export
        virtual void destory();//tolua_export
        virtual void update(uint64_t cur_tick);//tolua_export
        virtual int recv(Message* msg);//tolua_export
        virtual int unreach(Message* msg);//tolua_export

        int lua_pushfunction(const char *func);
        int lua_printstack(); 
        const char* lua_getstring(const char *fieldname);
        int64_t lua_getnumber(const char *fieldname);

        GameObject *get_gameobject();
        void set_gameobject(GameObject* object);
        Node* get_node();

        int create_file_event(int fd, int mask, aeFileProc* proc, void* clientData);
        void delete_file_event(int fd, int mask);

        int reg_msg(unsigned int id);//tolua_export
        int unreg_msg(unsigned int id);//tolua_export
        void send_gameobject_msg(int dst_nodeid, int dst_objectid, Message* msg);
        void send_gameobject_msg(int dst_nodeid, int dst_objectid, int msgid, const Buffer* buffer);
        int get_component(lua_State* L);
        Message* alloc_msg();
        void destory_msg(Message* msg);
        Component* get_component(const char* name);//tolua_export

    public:
        GameObject* gameobject;//tolua_export
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
