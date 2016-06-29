
#include "nodesrv.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

    Nodesrv::init();

    printf("\ncreate node local 1\n");
    NodeMgr::create_node_local(1);//, "data/gatesrv/main.lua");

    printf("\ncreate node local 2\n");
    NodeMgr::create_node_local(2);//, "data/gamesrv/main.lua");

    for(;;)
    {
        sleep(1);
        NodeMgr::update(time(NULL));
    }

    return 0;
}

