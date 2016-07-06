#include "node.h"

#include "msg/msg.h"
#include "node/entity.h"
#include "node/entityroute.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"
#include "node/nodemgr.h"
#include "log/log.h"
#include "script/script.h"

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

extern "C"{
    int luaopen_neox(lua_State* tolua_S);
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
}

void Node::on_create()
{
    L = lua_open();
    luaL_openlibs(L);
    luaopen_neox(L);
}

void Node::main(const char* mainfile)
{
    //将自己注册到lua
    tolua_pushusertype(L, (void*)this, "Node");
    lua_setglobal(L, "mynode");
    //创建事件
    loop_ = aeCreateEventLoop(10240);
    if (mainfile[0] != 0)
    {
        lua_dofile(mainfile);
    }
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
    printf("accept a new socket\n");
    Sendbuf::create(sockfd);
    Recvbuf::create(sockfd, 1024);
    create_file_event(sockfd, AE_READABLE, _ev_readable, this);
}

void Node::ev_readable(int sockfd)
{
    printf("node[%d] ev_readable\n", this->id);
    //接收数据
    for(;;)
    {
        char* wptr= Recvbuf::getwptr(sockfd);
        int buflen = Recvbuf::bufremain(sockfd);
        int ir = ::recv(sockfd, wptr, buflen, 0);
        printf("node[%d] real recv %d\n", this->id, ir);
        if (ir == 0 || (ir == -1 && errno != EAGAIN))
        {
            break;
        }
        if (ir == -1 && errno == EAGAIN)
        {
            break;
        }
        Recvbuf::wskip(sockfd, ir);
        char* rptr = Recvbuf::getrptr(sockfd);
        int datalen = Recvbuf::datalen(sockfd);

        int packetlen = dispatch(rptr, datalen);
        if (packetlen > 0)
        {
            Recvbuf::rskip(sockfd, packetlen);
            Recvbuf::buf2line(sockfd);
        }
        break;
    }
}

void Node::ev_writable(int sockfd)
{
    printf("node[%d] ev_writable\n", this->id);
    //发送数据
    for(;;)
    {
        int datalen = Sendbuf::datalen(sockfd_);
        if (datalen <= 0)
        {
            printf("node[%d] delete write event\n", this->id);
            delete_file_event(this->sockfd_, AE_WRITABLE);
            break;
        }
        char* buf = Sendbuf::get_read_ptr(sockfd_);
        int ir = ::send(sockfd_, buf, datalen, 0);
        printf("node[%d] real send %d\n", this->id, ir);
        if (ir > 0) 
        {
            Sendbuf::skip_read_ptr(sockfd_, ir);
        } else if (ir == -1 && errno == EAGAIN) 
        {
            break;
        } else if(ir == -1) 
        {
            real_close("peer close");
            break;
        }
    }
}

int Node::listen(const char* host, unsigned short port)
{
    if (this->listenfd_ != -1)
    {
        printf("node[%d] is listening\n", this->id);
        return 1;
    }
    int error;
    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("node[%d] socket error\n", this->id);
        return 1;
    }
    error = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    if (error < 0)
    {
        printf("node[%d] fcntl error\n", this->id);
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
	if(error < 0){		
        ::close(sockfd);
        printf("node[%d] bind error\n", this->id);
		return 3;	
    }
	error = ::listen(sockfd, 5);	
    if(error < 0){
        ::close(sockfd);
        printf("node[%d] listen error\n", this->id);
        return 4;
    }
    this->listenfd_ = sockfd;
    create_file_event(sockfd, AE_READABLE | AE_WRITABLE, _ev_accept, this);
    printf("node[%d] listen success\n", this->id);
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
            printf("node[%d] connect socket error\n", this->id);
            return 1;
        }
        error = ::fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
        if (error < 0)
        {
            printf("node[%d] connect fcntl error\n", this->id);
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
            printf("node[%d] reconnect success\n", this->id);
            this->is_connect_ = true;
            Sendbuf::create(this->sockfd_);
            Recvbuf::create(this->sockfd_, 1024);
            create_file_event(this->sockfd_, AE_READABLE, _ev_readable, this);
            send_node_reg();
        } else
        {
            printf("node[%d] reconnect error(%d) errno(%d)\n", this->id, error, errno);
        }
    }
    return 0;
}

void Node::update(long long cur_tick)
{
    aeOnce(loop_);
    
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


void Node::recv(MsgHeader* header, const char* data, size_t size)
{
    //不可靠的消息传输
    switch(header->id)
    {
        case MSG_NODE_REG:
            {
                recv_node_reg(header, data, size);
            }
            break;
        case MSG_CREATE_ENTITY:
            {
                recv_create_entity(header, data, size);
            };
            break;
        default:
            {
                recv_entity_msg(header, data, size);
            }
            break;
    }
}

int Node::dispatch(char* data, size_t datalen)
{
    MsgHeader *header = (MsgHeader*)data;
    if (datalen < sizeof(header->len))
    {
        return 0;
    }
    if (datalen < header->len)
    {
        return 0;
    }
    char *body = data + sizeof(MsgHeader);
    int bodylen = header->len - sizeof(MsgHeader);
    recv(header, body, bodylen);
    return header->len;
}

void Node::forward_entity_msg(MsgHeader* header, const char* data, size_t size)
{
    Entity* entity = find_entity(header->dst_entityid);
    if (entity)
    {
        entity->recv(header, data, size);
        return;
    }
    if (is_disconnect())
    {
        return;
    }
    send((char *)&header, sizeof(header));
    send(data, size);
}

void Node::forward_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const char* data, size_t size)
{
    Node* src_node = src_entity->node;
    if (!src_node)
    {
        return;
    }
    static MsgHeader header;
    header.src_nodeid = src_node->get_id();
    header.src_entityid = src_entity->id;
    header.dst_entityid = dst_entityid;
    header.dst_nodeid = this->id;
    header.id = msgid;
    //先发给本地实体
    Entity* entity = find_entity(dst_entityid);
    if (entity)
    {
        entity->recv(&header, data, size);
        return;
    }
    if (is_disconnect())
    {
        src_entity->unreach(&header, data, size);
        return;
    }
    //发给关联节点
    send((char *)&header, sizeof(header));
    send(data, size);
}

void Node::recv_entity_msg(MsgHeader* header, const char* data, size_t size)
{
    int dst_entityid = header->dst_entityid;
    //广播 
    if (dst_entityid == 0)
    {
        for (int i = entity_vector_.size() - 1; i >= 0; i--)
        {
            Entity* entity = entity_vector_[i];
            entity->recv(header, data, size);
        }
    } else
    {

        Entity* entity = find_entity(dst_entityid);
        if(entity)
        {
            entity->recv(header, data, size);
        } else
        {
            //转发到中心节点
            Node* center_node = EntityRoute::center_node_;
            if (center_node == this)
            {
                return;
            }
            center_node->forward_entity_msg(header, data, size);
        }
    }
}

void Node::send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, ::google::protobuf::Message* msg)
{
    /*  
    printf("node[%d] send entity msg\n", id);
    Node* src_node = src_entity->node;
    if (!src_node)
    {
        return;
    }
    int msg_size = msg->ByteSize();
    static MsgHeader header;
    header.src_nodeid = src_node->get_id();
    header.src_entityid = src_entity->id;
    header.dst_entityid = dst_entityid;
    header.dst_nodeid = this->id;
    header.id = msgid;
    header.len = sizeof(MsgHeader) + msg_size;
    //发给本地实体
    Entity* entity = find_entity(dst_entityid);
    if (entity)
    {
    //    entity->recv(&header, data, size);
        return;
    } 
    if (is_disconnect())
    {
        printf("node[%d] is disconnect\n", get_id());
     //   src_entity->unreach(&header, data, size);
        return;
    }
    //插入到缓冲区
    char* buf= Sendbuf::alloc(this->sockfd_,  header.len);
    if (!buf)
    {
        return;
    }
    printf("node[%d] send %ld to sockfd(%d)\n", id, header.len, this->sockfd_);
    memcpy(buf, &header, sizeof(header));
    msg->SerializeToArray(buf + sizeof(header), msg_size);
    Sendbuf::flush(this->sockfd_, buf, header.len);
    create_file_event(this->sockfd_, AE_WRITABLE, _ev_writable, this);
    */
}

void Node::send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, Buffer* buffer)
{
    send_entity_msg(src_entity, dst_entityid, msgid, buffer->get_buffer(), buffer->size());
}


void Node::send_entity_msg(Entity* src_entity, int dst_entityid, int msgid, const char* data, size_t size)
{
    printf("node[%d] send entity msg\n", id);
    Node* src_node = src_entity->node;
    if (!src_node)
    {
        return;
    }
    static MsgHeader header;
    header.src_nodeid = src_node->get_id();
    header.src_entityid = src_entity->id;
    header.dst_entityid = dst_entityid;
    header.dst_nodeid = this->id;
    header.id = msgid;
    header.len = sizeof(MsgHeader) + size;
    //发给本地实体
    Entity* entity = find_entity(dst_entityid);
    if (entity)
    {
        entity->recv(&header, data, size);
        return;
    } 
    if (is_disconnect())
    {
        printf("node[%d] is disconnect\n", get_id());
        src_entity->unreach(&header, data, size);
        return;
    }
    //发送给自己的关联节点
    send((char *)&header, sizeof(header));
    send(data, size);
}

int Node::send(const char *data, size_t size)
{
    //插入到缓冲区
    char* buf= Sendbuf::alloc(sockfd_,  size);
    if (!buf)
    {
        return 0;
    }
    printf("node[%d] send %ld to sockfd(%d)\n", id, size, this->sockfd_);
    memcpy(buf, data, size);
    Sendbuf::flush(sockfd_, buf, size);
    create_file_event(this->sockfd_, AE_WRITABLE, _ev_writable, this);
    return size;
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

int Node::real_close(const char* err)
{
    return 0;
}

bool Node::is_disconnect()
{
    return !this->is_connect_;
}


void Node::recv_node_reg(MsgHeader* header, const char* data, size_t size)
{
    printf("node[%d] recv node reg\n", this->id);
}

void Node::send_node_reg()
{
    printf("node[%d] send node reg\n", this->id);
    static MsgHeader header;
    header.src_nodeid = this->id;
    header.src_entityid = 0;
    header.dst_entityid = 0;
    header.dst_nodeid = get_id();
    header.id = MSG_NODE_REG;
    header.len = sizeof(MsgHeader);
    send((char *)&header, sizeof(header));
}


void Node::recv_create_entity(MsgHeader* header, const char* data, size_t size)
{
    CreateEntityMsg* msg = (CreateEntityMsg*)data;
    printf("node[%d] recv create entity %s\n", this->id, msg->filepath);
    create_entity_local(msg->filepath);
}

void Node::create_entity_remote(Entity* src_entity, const char* filepath)
{
    printf("node[%d] send create entity %s\n", this->id, filepath);

    unsigned short str_len = strlen(filepath);
    Node* src_node = src_entity->node;

    static MsgHeader header;
    header.src_nodeid = src_node->id;
    header.src_entityid = src_entity->id;
    header.dst_entityid = 0;
    header.dst_nodeid = this->id;
    header.id = MSG_CREATE_ENTITY;
    header.len = sizeof(MsgHeader) + sizeof(str_len) + str_len + 1;
    
    CreateEntityMsg msg; 
    msg.len = str_len;
    memcpy(msg.filepath, filepath, str_len + 1);

    if (is_local())
    {
        recv_create_entity(&header, (const char *)&msg, sizeof(msg));
    } else
    {
        send((char *)&header, sizeof(header));
        send((char*)&msg, sizeof(msg));
    }
}


int Node::create_file_event(int fd, int mask, aeFileProc* proc, void* userdata)
{
    return aeCreateFileEvent(loop_, fd, mask, proc, userdata);
}

void Node::delete_file_event(int fd, int mask)
{
    aeDeleteFileEvent(loop_, fd, mask);
}


Entity* Node::create_entity_local(const char* filepath)
{
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
            printf("node[%d] create entity local error %s\n", this->id, lua_tostring(L, -1));
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
    lua_getglobal(L, "debug");  
    lua_getfield(L, -1, "traceback");  
    lua_pcall(L, 0, 1, 0);   
    const char* sz = lua_tostring(L, -1);  
    printf("%s\n", sz);
    return 0;
}


int Node::lua_pushfunction(const char *func)
{
    char *start = (char *)func;
    char *class_name = start;
    char *pfunc = start;
    while(*pfunc != 0)
    {
        if(*pfunc == '.' && class_name == start)
        {
            *pfunc = 0;
            lua_getglobal(L, class_name);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                return 1;
            }
            class_name = pfunc + 1;
        }else if(*pfunc == '.')
        {
            *pfunc = 0;
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            *pfunc = '.';
            if(lua_isnil(L, -1))
            {
                return 2;
            }
            lua_remove(L, -2);//弹出table
            class_name = pfunc + 1;
        }
        pfunc++;
    }
    if(class_name == start)
    {
        lua_getglobal(L, class_name);
        if(lua_isnil(L, -1))
        {
            return 3;
        }
    }else
    {
        lua_pushstring(L, class_name);
        lua_gettable(L, -2);
        if(lua_isnil(L, -1))
        {
            return 4;
        }
        lua_remove(L, -2);//弹出table
    }
    return 0;     
}

bool Node::lua_getvalue(const char *fieldname)
{
    static char fieldbuf[128];
    strcpy(fieldbuf, fieldname);
    char *start = (char *)fieldbuf;
    char *class_name = start;
    char *pfunc = start;
    while(*pfunc != 0)
    {
        if(*pfunc == '.' && class_name == start)
        {
            *pfunc = 0;
            lua_getglobal(L, class_name);
            *pfunc = '.';
            if(lua_isnil(L, -1)){
                lua_pop(L, 1);
                return false;
            }
            class_name = pfunc + 1;
        }else if(*pfunc == '.')
        {
            *pfunc = 0;
            lua_pushstring(L, class_name);
            lua_gettable(L, -2);
            *pfunc = '.';
            if(lua_isnil(L, -1))
            {
                lua_pop(L, 2);
                return false;
            }
            lua_remove(L, -2);//弹出table
            class_name = pfunc + 1;
        }
        pfunc++;
    }
    if(class_name == start)
    {
        lua_getglobal(L, class_name);
        if(lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            return false;
        }
        return (int64_t)lua_tonumber(L, -1);
    }else
    {
        lua_pushstring(L, class_name);
        lua_gettable(L, -2);
        if(lua_isnil(L, -1))
        {
            lua_pop(L, 2);
            return false;
        }
        lua_remove(L, -2);//弹出table
    }
    return true;
}

const char* Node::lua_getstring(const char *fieldname)
{
    if(!lua_getvalue(fieldname))
    {
        return NULL;
    }
    if(!lua_isstring(L, -1))
    {
        lua_pop(L, 1);
        return NULL;
    }
    const char* result = (const char*)lua_tostring(L, -1);
    lua_pop(L, 1);
    return result;
}

int64_t Node::lua_getnumber(const char *fieldname)
{
    if(!lua_getvalue(fieldname))
    {
        return 0;
    }
    if(!lua_isnumber(L, -1))
    {
        lua_pop(L, 1);
        return 0;
    }
    int64_t result = (int64_t)lua_tonumber(L, -1);
    lua_pop(L, 1);
    return result;
}

void Node::lua_reglib(int (*p)(lua_State* L))
{
    p(L);
}

int Node::lua_dofile(const char* filepath)
{
    if(luaL_dofile(L, filepath))
    {
        if (lua_isstring(L, -1))
        {
            printf("dofile error %s\n", lua_tostring(L, -1));
        }
    }
    return 0;
}

