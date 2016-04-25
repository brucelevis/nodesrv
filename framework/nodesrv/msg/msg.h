#ifndef _MSG_H_
#define _MSG_H_

typedef struct tagMsgHeader{
    unsigned int len;
    //源实体id
    unsigned int src_entityid;
    unsigned int src_nodeid;
    //目标实体id
    unsigned int dst_entityid;
    unsigned int dst_nodeid;
    //消息id
    union {
        unsigned int id;
        struct 
        {
            unsigned short sysid;
            unsigned short cmdid;
        };
    };
}MsgHeader;

//发送消息
#define MSG_SEND 1
//连接节点
#define MSG_NODE_REG 3
//创建实体
#define MSG_CREATE_ENTITY 4

#pragma pack(push, 1)
typedef struct tagCreateEntityMsg
{
    unsigned short len;
    char filepath[64];
} CreateEntityMsg;
#pragma pack(pop)

#endif
