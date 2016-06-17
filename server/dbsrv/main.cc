#include "nodeapi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    NodeMgr::create_node_local(1, "main.lua");
    for(;;)
    {
        sleep(1);
        NodeMgr::update(time(NULL));
    }
    return 0;
}
