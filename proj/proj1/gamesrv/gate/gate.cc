
#include "gate/gate.h"


Gate::Gate()
{

}


Gate::~Gate()
{

}


int Gate::recv_login(MsgHeader* header, const char* data, size_t size)
{
#pragma pack(push, 1)
    static struct Data
    {

    }data;
#pragma pack(pop)
    return 0;
}
