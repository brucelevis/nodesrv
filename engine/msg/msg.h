#ifndef _MSG_H_
#define _MSG_H_
#include <stdint.h>
#include <stdlib.h>

//tolua_begin
typedef struct tagMessage
{
    uint32_t src_entityid;
    uint32_t src_nodeid;
    uint32_t dst_entityid;
    uint32_t dst_nodeid;
    uint32_t id;
    int sockfd;
    int sid;
    const char* data;
    size_t datalen;
} Message;

typedef struct tagMsgHeader
{
    uint32_t len;
    //源实体id
    uint32_t src_entityid;
    uint32_t src_nodeid;
    //目标实体id
    uint32_t dst_entityid;
    uint32_t dst_nodeid;
    //消息id
    uint32_t id;
} MsgHeader;

//发送消息
#define MSG_SEND 1
//连接节点
#define MSG_NODE_REG 3
//创建实体
#define MSG_CREATE_ENTITY 4
//网络原始数据
#define MSG_NET_RAW_DATA 5
//网络数据包
#define MSG_NET_PACKET 6
//新链接
#define MSG_NEW_CONNECTION 7

#pragma pack(push, 1)

//创建实体
typedef struct tagCreateEntityMsg
{
    unsigned short len;
    char filepath[64];
} CreateEntityMsg;

#pragma pack(pop)

//tolua_end

#endif
