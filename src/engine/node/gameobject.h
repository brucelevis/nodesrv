#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "msg/msg.h"
#include "type/type.h"
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
class Transform;

class GameObject {//tolua_export
    public:
        GameObject();//tolua_export
        virtual ~GameObject();//tolua_export
        int test();//tolua_export
        
        //创建
        virtual void create();//tolua_export
        //保存
        virtual int save();//tolua_export
        //帧函数
        virtual void update(uint64_t cur_tick);//tolua_export
        //唤醒
        virtual void awake();//tolua_export
        //销毁
        virtual void destory();//tolua_export

        //接收到消息
        virtual int recv(Message* msg);//tolua_export

        virtual int unreach(Message* msg);//tolua_export

        //组件相关
        template<class T>
        T* add_component();
        template<class T>
        int del_component();
        template<class T>
        T* get_component();

        int add_component(Component* component);//tolua_export
        ScriptComponent* add_script(const char* scriptname);//tolua_export
        int del_component(Component* component);//tolua_export
        Component* get_component(Type* type);//tolua_export
        Component* get_component(const char* name);//tolua_export
        int get_component(lua_State* L);//tolua_export
        ScriptComponent* get_script(const char* classname);//tolua_export

        //消息相关
        int reg_msg(uint32_t id, Component* component);//tolua_export
        int unreg_msg(uint32_t id, Component* component);//tolua_export
        
        //子对象相关
        GameObject* get_child(int index);//tolua_export
        int add_child(GameObject* obj);//tolua_export
        int del_child(int index);//tolua_export
        int del_child(GameObject* obj);//tolua_export
        int child_index(GameObject* obj);//tolua_export
        GameObject* get_parent();//tolua_export
        void obj_dump(int deep = 0);//tolua_export

        //保存相关
    public:
        int id;//tolua_export
        void* data;//tolua_export
        Node* node;//tolua_export
        char name[64];//tolua_export
        Transform* transform;//tolua_export
    private:
        GameObject* parent;
        std::vector<GameObject*> children;
        std::vector<Component*> comp_vector;
        std::map<uint32_t, Component*> msg_map;
        std::map<std::string, Component*> comp_map;
};//tolua_export

template<class T>T* GameObject::add_component()
{
    T* component = new T();
    add_component(component);
    return component;
}

template<class T>
T* GameObject::get_component()
{
    return get_component(T::type);
}

template<class T>
int GameObject::del_component()
{
    Component* component = get_component(T::type);
    return del_component(component);
}

#endif
