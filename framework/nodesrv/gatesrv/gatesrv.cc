#include "gatesrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(GateSrv)

GateSrv::GateSrv()
{

}

GateSrv::~GateSrv()
{

}

void GateSrv::awake()
{
    LOG_DEBUG("GateSrv::awake");
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        LOG_ERROR("net component is nil");
        exit(1);
        return;
    }
    const char* ip = lua_getstring("Config.ip");
    uint16_t port = lua_getnumber("Config.port");
    if(net_component->listen(ip, port))
    {
        LOG_ERROR("listen error");
        exit(1);
        return;
    }

    this->entity->reg_msg(MSG_NEW_CONNECTION, this);
    this->entity->reg_msg(MSG_CLOSE_CONNECTION, this);
    this->entity->reg_msg(MSG_NET_RAW_DATA, this);
}

int GateSrv::recv(Message* msg)
{
    switch(msg->id)
    {
        case MSG_NEW_CONNECTION:
            {
                return recv_new_connection(msg);
            }
            break;
        case MSG_CLOSE_CONNECTION:
            {
                return recv_close_connection(msg);
            }
            break;
        case MSG_NET_RAW_DATA:
            {
                return recv_net_raw_data(msg);
            }
            break;
    }
    return 0;
}

int GateSrv::recv_close_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("recv_close_connection %d", sockfd);
    return 0;
}

int GateSrv::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("recv_new_connection %d", sockfd);
    return 0;
}

int GateSrv::recv_net_raw_data(Message* msg)
{
    LOG_DEBUG("recv_net_raw_data datalen(%d)", msg->datalen);
    return 0;
}


