
#include "entity.h"

#include "component/component.h"
#include "components/scriptcomponent.h"


#include <string.h>

Entity::Entity()
{
    this->data = 0;
    this->node = 0;
    this->id = 0;
}

Entity::~Entity()
{

}

void Entity::create()
{

}

int Entity::unreach(MsgHeader* header, const void* data, size_t datalen)
{
    printf("entity[%d] recv datalen(%ld)\n", id, datalen);
    std::map<unsigned int, Component*>::iterator it;
    it = msg_map.find(header->id);
    if (it != msg_map.end())
    {
        Component* component = it->second;
        component->unreach(header, data, datalen);
    }
    return 0;
}


int Entity::recv(MsgHeader* header, const void* data, size_t datalen)
{
    printf("entity[%d] recv datalen(%ld)\n", id, datalen);
    std::map<unsigned int, Component*>::iterator it;
    it = msg_map.find(header->id);
    if (it != msg_map.end())
    {
        Component* component = it->second;
        return component->recv(header, data, datalen);
    }
    //for (int i = component_vector.size() - 1; i >= 0; i--)
    //{
        //Component* component = component_vector[i];
        //int ir = component->recv(header, data, datalen);
        //if (ir > 0)
        //{
            //break;
        //}
    //}
    return 0;
}

int Entity::save()
{
    return 0;
}


ScriptComponent* Entity::add_script(const char* scriptname)
{
    printf("entity[%d] add script %s\n", this->id, scriptname);
    ScriptComponent* component = new ScriptComponent(scriptname);
    component_vector.push_back(component);
    component->set_entity(this);
    return component;
}

int Entity::add_component(Component* component)
{
    printf("entity[%d] add component %s\n", this->id, component->get_type()->name);
    component_vector.push_back(component);
    component->set_entity(this);
    return 0;
}

int Entity::del_component(Component* component)
{
    for (int i = component_vector.size() - 1; i >= 0; i--)
    {
        if (component_vector[i] == component)
        {
            //交换，再删除
            component_vector[i] = component_vector[component_vector.size() - 1];
            component_vector.pop_back();
            break;
        }
    }
    return 0;
}

void Entity::update(long long cur_tick)
{
//    printf("entity[%d] update\n", this->id);
    for (int i = component_vector.size() - 1; i >= 0; i--)
    {
        Component* component = component_vector[i];
        component->update(cur_tick);
    }
}

int Entity::reg_msg(unsigned int id, Component* component)
{
    msg_map[id] = component;
    return 0;
}

int Entity::unreg_msg(unsigned int id, Component* component)
{
    std::map<unsigned int, Component*>::iterator it;
    it = msg_map.find(id);
    if (it != msg_map.end())
    {
        msg_map.erase(it);
    }
    return 0;
}


int Entity::test()
{
    printf("entity[%d] test\n", this->id);
    return 0;
}

Entity* Entity::get_child(int index)
{
    if (index < 0 || index >= (int)children.size())
    {
        return NULL;
    }
    return children[index];
}

int Entity::add_child(Entity* entity)
{
    children.push_back(entity);
    entity->parent = this;
    return children.size() - 1;
}

Entity* Entity::get_parent()
{
    return this->parent;
}

int Entity::indexof(Entity* entity)
{
    for(int i = 0; i < (int)children.size(); i++)
    {
        if (children[i] == entity)
        {
            return i;
        }
    }
    return -1;
}

int Entity::del_child(Entity* entity)
{
    for(int i = 0; i < (int)children.size(); i++)
    {
        if (children[i] == entity)
        {
            children[i] = children[children.size() - 1];
            children.pop_back();
            return i;
        }
    }
    return -1;
}



int Entity::del_child(int index)
{
    if (index < 0 || index >= (int)children.size())
    {
        return 1;
    }
    children[index] = children[children.size() - 1];
    children.pop_back();
    return 0; 
}

Component* Entity::get_component(int index)
{
    if (index < 0 || index >= (int)component_vector.size())
    {
        return NULL;
    }
    return component_vector[index];
}

Component* Entity::get_component(const char* name)
{
    for (int i = 0; i < (int)component_vector.size(); i++)
    {
        Component* component = component_vector[i];
        if(!strcmp(component->get_type()->name, name))
        {
            return component;
        }
    }
    return NULL;
}

int Entity::get_component(lua_State* L)
{
    const char* classname = ((const char*)  tolua_tostring(L, 2, 0));
    for (size_t i = 0; i < component_vector.size(); i++)
    {
        Component* component = component_vector[i];
        if(!strcmp(component->get_type()->name, classname))
        {
            tolua_pushusertype(L, (void*)component, classname);
            return 1;
        }
    }
    lua_pushnil(L);
    return 1;
}

ScriptComponent* Entity::get_script(const char* classname)
{
    for (int i = 0; i < (int)component_vector.size(); i++)
    {
        Component* component = component_vector[i];
        if(component->get_type() == ScriptComponent::type && !strcmp(((ScriptComponent*)component)->modname, classname))
        {
            return (ScriptComponent*)component;
        }
    }
    return NULL;
}


void Entity::awake()
{
    for (int i = 0; i < (int)component_vector.size(); i++)
    {
        Component* component = component_vector[i];
        component->awake();
    }
}
