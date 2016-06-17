
#include "component.h"
#include "entity/entity.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "nodeapi.h"

IMPLEMENT(Component)

Component::Component()
{
    this->entity = 0;
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

void Component::update(long long cur_tick)
{

}

int Component::recv(Message* msg)
{
    return 0;
}

int Component::recv(MsgHeader* header, const void* data, size_t datalen)
{
    return 0;
}

int Component::unreach(MsgHeader* header, const void* data, size_t datalen)
{
    return 0;
}

void Component::set_entity(Entity* entity)
{
    this->entity = entity;
}

Entity* Component::get_entity()
{
    return this->entity;
}

int Component::create_file_event(int fd, int mask, aeFileProc* proc, void* clientData)
{
    return this->entity->node->create_file_event(fd, mask, proc, clientData);
}

void Component::delete_file_event(int fd, int mask)
{
    this->entity->node->delete_file_event(fd, mask);
}


int Component::lua_pushfunction(const char *func)
{
    return this->entity->node->lua_pushfunction(func);
}

int Component::lua_printstack()
{
    return this->entity->node->lua_printstack();
} 

lua_State* Component::get_lua_state()
{
    return this->entity->node->L;
}

Node* Component::get_node()
{
    if (!entity)
    {
        return NULL;
    }
    return entity->node;
}

void Component::send_entity_msg(int dst_entityid, int msgid, const char* data, size_t size)
{
    Node* node = get_node();    
    node->send_entity_msg(this->entity, dst_entityid, msgid, data, size);
}


void Component::forward_entity_msg(int dst_nodeid, int dst_entityid, int msgid, const char* data, size_t size)
{
    NodeMgr::forward_entity_msg(this->entity, dst_nodeid, dst_entityid, msgid, data, size);
}

int Component::reg_msg(unsigned int id)
{
    return this->entity->reg_msg(id, this);
}

int Component::unreg_msg(unsigned int id)
{
    return this->entity->unreg_msg(id, this);
}

int Component::get_component(lua_State* L)
{
    return this->entity->get_component(L);
}

