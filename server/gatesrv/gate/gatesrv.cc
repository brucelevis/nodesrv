
#include "gate/gatesrv.h"
#include "components/netcomponent.h"
#include "entity/entity.h"
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
    printf("GateSrv::awake()\n");
    NetComponent* net_component = (NetComponent*)this->entity->get_component("NetComponent");
    if (!net_component)
    {
        printf("net component is nil");
        exit(1);
        return;
    }
    net_component->listen("127.0.0.1", 9090);
}
