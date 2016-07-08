#include "scenesrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(SceneSrv)

SceneSrv::SceneSrv()
{

}

SceneSrv::~SceneSrv()
{

}

void SceneSrv::awake()
{
    LOG_DEBUG("SceneSrv::awake");
    this->entity->reg_msg(MSG_NEW_CONNECTION, this);
    this->entity->reg_msg(MSG_CLOSE_CONNECTION, this);
    this->entity->reg_msg(MSG_NET_RAW_DATA, this);
}

int SceneSrv::recv(Message* msg)
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

int SceneSrv::recv_close_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("recv_close_connection %d", sockfd);
    return 0;
}

int SceneSrv::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("recv_new_connection %d", sockfd);
    return 0;
}

int SceneSrv::recv_net_raw_data(Message* msg)
{
    LOG_DEBUG("recv_net_raw_data datalen(%d)", msg->datalen);
    return 0;
}


