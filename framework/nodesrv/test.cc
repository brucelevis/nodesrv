
#include "nodeapi.h"

#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{

    Nodeapi::init();

    printf("create node local 1\n");
    NodeMgr::create_node_local(1, "data/node1/main.lua");

    printf("create node local 2\n");
    NodeMgr::create_node_local(2, "data/node2/main.lua");

    for(;;)
    {
        sleep(1);
        NodeMgr::update(time(NULL));
    }

    return 0;
}

