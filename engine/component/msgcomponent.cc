
#include "component/msgcomponent.h"


MsgComponent::MsgComponent()
{

}

MsgComponent::~MsgComponent()
{

}

int MsgComponent::recv(MsgHeader* header, const char* data, size_t datalen)
{
    return 0;
}


void MsgComponent::regist_msg(int id, MsgHandler handler)
{
    handler_map_[id] = handler;
}
