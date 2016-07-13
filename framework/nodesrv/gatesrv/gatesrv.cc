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


void GateSrv::listen()
{
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        LOG_ERROR("net component is nil");
        exit(1);
        return;
    }
}

void GateSrv::awake()
{
    LOG_DEBUG("GateSrv::awake");
    //this->entity->reg_msg(MSG_NEW_SESSION, this);
    //this->entity->reg_msg(MSG_CLOSE_SESSION, this);
    //this->entity->reg_msg(MSG_NET_PACKET, this);
}

int GateSrv::recv(Message* msg)
{
    switch(msg->header.id)
    {
        case MSG_NEW_SESSION:
            {
                return recv_new_session(msg);
            }
            break;
        case MSG_CLOSE_SESSION:
            {
                return recv_close_session(msg);
            }
            break;
        case MSG_NET_PACKET:
            {
                return recv_net_packet(msg);
            }
            break;
    }
    return 0;
}

int GateSrv::recv_net_packet(Message* msg)
{
    LOG_DEBUG("recv_net_packet payload(%d)", msg->payload.size());
    return 0;
}

int GateSrv::recv_close_session(Message* msg)
{
    int sockfd = msg->sockfd;
    int sid = msg->sid;
    LOG_DEBUG("recv_close_session sockfd(%d) sid(%d)", sockfd, sid);
    return 0;
}

int GateSrv::recv_new_session(Message* msg)
{
    int sockfd = msg->sockfd;
    int sid = msg->sid;
    LOG_DEBUG("recv_new_session sockfd(%d) sid(%d)", sockfd, sid);
    return 0;
}



