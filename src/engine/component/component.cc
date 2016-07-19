
#include "component.h"
#include "node/node.h"
#include "node/nodemgr.h"

IMPLEMENT(Component)

Component::Component()
{
    this->gameobject = NULL;
}

Component::~Component()
{

}

void Component::destory()
{

}

void Component::awake()
{

}

void Component::update(uint64_t cur_tick)
{

}


int Component::recv(Message* msg)
{
    return 0;
}

int Component::unreach(Message* msg)
{
    return 0;
}

void Component::set_gameobject(GameObject* object)
{
    this->gameobject = object;
}

GameObject* Component::get_gameobject()
{
    return this->gameobject;
}

int Component::create_file_event(int fd, int mask, aeFileProc* proc, void* clientData)
{
    return this->gameobject->node->create_file_event(fd, mask, proc, clientData);
}

void Component::delete_file_event(int fd, int mask)
{
    this->gameobject->node->delete_file_event(fd, mask);
}

int64_t Component::lua_getnumber(const char *fieldname)
{
    return this->gameobject->node->lua_getnumber(fieldname);
}

const char* Component::lua_getstring(const char *fieldname)
{
    return this->gameobject->node->lua_getstring(fieldname);
}

int Component::lua_pushfunction(const char *func)
{
    return this->gameobject->node->lua_pushfunction(func);
}

int Component::lua_printstack()
{
    return this->gameobject->node->lua_printstack();
} 

lua_State* Component::get_lua_state()
{
    return NodeMgr::L;
}

Node* Component::get_node()
{
    if (!gameobject)
    {
        return NULL;
    }
    return gameobject->node;
}

void Component::send_gameobject_msg(int dst_nodeid, int dst_objectid, Message* msg)
{
    gameobject->node->send_gameobject_msg(this->gameobject, dst_nodeid, dst_objectid, msg);
}


int Component::reg_msg(unsigned int id)
{
    return this->gameobject->reg_msg(id, this);
}

int Component::unreg_msg(unsigned int id)
{
    return this->gameobject->unreg_msg(id, this);
}


int Component::get_component(lua_State* L)
{
    return this->gameobject->get_component(L);
}

Component* Component::get_component(const char* name)
{
    return this->gameobject->get_component(name);
}

Message* Component::alloc_msg()
{
    return this->gameobject->node->alloc_msg();
}
