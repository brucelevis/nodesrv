#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "msg/msg.h"
#include "container/buffer.h"

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
        virtual void update(uint64_t cur_tick);
        virtual void awake();
        virtual void destory();

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
        int reg_msg(uint32_t id, Component* component);
        int unreg_msg(uint32_t id, Component* component);
        
        //子对象相关
        Entity* get_child(int index);
        int add_child(Entity* entity);
        int del_child(int index);
        int del_child(Entity* entity);
        int child_index(Entity* entity);
        Entity* get_parent();

        //保存相关
    public:
        int id;
        void* data;
        Node* node;
        char name[64];
//tolua_end
    private:
        Entity* parent;
        std::vector<Entity*> children;
        std::vector<Component*> comp_vector;
        std::map<uint32_t, Component*> msg_map;
        std::map<std::string, Component*> comp_map;
};//tolua_export

#endif
