
#include "neox.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

    HttpClient client;
    client.connect("192.168.100.34", 12341);
    client.send_open_websock();
    //client.send("GET / HTTP/1.1\r\n");
    //client.send("\r\n");
    client.recv();
    client.send_string_frame("hello");
    client.recv_frame();

    //Logger logger;
    //logger.set_tag("gatesrv1");
    //logger.set_format("[%06Y][%T][%P][%L]%s\n");
    //logger.info("helloaaaba");
    //logger.info("helloaaabb");
    //logger.info("helloaaabc");
    //Neox::init();
    //printf("\ncreate node local 1\n");
    //NodeMgr::create_node_local(1);//, "data/gatesrv/main.lua");
    //printf("\ncreate node local 2\n");
    //NodeMgr::create_node_local(2);//, "data/gamesrv/main.lua");
    //for(;;)
    //{
        //sleep(1);
        //NodeMgr::update(time(NULL));
    //}
    return 0;
}

