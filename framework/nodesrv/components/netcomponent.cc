#include "netcomponent.h"

#include "entity/entity.h"
#include "node/node.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"

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


IMPLEMENT(NetComponent)

static void _ev_accept(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    NetComponent* self = (NetComponent*)clientData;
    self->ev_accept(sockfd);
}

static void _ev_writable(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    NetComponent* self = (NetComponent*)clientData;
    self->ev_writable(sockfd);
}

static void _ev_readable(struct aeEventLoop *eventLoop, int sockfd, void *clientData, int mask)
{
    NetComponent* self = (NetComponent*)clientData;
    self->ev_readable(sockfd);
}



NetComponent::NetComponent():Component()
{
    sockfd_ = -1;
    is_connect_ = false;
}

NetComponent::~NetComponent()
{

}


void NetComponent::update(long long cur_tick)
{
    Component::update(cur_tick);
    if (!this->is_connect_ && this->ip_[0])
    {
        real_connect();
    }
}


int NetComponent::connect(int sockfd)
{
    if (this->sockfd_ != -1)
    {
        return 1;
    }
    this->sockfd_ = sockfd;
    this->is_connect_ = true;
    Sendbuf::create(this->sockfd_);
    Recvbuf::create(this->sockfd_, 1024);
    this->create_file_event(this->sockfd_, AE_READABLE, _ev_readable, this);
    return 0;
}

int NetComponent::listen(const char* host, unsigned short port)
{
    int error;
    int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket error\n");
        return 1;
    }
    error = fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    if (error < 0)
    {
        printf("fcntl error\n");
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
        printf("bind error\n");
		return 3;	
    }
	error = ::listen(sockfd, 5);	
    if(error < 0){
        ::close(sockfd);
        printf("listen error\n");
        return 4;
    }
    this->sockfd_ = sockfd;
    this->create_file_event(this->sockfd_, AE_READABLE | AE_WRITABLE, _ev_accept, this);
    printf("listen success\n");
    return 0;
}

int NetComponent::connect(const char* host, unsigned short port)
{
    strcpy(this->ip_, host);
    this->port_ = port;
    return 0;
}

int NetComponent::real_connect()
{
    int error;
    if (this->is_connect_)
    {
        return 0;
    }
    if (this->sockfd_ == -1)
    {
        int sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            printf("connect socket error\n");
            return 1;
        }
        error = ::fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
        if (error < 0)
        {
            printf("connect fcntl error\n");
            ::close(sockfd);
            return 2;
        }
        this->sockfd_ = sockfd;
    }
    if (this->sockfd_ != -1)
    {
        int sockfd = this->sockfd_;
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
        error = ::connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if ((error == 0) || (error < 0 && errno == EISCONN))
        {
            printf("NetComponent connect success\n");
            this->is_connect_ = true;
            Sendbuf::create(this->sockfd_);
            Recvbuf::create(this->sockfd_, 1024);
            create_file_event(this->sockfd_, AE_READABLE, _ev_readable, this);
        } else 
        {
            printf("connect connect error %s\n", strerror(errno));
        }
    }
    return 0;
}

void NetComponent::ev_writable(int sockfd)
{
    printf("netcomponent ev_writable\n");
    //发送数据
    for(;;)
    {
        int datalen = Sendbuf::datalen(sockfd_);
        if (datalen <= 0)
        {
            printf("netcomponent  delete write event\n");
            this->delete_file_event(this->sockfd_, AE_WRITABLE);
            break;
        }
        char* buf = Sendbuf::get_read_ptr(sockfd_);
        int ir = ::send(sockfd_, buf, datalen, 0);
        printf("netcomponent real send %d\n", ir);
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


void NetComponent::ev_readable(int sockfd)
{
    printf("netcomponent ev_readable\n");
    //接收数据
    for(;;)
    {
        char* wptr= Recvbuf::getwptr(sockfd);
        int buflen = Recvbuf::bufremain(sockfd);
        int ir = ::recv(sockfd, wptr, buflen, 0);
        printf("netcomponent real recv %d\n", ir);
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

int NetComponent::dispatch(char* data, size_t datalen)
{
    static struct FileHeader
    {
        unsigned int len;
    } file_header; 
    file_header = *(FileHeader*)data;
    if (datalen < sizeof(file_header.len))
    {
        return 0;
    }
    if (datalen < file_header.len)
    {
        return 0;
    }
    char *body = data + sizeof(FileHeader);
    size_t bodylen = file_header.len - sizeof(FileHeader);

    static MsgHeader header;
    header.src_nodeid = 0;
    header.src_entityid = 0;
    header.dst_entityid = 0;
    header.dst_nodeid = 0;
    header.id = MSG_SEND;
    header.len = sizeof(MsgHeader) + bodylen;

    this->entity->recv(&header, (const char*)body, bodylen);

    return file_header.len;
}


void NetComponent::ev_accept(int listenfd)
{
    int sockfd;	
    int error;
    struct sockaddr_in addr;	
    socklen_t addrlen = sizeof(addr);	
    sockfd = ::accept(this->sockfd_, (struct sockaddr*)&addr, &addrlen);
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
    //this->create_file_event(sockfd, AE_READABLE, _ev_readable, this);
}


void NetComponent::real_close(const char* reason)
{

}

int NetComponent::send(const char *data, size_t size)
{
    //插入到缓冲区
    char* buf= Sendbuf::alloc(sockfd_,  size);
    if (!buf)
    {
        return 0;
    }
    printf("entity[%d] send %ld to sockfd(%d)\n", this->entity->id, size, this->sockfd_);
    memcpy(buf, data, size);
    Sendbuf::flush(sockfd_, buf, size);
    create_file_event(this->sockfd_, AE_WRITABLE, _ev_writable, this);
    return size;
}
