
#include "component.h"
#include "log/log.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "node/router.h"

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
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return 0;
    }
    return this->gameobject->node->create_file_event(fd, mask, proc, clientData);
}

void Component::delete_file_event(int fd, int mask)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return;
    }
    this->gameobject->node->delete_file_event(fd, mask);
}

int64_t Component::lua_getnumber(const char *fieldname)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return 0;
    }
    return this->gameobject->node->lua_getnumber(fieldname);
}

const char* Component::lua_getstring(const char *fieldname)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return "";
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return "";
    }
    return this->gameobject->node->lua_getstring(fieldname);
}

int Component::lua_pushfunction(const char *func)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return 0;
    }
    return this->gameobject->node->lua_pushfunction(func);
}

int Component::lua_printstack()
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return 0;
    }
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

void Component::send_gameobject_msg(int dst_nodeid, int dst_objectid, int msgid, const Buffer* buffer)
{
    Message* msg = alloc_msg();
    MessageHeader& header = msg->header;
    header.id = msgid;

    msg->payload.reset();
    msg->payload.write(buffer);

    send_gameobject_msg(dst_nodeid, dst_objectid, msg);

    destory_msg(msg);
}

void Component::send_gameobject_msg(int dst_nodeid, int dst_objectid, Message* msg)
{
    GameObject* src_object = this->gameobject;
    if(!src_object)
    {
        LOG_ERROR("src_object not found");
        return;
    }
    Node* src_node = src_object->node;
    if (!src_node)
    {
        LOG_ERROR("src_node not found");
        return;
    }
    Node* node = NodeMgr::find_node(dst_nodeid);
    if (!node)
    {
        //转发到中心节点
        Node* center_node = Router::center_node;
        if (center_node != src_node)
        {
            node = center_node;
        }
    }
    if (!node)
    {
        LOG_ERROR("dst_node(%d) not found", dst_nodeid);
        return;
    }
    msg->header.src_objectid = src_object->id;
    msg->header.src_nodeid = src_node->id;
    msg->header.dst_nodeid = dst_nodeid;
    msg->header.dst_objectid = dst_objectid;
    node->send_gameobject_msg(src_object, msg);
}


int Component::reg_msg(unsigned int id)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    return this->gameobject->reg_msg(id, this);
}

int Component::unreg_msg(unsigned int id)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    return this->gameobject->unreg_msg(id, this);
}


int Component::get_component(lua_State* L)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return 0;
    }
    return this->gameobject->get_component(L);
}

Component* Component::get_component(const char* name)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return NULL;
    }
    return this->gameobject->get_component(name);
}

Message* Component::alloc_msg()
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return NULL;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return NULL;
    }
    return this->gameobject->node->alloc_msg();
}


void Component::destory_msg(Message* msg)
{
    if (!this->gameobject)
    {
        LOG_ERROR("no gameobject");
        return;
    }
    if (!this->gameobject->node)
    {
        LOG_ERROR("no node");
        return;
    }
    this->gameobject->node->destory_msg(msg);
}
