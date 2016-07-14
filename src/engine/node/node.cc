#include "node.h"

#include "msg/msg.h"
#include "node/entity.h"
#include "node/entityroute.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "script/script.h"
#include "component/rpccomponent.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


static uint32_t MAGIC_CODE = 19860801;

static int time_diff(struct timeval *t1, struct timeval *t2)
{
    int usec = (t2->tv_sec - t1->tv_sec) * 1000000 + t2->tv_usec - t1->tv_usec;
    return usec;
}

static void _ev_accept(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    Node* node = (Node*)clientData;
    node->ev_accept(sockfd);
}

static void _ev_writable(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    Node* node = (Node*)clientData;
    node->ev_writable(sockfd);
}

static void _ev_readable(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    Node* node = (Node*)clientData;
    node->ev_readable(sockfd);
}

Node::Node(int nodeid)
{
    this->id = nodeid;
    sockfd_ = -1;
    listenfd_ = -1;
    ip_[0] = 0;
    port_ = 0;
    name[0] = 0;
    this->is_connect_ = false;
}

void Node::main()
{
    lua_State* L = NodeMgr::L;
    //将自己注册到lua
    tolua_pushusertype(L, (void*)this, "Node");
    lua_setglobal(L, "mysrv");
    //创建事件
    //loop_ = aeCreateEventLoop(10240);
    //if (mainfile[0] != 0)
    //{
        //lua_dofile(mainfile);
    //}
}

Node::~Node()
{
    ::close(sockfd_);
}

void Node::ev_accept(int listenfd)
{
    int sockfd;	
    int error;
    struct sockaddr_in addr;	
    socklen_t addrlen = sizeof(addr);	
    sockfd = ::accept(listenfd, (struct sockaddr*)&addr, &addrlen);
    if(sockfd < 0)
    {
        return;
    }
    error = ::fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    if (error < 0) 
    {
        return;
    }
    LOG_INFO("accept a new socket");
    //Sendbuf::create(sockfd);
    Recvbuf::create(sockfd, 1024);
    create_file_event(sockfd, AE_READABLE, _ev_readable, this);
}

void Node::ev_readable(int sockfd)
{
    LOG_DEBUG("node[%d] ev_readable", this->id);
    //接收数据
    for(;;)
    {
        char* wptr= Recvbuf::getwptr(sockfd);
        int buflen = Recvbuf::bufremain(sockfd);
        int ir = ::recv(sockfd, wptr, buflen, 0);
        LOG_DEBUG("node[%d] real recv %d", this->id, ir);
        if (ir == 0 || (ir == -1 && errno != EAGAIN))
        {
            real_close(sockfd, "peer close");
            break;
        }
        if (ir == -1 && errno == EAGAIN)
        {
            break;
        }
        //for (int i = 0; i < ir; i++)
        //{
            //printf("%d\n", wptr[i]);
        //}
        Recvbuf::wskip(sockfd, ir);

        for (;;)
        {
            char* rptr = Recvbuf::getrptr(sockfd);
            int datalen = Recvbuf::datalen(sockfd);
            int packetlen = dispatch(rptr, datalen);
            if (packetlen > 0)
            {
                Recvbuf::rskip(sockfd, packetlen);
                Recvbuf::buf2line(sockfd);
            } else 
            {
                break;
            }
        }
    }
}

void Node::ev_writable(int sockfd)
{
    LOG_DEBUG("node[%d] ev_writable sockfd(%d)", this->id, sockfd);
    //发送数据
    for(;;)
    {
        if (send_msg_queue.size() <= 0)
        {
            LOG_DEBUG("node[%d] delete write event", this->id);
            delete_file_event(sockfd, AE_WRITABLE);
            break;
        }
        int ir = 0;
        Message* msg = send_msg_queue.front();
        if (msg->byte_sent < sizeof(msg->magic_code) + sizeof(msg->header) + sizeof(msg->magic_code2))
        {
            char* buf = (char*)(&msg->magic_code);
            ir = ::send(sockfd, buf + msg->byte_sent, sizeof(msg->magic_code) + sizeof(msg->header) + sizeof(msg->magic_code2) - msg->byte_sent, 0);
            //for (int i = 0; i < ir; i++)
            //{
                //printf("%d\n", (buf + msg->byte_sent)[i]);
            //}
            if (ir > 0)msg->byte_sent += ir; else goto ev_writable_end; 
        }
        LOG_DEBUG("node[%d] real send header %d", this->id, ir);
        if (msg->payload.size() <= 0)
        {
            send_msg_queue.pop();
            destory_msg(msg);
            break;
        }
        ir = ::send(sockfd, msg->payload.get_buffer(), msg->payload.size(), 0);
        if (ir > 0)
        {
            //for (int i = 0; i < ir; i++)
            //{
                //printf("%d\n",  (msg->payload.get_buffer())[i]);
            //}
            msg->byte_sent += ir;
            msg->payload.read_buf(NULL, ir);
        }
        LOG_DEBUG("node[%d] real send %d", this->id, ir);

ev_writable_end:
        if (ir == -1 && errno == EAGAIN) 
        {
            break;
        } else if(ir == -1) 
        {
            real_close(sockfd, "peer close");
            break;
        }
    }
}

int Node::listen(const char* host, unsigned short port)
{
    if (this->listenfd_ != -1)
    {
        LOG_DEBUG("node[%d] is listening", this->id);
        return 1;
    }
    int error;
    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        LOG_DEBUG("node[%d] socket error", this->id);
        return 1;
    }
    error = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    if (error < 0)
    {
        LOG_DEBUG("node[%d] fcntl error", this->id);
        ::close(sockfd);
        return 2;
    }
    struct sockaddr_in addr;
	bzero((void*)&addr, sizeof(addr));	
	addr.sin_family = AF_INET;	
	addr.sin_addr.s_addr = INADDR_ANY;	
	addr.sin_port = htons(port);	
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	error = ::bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	if(error < 0)
    {		
        ::close(sockfd);
        LOG_ERROR("node[%d] bind error %d", this->id, port);
		return 3;	
    }
	error = ::listen(sockfd, 5);	
    if(error < 0)
    {
        ::close(sockfd);
        LOG_ERROR("node[%d] listen error", this->id);
        return 4;
    }
    this->listenfd_ = sockfd;
    create_file_event(sockfd, AE_READABLE | AE_WRITABLE, _ev_accept, this);
    LOG_INFO("node[%d] listen(%d) success", this->id, port);
    return 0;
}

int Node::connect(const char* host, unsigned short port)
{
    strcpy(this->ip_, host);
    this->port_ = port;
    return 0;
}

int Node::real_connect()
{
    //LOG_DEBUG("real_connect");
    int error;
    int sockfd;
    if (this->is_connect_)
    {
        return 1;
    }
    if (this->sockfd_ == -1)
    {
        sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            LOG_DEBUG("node[%d] connect socket error", this->id);
            return 1;
        }
        error = ::fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
        if (error < 0)
        {
            LOG_DEBUG("node[%d] connect fcntl error", this->id);
            ::close(sockfd);
            return 1;
        }
        this->sockfd_ = sockfd;
    }

    if (this->sockfd_ != -1)
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;	
        if(inet_addr(this->ip_) != (in_addr_t)-1)
        {
            addr.sin_addr.s_addr = inet_addr(this->ip_);   
        }else
        {
            struct hostent *hostent;
            hostent = gethostbyname(this->ip_);
            if(hostent->h_addr_list[0] == NULL)
            {
                return 1;
            }
            memcpy(&addr.sin_addr, (struct in_addr *)hostent->h_addr_list[0], sizeof(struct in_addr));
        } 
        addr.sin_port = htons(this->port_);        
        error = ::connect(this->sockfd_, (struct sockaddr *)&addr, sizeof(addr));
        if ((error == 0) || (error < 0 && errno == EISCONN))
        {
            LOG_INFO("node[%d] reconnect success", this->id);
            this->is_connect_ = true;
            create_file_event(this->sockfd_, AE_READABLE, _ev_readable, this);
            create_file_event(this->sockfd_, AE_WRITABLE, _ev_writable, this);
            //send_node_reg();
        } else
        {
            //LOG_DEBUG("node[%d] reconnect error(%d) errno(%d)", this->id, error, errno);
        }
    }
    return 0;
}

void Node::update(long long cur_tick)
{
    
    if (!this->is_connect_ && this->ip_[0])
    {
        real_connect();
    }

    //处理节点
    for (int i = entity_vector_.size() - 1; i >= 0; i--)
    {
        Entity* entity = entity_vector_[i];
        entity->update(cur_tick);
    } 
}


void Node::recv(Message* msg)
{
    LOG_MSG("MESSAGE node[%d] msgid(%d) src_node(%d,%d) len(%d)", this->id, msg->header.id, msg->header.src_nodeid, msg->header.src_entityid, msg->header.len);
    struct timeval t1;
    gettimeofday(&t1, NULL);
    //不可靠的消息传输
    switch(msg->header.id)
    {
        case MSG_NODE_REG:
            {
                recv_node_reg(msg);
            }
            break;
        case MSG_CREATE_ENTITY:
            {
                recv_create_entity(msg);
            };
            break;
        default:
            {
                recv_entity_msg(msg);
            }
            break;
    }
    struct timeval t2;
    gettimeofday(&t2, NULL);
    LOG_MSG("MESSAGE node[%d] msgid(%d) src_node(%d,%d) len(%d) usec(%d)", this->id, msg->header.id, msg->header.src_nodeid, msg->header.src_entityid, msg->header.len, time_diff(&t1, &t2));
}

int Node::dispatch(char* data, size_t datalen)
{
    uint32_t magic_code = 0;
    uint32_t magic_code2 = 0;
    if (datalen < sizeof(magic_code) + sizeof(MessageHeader) + sizeof(magic_code2))
    {
        return 0;
    }
    magic_code = *(int *)(data);
    MessageHeader *header = (MessageHeader*)(data + sizeof(magic_code));
    magic_code2 = *(int *)(data + sizeof(magic_code) + sizeof(MessageHeader));
    if (magic_code2 - header->len != magic_code)
    {
        LOG_ERROR("magic code error");
        return sizeof(magic_code);
    }
    if (datalen < sizeof(magic_code) + header->len + sizeof(magic_code))
    {
        return 0;
    }
    char *payload = data + sizeof(magic_code) + sizeof(MessageHeader) + sizeof(magic_code2);
    int payloadlen = header->len - sizeof(MessageHeader);

    Message* msg = alloc_msg();
    msg->header = *header;
    msg->payload.reset();
    msg->payload.write_buf(payload, payloadlen);
    recv(msg);
    destory_msg(msg);

    return sizeof(magic_code) + header->len + sizeof(magic_code2);
}

void Node::forward_entity_msg(Message* msg)
{
    //先发给本地实体
    Entity* entity = find_entity(msg->header.dst_entityid);
    if (entity)
    {
        entity->recv(msg);
        return;
    }
    if (is_disconnect())
    {
        return;
    }
    send_entity_msg(NULL, msg);
}

void Node::recv_entity_msg(Message* msg)
{
    int dst_entityid = msg->header.dst_entityid;
    //广播 
    if (dst_entityid == 0)
    {
        for (int i = entity_vector_.size() - 1; i >= 0; i--)
        {
            Entity* entity = entity_vector_[i];
            entity->recv(msg);
        }
    } else
    {
        Entity* entity = find_entity(dst_entityid);
        if(entity)
        {
            entity->recv(msg);
        } else
        {
            //转发到中心节点
            Node* center_node = EntityRoute::center_node_;
            if (center_node == this)
            {
                return;
            }
            if (center_node)
            {
                center_node->forward_entity_msg(msg);
            }
        }
    }
}

void Node::send_entity_msg(Entity* src_entity, int dst_nodeid, int dst_entityid, Message* msg)
{
    if (!src_entity)
    {
        LOG_ERROR("src_entity not found");
        return;
    }
    Node* src_node = src_entity->node;
    if (!src_node)
    {
        LOG_ERROR("src_node not found");
        return;
    }
    Node* node = NodeMgr::find_node(dst_nodeid);
    if (!node)
    {
        LOG_ERROR("dst_node(%d) not found", dst_nodeid);
        return;
    }
    msg->header.src_entityid = src_entity->id;
    msg->header.src_nodeid = src_node->id;
    msg->header.dst_nodeid = dst_nodeid;
    msg->header.dst_entityid = dst_entityid;
    node->send_entity_msg(src_entity, msg);
}

void Node::send_entity_msg(Entity* src_entity, Message* msg)
{
    if (src_entity)
    {
        msg->header.src_entityid = src_entity->id;
        msg->header.src_nodeid = src_entity->node->id;
    }
    //发给本地实体
    Entity* dst_entity = find_entity(msg->header.dst_entityid);
    if (dst_entity)
    {
        dst_entity->recv(msg);
        destory_msg(msg);
    } 
    else if (is_disconnect())
    {
        LOG_WARN("node[%d] is disconnect", get_id());
        int src_entityid = msg->header.src_entityid;
        Entity* src_entity = find_entity(src_entityid);
        if (src_entity)
        {
            src_entity->unreach(msg);
        } 
        if (msg->option.cache)
        {
            msg->header.len = sizeof(MessageHeader) + msg->payload.size();
            msg->magic_code = MAGIC_CODE;
            MAGIC_CODE += msg->header.len;
            msg->magic_code2 = MAGIC_CODE;
            this->send_msg_queue.push(msg);
        } else 
        {
            destory_msg(msg);
        }
    }
    else 
    {
        msg->header.len = sizeof(MessageHeader) + msg->payload.size();
        msg->magic_code = MAGIC_CODE;
        MAGIC_CODE += msg->header.len;
        msg->magic_code2 = MAGIC_CODE;
        this->send_msg_queue.push(msg);
        create_file_event(this->sockfd_, AE_WRITABLE, _ev_writable, this);
    }
}

void Node::send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const Buffer* buffer)
{
    LOG_INFO("node[%d] send entity msg(%d)", this->id, msgid);
    Node* src_node = src_entity->node;
    if (!src_node)
    {
        return;
    }
    Message* msg = alloc_msg();
    MessageHeader& header = msg->header;
    header.src_nodeid = src_node->get_id();
    header.src_entityid = src_entity->id;
    header.dst_entityid = dst_entityid;
    header.dst_nodeid = this->id;
    header.id = msgid;

    msg->payload.reset();
    msg->payload.write(buffer);

    send_entity_msg(src_entity, msg);
}


bool Node::is_local()
{
    return is_local_;
}

void Node::set_local(bool v)
{
    is_local_ = v;
}

int Node::get_id()
{
    return id;
}


int Node::add_entity(Entity* entity)
{
    LOG_DEBUG("node[%d] add entity(%d)", this->id, entity->id);
    entity_map_[entity->id] = entity; 
    entity_vector_.push_back(entity);
    entity->node = this;
    return 0;
}


Entity* Node::find_entity(int entityid)
{
    std::map<int, Entity*>::iterator it;
    it = entity_map_.find(entityid);
    if (it != entity_map_.end())
    {
        return it->second;
    }
    return NULL;
}

int Node::real_close(int sockfd, const char* err)
{
    LOG_DEBUG("real close %s", err);
    //移动事件
    delete_file_event(sockfd, AE_READABLE);
    delete_file_event(sockfd, AE_WRITABLE);
    //关闭socket
    ::close(sockfd);
    if (sockfd == this->sockfd_)
    {
        this->is_connect_ = false;
        this->sockfd_ = -1;
    }
    return 0;
}

bool Node::is_disconnect()
{
    return !this->is_connect_;
}


void Node::recv_node_reg(Message* msg)
{
    LOG_DEBUG("node[%d] recv node[%d] reg", this->id, msg->header.src_nodeid);
}

void Node::send_node_reg()
{
    LOG_DEBUG("node[%d] send node reg", this->id);
    Message* msg = alloc_msg();
    MessageHeader& header = msg->header;
    header.src_nodeid = this->id;
    header.src_entityid = 0;
    header.dst_entityid = 0;
    header.dst_nodeid = this->id;
    header.id = MSG_NODE_REG;
    send_entity_msg(NULL, msg);
}


void Node::recv_create_entity(Message* msg)
{
    const char* filepath = msg->payload.read_utf8();
    LOG_DEBUG("node[%d] recv create entity %s", this->id, filepath);
    create_entity_local(filepath);
}

void Node::create_entity_remote(Entity* src_entity, const char* filepath)
{
    LOG_DEBUG("node[%d] send create entity %s", this->id, filepath);

    Node* src_node = src_entity->node;

    Message* msg = alloc_msg();
    MessageHeader& header = msg->header;
    header.src_nodeid = src_node->id;
    header.src_entityid = src_entity->id;
    header.dst_entityid = 0;
    header.dst_nodeid = this->id;
    header.id = MSG_CREATE_ENTITY;
    msg->payload.write_utf8(filepath);

    if (is_local())
    {
        recv(msg);
        destory_msg(msg);
    } else
    {
        send_entity_msg(NULL, msg);
    }
}


int Node::create_file_event(int fd, int mask, aeFileProc* proc, void* userdata)
{
    return aeCreateFileEvent(NodeMgr::loop, fd, mask, proc, userdata);
}

void Node::delete_file_event(int fd, int mask)
{
    aeDeleteFileEvent(NodeMgr::loop, fd, mask);
}


Entity* Node::create_entity_local(const char* filepath)
{
    lua_State* L = NodeMgr::L;
    LOG_DEBUG("node[%d] create entity local %s", this->id, filepath);
    Entity* entity = NULL;
    if (filepath == NULL)
    {
        entity = new Entity();
    } 
    else 
    {
        //调用脚本初始化实体
        lua_getglobal(L, "instantiate");
        lua_getglobal(L, filepath);
        if (lua_pcall(L, 1, 1, 0) != 0)
        {
            LOG_DEBUG("node[%d] create entity local error %s", this->id, lua_tostring(L, -1));
            lua_printstack();
        }
        tolua_Error tolua_err;
        if(!tolua_isusertype(L, -1, "Entity", 0, &tolua_err))
        {
            lua_pop(L, lua_gettop(L));
            return NULL;
        }
        entity = (Entity*)tolua_tousertype(L, -1, 0);
        lua_pop(L, lua_gettop(L));
    }
    if (entity == NULL)
    {
        return NULL;
    }
    this->add_entity(entity);
    entity->awake();
    return entity;
}


void Node::transfer_entity(Entity* src_entity)
{

} 

int Node::lua_printstack() 
{
    lua_State* L = NodeMgr::L;
    return Script::lua_printstack(L);
}


int Node::lua_pushfunction(const char *func)
{
    lua_State* L = NodeMgr::L;
    return Script::lua_pushfunction(L, func);
}

bool Node::lua_getvalue(const char *fieldname)
{
    lua_State* L = NodeMgr::L;
    return Script::lua_getvalue(L, fieldname);
}

const char* Node::lua_getstring(const char *fieldname)
{
    lua_State* L = NodeMgr::L;
    return Script::lua_getstring(L, fieldname);
}

int64_t Node::lua_getnumber(const char *fieldname)
{
    lua_State* L = NodeMgr::L;
    return Script::lua_getnumber(L, fieldname);
}

void Node::lua_reglib(int (*p)(lua_State* L))
{
    lua_State* L = NodeMgr::L;
    Script::lua_reglib(L, p);
}

int Node::lua_dofile(const char* filepath)
{
    lua_State* L = NodeMgr::L;
    return Script::lua_dofile(L, filepath);
}

Message* Node::alloc_msg()
{
    Message* msg = new Message();
    msg->ref_count++;
    return msg;
}

void Node::destory_msg(Message* msg)
{
    if(msg == NULL)
    {
        return;
    }
    msg->ref_count--;
    if (msg->ref_count <= 0)
    {
        delete msg;
    }
}

int Node::post(lua_State* L)
{
    Entity* entity = find_entity(0);
    if(!entity)
    {
        LOG_ERROR("entity 0 not found");
        return 0;
    }
    RPCComponent* rpc = dynamic_cast<RPCComponent *>(entity->get_component(RPCComponent::type));
    if (!rpc)
    {
        LOG_ERROR("rpc component not found");
        return 0;
    }
    return rpc->post(L);
}




