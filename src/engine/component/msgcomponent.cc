
#include "component/msgcomponent.h"


MsgComponent::MsgComponent()
{

}

MsgComponent::~MsgComponent()
{

}

int MsgComponent::recv(Message* msg)
{
    return 0;
}


void MsgComponent::regist_msg(int id, MsgHandler handler)
{
    handler_map_[id] = handler;
}
