#ifndef _PORT_H_
#define _PORT_H_


//一个管理SOCKET的模块， 但解包已经不在C层了，
/*
    1.可写事件要小心用，有数据时才加，否则CPU会空转，但如果跑帧run_once的话不会有问题，
    2.但缓冲层也不在C了，所以会不断调用LUA的事件回调，所以还是有数据才加吧
    
Thu Oct  1 09:08:23 CST 2015
还是将BUF移进来吧，效率高点, 减少穿越次数
*/

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <tolua++.h>
}

#include "net/ae.h"

namespace Port 
{
    #define MAX_SOCK 10240
    typedef int ae_read_func(int sockfd, const char* buf, int datalen);
    typedef void ae_write_func(int sockfd);
    typedef int ae_accept_func(int sockfd);

    typedef struct Port
    {
        lua_State *L;  
        struct aeEventLoop *loop;
        void *userdata;
        ae_read_func* on_read;
        ae_write_func* on_write;
        ae_accept_func* on_accept;
        char lua_on_read[128];
        char lua_on_accept[128];
        char lua_on_close[128];
        char lua_on_connect_err[128];
        char lua_on_connect_suc[128];
        char name[64];
        int timerid;
    }Port;

    typedef struct Sock
    {
        Port* port;
        int sockfd;
        int shutdown; 
        int uid;
        int send_seq; 
        int recv_seq; 
        int userdata;
        int srvid;
        int handshake;
    }Sock;

    int remove_write_event(int sockfd);
    int add_write_event(int sockfd);

    int listen(Port* port, unsigned short listenport);
    const char* getpeerip(int sockfd);;
    int getpeerport(int sockfd);

    int syncconnect(Port* port, const char* ip, unsigned short portnum);
    int connect(Port* port, const char* ip, unsigned short portnum);

    int free(Port* port);
    int rename(Port* port, const char *name);
    int getsrvid(int sockfd);
    int setsrvid(int sockfd, int srvid);
    int getuserdata(int sockfd);
    int setuserdata(int sockfd, int userdata);
    int setuid(int sockfd, int uid);
    int close(int sockfd, const char *reason);
    int shutdown(int sockfd);
    Port* create(struct aeEventLoop* loop);
    int send(int sockfd, char *buf, int buflen);
    int recv(int sockfd, char *buf, int buflen);
    Port* sock2port(int sockfd);
    Sock* sockfromfd(int sockfd);
    bool sock_is_close(int sockfd);


    int set_read_func(Port* port, ae_read_func* func);
    int set_write_func(Port* port, ae_read_func* func);
    int set_accept_func(Port* port, ae_accept_func* func);
};

#endif

