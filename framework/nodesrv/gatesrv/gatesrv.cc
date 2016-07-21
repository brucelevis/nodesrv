#include "gatesrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(GateSrv)

#define MAX_SOCKFD 65536

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

typedef struct tagSession
{
    int sockfd; 
    unsigned int sid;
    int recv_seq;
    int send_seq;
} Session;

static Session session_arr[MAX_SOCKFD];
static uint16_t sessionid_counter = 0;

static Session* session_find(uint32_t sid)
{
    int sockfd = sid >> 16;
    if (sockfd <= 0 || sockfd >= MAX_SOCKFD)
    {
        return NULL;
    }
    Session* session = &session_arr[sockfd];
    if (session->sid != sid)
    {
        return NULL;
    }
    return session;
}

static Session* session_get(int sockfd)
{
    if (sockfd < 0 || sockfd >= MAX_SOCKFD)
    {
        return NULL;
    }
    Session* session = &session_arr[sockfd];
    if (session->sockfd != sockfd)
    {
        return NULL;
    }
    return session;
}

int session_init(int sockfd)
{
    if (sockfd < 0 || sockfd >= MAX_SOCKFD)
    {
        return 0;
    }
    Session* session = &session_arr[sockfd];
    memset(session, 0, sizeof(Session));
    session->sockfd = sockfd;
    session->sid = sockfd << 16 | sessionid_counter++;
    return session->sid;
}

void session_destory(int sockfd)
{

}


GateSrv::GateSrv()
{
    net_component = NULL;
}

GateSrv::~GateSrv()
{

}


void GateSrv::listen()
{
    NetComponent* net_component = get_component<NetComponent>();
    if (!net_component)
    {
        LOG_ERROR("net component is nil");
        exit(1);
        return;
    }
}

void GateSrv::awake()
{
    LOG_DEBUG("GateSrv::awake");
    this->reg_msg(MSG_NEW_CONNECTION);
    this->reg_msg(MSG_CLOSE_CONNECTION);
    this->reg_msg(MSG_NET_RAW_DATA);
    net_component = get_component<NetComponent>();
    if (!net_component)
    {
        LOG_ERROR("net_component not found");
        exit(0);
    }
}

int GateSrv::recv(Message* msg)
{
    switch(msg->header.id)
    {
        case MSG_NEW_CONNECTION:
            {
                return recv_new_connection(msg);
            }
            break;
        case MSG_CLOSE_CONNECTION:
            {
                return recv_close_connection(msg);
            }
            break;
        case MSG_NET_RAW_DATA:
            {
                return recv_net_raw_data(msg);
            }
            break;
    }
    return 0;
}

int GateSrv::recv_net_raw_data(Message* msg)
{
    LOG_DEBUG("recv_net_packet payload(%d)", msg->datalen);
    char *body = (char*)msg->data;
    uint32_t bodylen = msg->datalen;
    if (bodylen < sizeof(int))
    {
        return 0;
    }
    int sockfd = msg->sockfd;
    Session* session = session_get(sockfd);
    if (!session)
    {
        LOG_ERROR("session not found");
        return 0;
    }

    int plen = *(int *)body + 4;
    body += sizeof(int);
    bodylen -= sizeof(int);

    int seq = *(int *)body;
    body += sizeof(int);
    bodylen -= sizeof(int);

    session->recv_seq = 4 * session->recv_seq + 9;
    if(session->recv_seq != seq)
    {
        LOG_ERROR("seq error expected %d recv %d", session->recv_seq, seq);
    }else
    {
        struct timeval t1;
        gettimeofday(&t1, NULL);

        Message* msg = alloc_msg();
        msg->header.src_nodeid = 0;
        msg->header.src_objectid = 0;
        msg->header.dst_objectid = 0;
        msg->header.dst_nodeid = 0;
        msg->header.id = MSG_NET_PACKET;
        msg->sockfd = sockfd;
        msg->sid = session->sid;
        msg->payload.reset();
        msg->payload.write_buf(body, bodylen);
        this->gameobject->recv(msg);
    }
    return plen;

}

int GateSrv::recv_close_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    LOG_DEBUG("HttpComponent recv_close_connection sockfd(%d)", sockfd);
    Session* session = session_get(sockfd);
    if (!session)
    {
        return 0;
    }
    Message* msg2 = alloc_msg();
    msg2->header.src_nodeid = 0;
    msg2->header.src_objectid = 0;
    msg2->header.dst_objectid = 0;
    msg2->header.dst_nodeid = 0;
    msg2->header.id = MSG_CLOSE_SESSION;
    msg2->sid = session->sid;
    this->gameobject->recv(msg2);
    session_destory(sockfd);
    return 0;

}


int GateSrv::recv_new_connection(Message* msg)
{
    int sockfd = msg->sockfd;
    int sid = session_init(sockfd);
    LOG_DEBUG("recv_new_connection sockfd(%d) sid(%d)", sockfd, sid);
    Message* msg2 = alloc_msg();
    msg2->header.src_nodeid = 0;
    msg2->header.src_objectid = 0;
    msg2->header.dst_objectid = 0;
    msg2->header.dst_nodeid = 0;
    msg2->header.id = MSG_NEW_SESSION;
    msg2->sid = sid;
    this->gameobject->recv(msg2);
    return 0;


}

int GateSrv::reply(lua_State *L)
{
	if (!lua_isnumber(L, 2) || !lua_isuserdata(L, 3))
    {
        LOG_ERROR("arg error");
        return 0;
    }
    struct timeval t1;
    gettimeofday(&t1, NULL);
    int sid = (int)lua_tonumber(L, 2);
    Session* session = session_find(sid);
    if (!session)
    {
        LOG_ERROR("session not found");
        return 0;
    }
    int sockfd = session->sockfd;

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

    int msg_name_len = strlen(cmd);
    memcpy(msg_name, cmd, msg_name_len);
    msg_name[msg_name_len] = 0;

    LOG_INFO("SEND %s", cmd);

    int body_len = message->ByteSize();
    int plen = 4 + sizeof(int) + msg_name_len + 2  + body_len;
    char *buf = net_component->alloc_send_buf(sockfd, plen);
    if(buf == NULL)
    {
        LOG_ERROR("alloc fail cmd:%s\n", cmd);
        return 0;
    }

    *((int *)buf) = plen - 4;
    buf += 4;

    session->send_seq = 4 * session->send_seq + 9;
    *((int *)buf) = session->send_seq;
    buf += sizeof(int);

    *((unsigned short *)buf) = msg_name_len;
    buf += 2;
    memcpy(buf, msg_name, msg_name_len);
    buf += msg_name_len;

    char * buf_end = (char *)message->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
    if(buf_end - buf != body_len)
    {
        LOG_ERROR("serialize fail %d/%d cmd:%s\n", buf_end - buf, body_len, cmd);
        return 0;
    }
    //加进socket的发送队列
    net_component->flush_send_buf(sockfd, buf, plen);

    struct timeval t2;
    gettimeofday(&t2, NULL);

    LOG_INFO("SEND %s plen:%d usec:%d", cmd, plen, time_diff(&t1, &t2));
    if(body_len < 4096)
    {
        LOG_DEBUG("%s", message->DebugString().data());
    }
    lua_pushboolean(L, true);
    return 1;
}


