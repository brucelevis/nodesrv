#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(Client)


#define MAX_MSG_NAME_LEN 128
static char recv_msg_name[MAX_MSG_NAME_LEN];
static char msg_name[MAX_MSG_NAME_LEN];
static int time_diff(struct timeval *t1, struct timeval *t2)
{
    int usec = (t2->tv_sec - t1->tv_sec) * 1000000 + t2->tv_usec - t1->tv_usec;
    return usec;
}


static void XOR(char *str, int str_len)
{
    for(int i = 0; i < str_len; i++)
    {
        str[i] = str[i] ^ 0xff;
    }
}

static void setnonblock(int sockfd)
{
    int flags;
    flags = fcntl(sockfd, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(sockfd, F_SETFL, flags);
}

static void setblock(int sockfd)
{
    int flags;
    flags = fcntl(sockfd, F_GETFL);
    flags &= ~O_NONBLOCK;
    fcntl(sockfd, F_SETFL, flags);
}



Client::Client()
{
//    net_component = NULL;
}

Client::~Client()
{

}

void Client::awake()
{
    LOG_DEBUG("Client::awake");
    //this->reg_msg(MSG_NEW_CONNECTION);
    //this->reg_msg(MSG_CLOSE_CONNECTION);
    //this->reg_msg(MSG_NET_RAW_DATA);
    //net_component = get_component<NetComponent>();
    //if (!net_component)
    //{
        //LOG_ERROR("net_component not found");
        //exit(0);
    //}
}

static char *s_send_buf;
static int s_send_size;
int Client::send(lua_State *L)
{
	if (lua_isnumber(L, 2) && lua_isuserdata(L, 3) && lua_isnumber(L, 4))
    {
        static int send_seq = 0;
        struct timeval t1;
        gettimeofday(&t1, NULL);
        int sockfd = (int)lua_tonumber(L, 2);

        LuaMessage *message_lua = (LuaMessage *)luaL_checkudata(L, 3, "LuaMessage");
        if(message_lua == NULL)
        {
            LOG_ERROR("checkuserdata is null");
            return 0;
        }
        google::protobuf::Message *message = message_lua->message;
        if(message == NULL)
        {
            LOG_ERROR("message is null");
            return 0;
        }
        const char *cmd = message->GetDescriptor()->full_name().data();
        if(cmd == NULL)
        {
            LOG_ERROR("cmd is null");
            return 0;
        }
        
        int timeout_sec = (int)lua_tonumber(L, 4);

        int msg_name_len = strlen(cmd);
        memcpy(msg_name, cmd, msg_name_len);
        msg_name[msg_name_len] = 0;

        LOG_MSG("SEND %s", cmd)
        setblock(sockfd);
        struct timeval tv;tv.tv_sec = timeout_sec; tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET,SO_RCVTIMEO, (char *)&tv,sizeof(tv));
        setsockopt(sockfd, SOL_SOCKET,SO_SNDTIMEO, (char *)&tv,sizeof(tv));

        int body_len = message->ByteSize();
        int plen = 4 + msg_name_len + 2  + sizeof(int) + body_len;
        if(s_send_size < plen)
        {
            s_send_size = plen;
            if(s_send_buf == NULL)
            {
                s_send_buf = (char *)malloc(s_send_size);
                if(s_send_buf == NULL)
                {
                    LOG_ERROR("malloc fail");
                    return 0;
            }
            }else
            {
                s_send_buf = (char *)realloc(s_send_buf, s_send_size);
                if(s_send_buf == NULL)
                {
                    LOG_ERROR("malloc fail");
                    return 0;
                }
            }
        }
        char *buf = s_send_buf;
        *((int *)buf) = plen - 4;
        buf += 4;

        send_seq = 4 * send_seq + 9;
        *((int *)buf) = send_seq;
        buf += sizeof(int);

        *((unsigned short *)buf) = msg_name_len;
        buf += 2;
        memcpy(buf, msg_name, msg_name_len);
        buf += msg_name_len;

        char * buf_end = (char *)message->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
        if(buf_end - buf != body_len){
            LOG_ERROR("serialize fail %d/%d cmd:%s\n", buf_end - buf, body_len, cmd);
            return 0;
        }
        int n = ::send(sockfd, s_send_buf, plen, 0);
        if(n < plen){
            LOG_ERROR("send fail n(%d) error(%s)", n, strerror(errno));
            return 0;
        }
        struct timeval t2;
        gettimeofday(&t2, NULL);

        if(body_len < 4096){
            LOG_MSG("%s", message->DebugString().data());
        }
        LOG_MSG("SEND %s plen:%d usec:%d", cmd, plen, time_diff(&t1, &t2))
        lua_pushboolean(L, true);
        setnonblock(sockfd);
        return 1;
	}
    lua_pushboolean(L, false);
    return 1;
}


static char *s_recv_buf;
static int s_recv_len;
static int s_recv_size;

int Client::recv(lua_State *L)
{
	if (lua_isnumber(L, 2) && lua_isnumber(L, 3))
    {
        struct timeval t1;
        gettimeofday(&t1, NULL);
        int sockfd = (int)lua_tonumber(L, 2);
        int timeout_sec = (int)lua_tonumber(L, 3);

        setblock(sockfd);
        struct timeval tv;tv.tv_sec = timeout_sec; tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET,SO_RCVTIMEO, (char *)&tv,sizeof(tv));
        setsockopt(sockfd, SOL_SOCKET,SO_SNDTIMEO, (char *)&tv,sizeof(tv));
        if(s_recv_buf == NULL)
        {
            s_recv_size = 1024 * 1024;
            s_recv_buf = (char *)malloc(s_recv_size);
            if(s_recv_buf == NULL)
            {
                LOG_ERROR("malloc fail");
                return 0;
            }
        }
        if(s_recv_len < 4)
        {
            int n = ::recv(sockfd, s_recv_buf + s_recv_len, 4 - s_recv_len, 0);
            if(n <= 0)
            {
                LOG_ERROR("recv fail");
                return 0;
            }
            s_recv_len += n;
        }
        char *body = s_recv_buf;
        int plen = *(int *)body + 4;
        
        if(s_recv_size < plen)
        {
            s_recv_size = plen;
            s_recv_buf = (char *)realloc(s_recv_buf, s_recv_size);
            if(s_recv_buf == NULL)
            {
                LOG_ERROR("relloc fail");
                s_recv_size = 0;
                s_recv_len = 0;
                return 0;
            }
        }
        if(s_recv_len < plen)
        {
            int n = ::recv(sockfd, s_recv_buf + s_recv_len, plen - s_recv_len, 0);
            if(n <= 0)
            {
                LOG_ERROR("recv fail");
                return 0;
            }
            s_recv_len += n;
        }
        int body_len = s_recv_len;
        body += sizeof(int);
        body_len -= sizeof(int);

        int seq = *(int *)body;
        body += sizeof(int);
        body_len -= sizeof(int);

        int msg_name_len = *(unsigned short *)body;
        body += sizeof(unsigned short);
        body_len -= sizeof(unsigned short);
        if(msg_name_len >= MAX_MSG_NAME_LEN - 1)
        {
            LOG_ERROR("reach max msg name len %d/%d", msg_name_len, MAX_MSG_NAME_LEN);
            return 0;
        }
        memcpy(recv_msg_name, body, msg_name_len);
        recv_msg_name[msg_name_len] = 0;

        body += msg_name_len;
        body_len -= msg_name_len;


        google::protobuf::Message* message = pblua_load_msg(recv_msg_name);
        if(message == NULL)
        {
            LOG_ERROR("can not load %d msg %s", msg_name_len, recv_msg_name);
            return 0;
        }
        google::protobuf::io::ArrayInputStream stream(body, body_len);
        
        if(message->ParseFromZeroCopyStream(&stream) == 0)
        {
            delete message;
            LOG_ERROR("parse fail\n");
            return 0;
        }

        LOG_MSG("RECV %s plen:%d", recv_msg_name, plen);

        if(message->ByteSize() < 4096)
        {
            LOG_MSG("%s", message->DebugString().data());
        }
        //msg
        LuaMessage *message_lua = (LuaMessage *)lua_newuserdata(L, sizeof(LuaMessage));
        if(message_lua == NULL)
        {
            delete message;
            LOG_ERROR("newuserdata null %s", recv_msg_name);
            return 0;
        }
        message_lua->message = message;
        message_lua->root_message = message_lua;
        message_lua->dirty = 0;
        luaL_getmetatable(L, "LuaMessage");
        lua_setmetatable(L, -2);

        struct timeval t2;
        gettimeofday(&t2, NULL);
        LOG_MSG("RECV %s plen:%d usec:%d", recv_msg_name, plen, time_diff(&t1, &t2));
        setnonblock(sockfd);
        
        s_recv_len -= plen;
        if(s_recv_len > 0)
        {
            memcpy(s_recv_buf, s_recv_buf + plen, s_recv_len);
        }
        return 1;
    }

    return 0;
}


