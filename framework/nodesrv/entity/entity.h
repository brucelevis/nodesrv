#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "msg/msg.h"

#include <stdlib.h> 
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}

class Node;
class Component;
class ScriptComponent;

//tolua_begin
class Entity
{
    public:
        Entity();
        virtual ~Entity();
        int test();
        
        //虚函数
        virtual void create();
        virtual int save();
        virtual void update(long long cur_tick);
        virtual void awake();

        virtual int recv(Message* msg);
        virtual int recv(MsgHeader* header, const void* data, size_t datalen);
        virtual int unreach(MsgHeader* header, const void* data, size_t datalen);

        //组件相关
        int add_component(Component* component);
        ScriptComponent* add_script(const char* scriptname);
        int del_component(Component* component);
        Component* get_component(const char* name);
        int get_component(lua_State* L);
        ScriptComponent* get_script(const char* classname);

        //消息相关
        int reg_msg(unsigned int id, Component* component);
        int unreg_msg(unsigned int id, Component* component);
        
        //子对象相关
        Entity* get_child(int index);
        int add_child(Entity* entity);
        int del_child(int index);
        int del_child(Entity* entity);
        int indexof(Entity* entity);
        Entity* get_parent();

    public:
        int id;
        void* data;
        Node* node;
        char name[64];

//tolua_end
    private:
        Entity* parent;
        std::vector<Entity*> children;
        std::vector<Component*> component_vector;
        std::map<unsigned int, Component*> msg_map;
        std::map<std::string, Component*> component_map;
};//tolua_export

#endif
