
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

void Component::awake()
{

}

void Component::update(long long cur_tick)
{

}

int Component::recv(MsgHeader* header, const char* data, size_t datalen)
{
    return 0;
}

int Component::unreach(MsgHeader* header, const char* data, size_t datalen)
{
    return 0;
}


Entity* Component::get_entity()
{
    return this->entity;
}

void Component::set_entity(Entity* entity)
{
    this->entity = entity;
}


int Component::create_file_event(int fd, int mask, aeFileProc* proc, void* clientData)
{
    return this->entity->node->create_file_event(fd, mask, proc, clientData);
}

void Component::delete_file_event(int fd, int mask)
{
    this->entity->node->delete_file_event(fd, mask);
}


int Component::pushluafunction(const char *func)
{
    return this->entity->node->pushluafunction(func);
}

int Component::lua_printstack()
{
    return this->entity->node->lua_printstack();
} 

lua_State* Component::get_lua_state()
{
    lua_State* L = Nodeapi::L;
    return L;
}

Node* Component::get_node()
{
    if (!entity)
    {
        return 0;
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

