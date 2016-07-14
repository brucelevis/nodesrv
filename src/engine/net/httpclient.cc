#include "net/httpclient.h"
#include "log/log.h"
extern "C" {
    #include "http_parser.h"
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>


#define CRLF2 "\r\n\r\n"
#define CRLF "\r\n"

typedef struct tagFrameHeader
{
    uint8_t opcode:4;
    uint8_t rsv:3;
    uint8_t fin:1;
    uint8_t payload_len:7;
    uint8_t mask:1;
}FrameHeader;


HttpClient::HttpClient()
{
    sockfd = -1;
    is_connect_ = false;
    timeout_sec = 60;
    content_length = 0;
}

HttpClient::~HttpClient()
{

}

bool HttpClient::connect(const char* host, unsigned short port)
{
    if (sockfd != -1)
    {
        LOG_ERROR("socket is connect already");
        return false;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);	
    if (sockfd < 0)
    {
        LOG_ERROR("create sock error");
        return false;
    }
    struct timeval tv;tv.tv_sec = timeout_sec; tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET,SO_RCVTIMEO, (char *)&tv,sizeof(tv));
    setsockopt(sockfd, SOL_SOCKET,SO_SNDTIMEO, (char *)&tv,sizeof(tv));
    int error;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;	
    if(inet_addr(host) != (in_addr_t)-1)
    {
        addr.sin_addr.s_addr = inet_addr(host);   
    }else
    {
        struct hostent *hostent;
        hostent = gethostbyname(host);
        if(hostent->h_addr_list[0] == NULL)
        {
            LOG_ERROR("connect fail %s", host);
            return false;
        }
        memcpy(&addr.sin_addr, (struct in_addr *)hostent->h_addr_list[0], sizeof(struct in_addr));
    } 
    addr.sin_port = htons(port);        
    error = ::connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(error < 0)
    {
        LOG_ERROR("connect fail errno:%d:%s\n", errno, strerror(errno));
        return false;
    }
    is_connect_ = true;
    return true;
}


bool HttpClient::send_open_websock()
{
    if(!is_connect())
    {
        LOG_ERROR("not connect");
        return false;
    }
    const char* data = "GET / HTTP/1.1\r\n"
        "Accept-Encoding: gzip, deflate, sdch\r\n"
        "Accept-Language: zh-CN,zh;q=0.8\r\n"
        "Connection: Upgrade\r\n"
        "Origin: null\r\n"
        "Pragma: no-cache\r\n"
        "Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits\r\n"
        "Sec-WebSocket-Key: pk4BUV3PuqJJWfAKyvIyaw==\r\n"
        "Sec-WebSocket-Version: 13\r\n"
        "Upgrade: websocket\r\n"
        "User-Agent: Mozilla/5.0\r\n\r\n"; 
    LOG_INFO("send open websock %d\n", strlen(data));
    uint32_t ir = ::send(sockfd, data, strlen(data), 0);
    if(ir < sizeof(data))
    {
        LOG_ERROR("send fail n(%d) error(%s)", ir, strerror(errno));
        return false;
    }
    return true;
}

void HttpClient::send(const char* val)
{
    if(!is_connect())
    {
        LOG_ERROR("not connect");
        return;
    }
    int datalen = strlen(val);
    int ir = ::send(sockfd, val, datalen, 0);
    if (ir != datalen)
    {
        LOG_ERROR("not sent ir(%d) datalen(%d)", ir, datalen);
        return;
    }
}

bool HttpClient::is_connect()
{
    return is_connect_;
}

bool HttpClient::recv()
{
    if(!is_connect())
    {
        LOG_ERROR("not connect");
        return false;
    }

    //接收header
    static char data[10240];
    uint32_t datalen = 0;
    uint32_t header_len = 0;
    for (int i = 0; i < 1000; i++)
    {
        int ir = ::recv(sockfd, data + datalen, sizeof(data) - datalen, 0);
        if (ir <= 0)
        {
            break;
        }
        //搜索\r\n\r\n
        for (uint32_t i = datalen; i < datalen + ir; i++)
        {
            if(strncmp(data + i, CRLF2, 4) == 0)
            {
                //找到
                header_len = i + 4;
                break;
            }
        }
        datalen += ir;
        if (header_len > 0)
        {
            break;
        }
        if (datalen >= sizeof(data))
        {
            break;
        }
    }
    if (header_len <= 0)
    {
        LOG_ERROR("header not found");
        return false;
    }
    LOG_DEBUG("header len %d", header_len);
    data[header_len] = 0;

    LOG_DEBUG(data);

    //处理header
    char* header_field = data;
    char* header_value = NULL;
    for (uint32_t i = 0; i < header_len; i++)
    {
        //寻找field
        if (header_value == NULL)
        {
            if (data[i] == ':' || data[i] == ' ')
            {
                uint32_t k = i + 1;
                for (; k < header_len; k++)
                {
                    if (data[k] != ':' && data[k] != ' ')
                    {
                        header_value = data + k;
                        break;
                    }
                }
                i = k + 1;
            }
        } else
        {
            if (data[i] == '\n')
            {
                char c = data[i - 1];
                data[i - 1] = 0;
                //printf("dddd %s\n", header_field);
                if (strncmp(header_field, "Content-Length", 14) == 0)
                {
                    content_length = atoi(header_value);
                }
                data[i - 1] = c;
                header_field = data + i + 1;
                header_value = NULL;
            }
        }
    }
    buffer.reset();
    if (content_length <= 0)
    {
        return true;
    }
    //剩余的数据
    if (datalen > header_len)
    {
        buffer.write_buf(data + header_len, datalen - header_len);
    }
    buffer.ensure_size(content_length);
    while(buffer.size() < content_length)
    {
        char* buf = buffer.get_write_buffer();
        int ir = ::recv(sockfd, buf, content_length - buffer.size(), 0);
        if (ir <= 0)
        {
            LOG_ERROR("recv error");
            return false;
        }
        buffer.write_buf(NULL, ir);
    }
    buffer.write_int8(0);
    LOG_DEBUG("body len %d", buffer.size());
    LOG_DEBUG("body %s", buffer.get_buffer());
    return true;
}


void HttpClient::close()
{
    if (!is_connect_)
    {
        return;
    }
    is_connect_ = false;
    ::close(sockfd);
    buffer.reset();
    content_length = 0;
}

bool HttpClient::send_binary_frame(Buffer* buffer)
{
    return send_frame(2, buffer->get_buffer(), buffer->size());
}

bool HttpClient::send_binary_frame(const void* data, unsigned short datalen)
{
    return send_frame(2, data, datalen);
}

//发送字符串帧
bool HttpClient::send_string_frame(const char* str)
{
    return send_frame(1, str, strlen(str) + 1);
}

//发送帧
bool HttpClient::send_frame(int opcode, const void* data, unsigned short datalen)
{
    if (!is_connect_)
    {
        LOG_ERROR("not connect");
        return false;
    }
    LOG_DEBUG("HttpClient.send_frame sid(%d) opcode(%d) datalen(%d)", opcode, datalen);
    //统一使用2字长长度
    FrameHeader header;
    header.fin = 1;//结束帧
    header.rsv = 0;
    header.opcode = opcode;
    header.mask = 0;//没有掩码
    if (datalen >= 126)
    {
        header.payload_len = 126;
        unsigned short real_len = htons(datalen);
        ::send(sockfd, &header, sizeof(header), 0);
        ::send(sockfd, &real_len, sizeof(real_len), 0);
        ::send(sockfd, data, datalen, 0);
    } else 
    {
        header.payload_len = datalen;
        ::send(sockfd, &header, sizeof(header), 0);
        ::send(sockfd, data, datalen, 0);
    }
    return true;
}


bool HttpClient::recv_frame()
{
    if(!is_connect())
    {
        LOG_ERROR("not connect");
        return false;
    }

    //接收header
    static char data[10240];
    uint32_t datalen = 0;
    uint32_t header_len = 0;
    uint64_t payload_len = 0;
    //掩码
    unsigned char *mask = 0;
    FrameHeader* frame_header = NULL;
    for (int i = 0; i < 1000; i++)
    {
        int ir = ::recv(sockfd, data + datalen, sizeof(data) - datalen, 0);
        LOG_DEBUG("real recv %d", ir);
        if (ir <= 0)
        {
            break;
        }
        datalen += ir;
        header_len = sizeof(FrameHeader);
        if (datalen < header_len)
        {
            continue;
        }
        frame_header = (FrameHeader*)data;
        payload_len = frame_header->payload_len;
        if (frame_header->payload_len == 126)
        {
            payload_len = *(uint16_t *)(data + sizeof(FrameHeader));
            header_len += 2;
        }
        else if (frame_header->payload_len == 127)
        {
            header_len += 8;
            payload_len = *(uint64_t *)(data + sizeof(FrameHeader));
        }
        if (frame_header->mask == 1)
        {
            mask = (unsigned char *)(data + header_len);
            header_len += 4;
        }
        if (datalen >= header_len)
        {
            break;
        }
        if (datalen >= sizeof(data))
        {
            LOG_ERROR("header too big");
            return false;
        }
    }
    LOG_DEBUG("payload_len %d", payload_len);
    if (frame_header == NULL)
    {
        return false;
    }
    buffer.reset();
    //剩余的数据
    if (datalen > header_len)
    {
        buffer.write_buf(data + header_len, datalen - header_len);
    }
    this->content_length = payload_len;
    buffer.ensure_size(content_length);
    while(buffer.size() < content_length)
    {
        char* buf = buffer.get_write_buffer();
        int ir = ::recv(sockfd, buf, content_length - buffer.size(), 0);
        if (ir <= 0)
        {
            LOG_ERROR("recv error");
            return false;
        }
        buffer.write_buf(NULL, ir);
    }
    char* payload_data = buffer.get_buffer();
    //用掩码修改数据
    if (frame_header->mask == 1)
    {
        for (uint64_t i = 0; i < payload_len; i++)
        {
            payload_data[i] = payload_data[i] ^ mask[i % 4];
        }
    }
    LOG_DEBUG("buffer len %d", buffer.size());
    return true;
}

