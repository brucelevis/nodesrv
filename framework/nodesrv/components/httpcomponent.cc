#include "httpcomponent.h"

#include "entity/entity.h"
#include "node/node.h"
#include "net/sendbuf.h"
#include "net/recvbuf.h"
#include "encrypt/base64.h"
#include "encrypt/sha1.h"
#include "encrypt/md5.h"
extern "C" {
    #include "http_parser.h"
}

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

IMPLEMENT(HttpComponent)

HttpComponent::HttpComponent():Component()
{

}

HttpComponent::~HttpComponent()
{

}
        
int HttpComponent::recv(MsgHeader* header, const void* data, size_t datalen)
{
    switch(header->id)
    {
        case MSG_NEW_CONNECTION:
            {
                return recv_new_connection(header, data, datalen);
            }
            break;
        case MSG_NET_RAW_DATA:
            {
                return recv_net_raw_data(header, data, datalen);
            }
            break;
    }
    return 0;
}

static int on_message_begin(http_parser *p)
{
    printf("on_message_begin\n");
    return 0;
}

static int on_headers_complete(http_parser *p)
{
    printf("on_headers_complete\n");
    return 0;
}
static int on_message_complete(http_parser *p)
{
    printf("on_message_complete\n");
    return 0;
}
static int on_chunk_complete(http_parser *p)
{
    printf("on_chunk_complete\n");
    return 0;
}
static int on_chunk_header(http_parser *p)
{
    printf("on_chunk_header\n");
    return 0;
}

static int on_header_field(http_parser *p, const char *buf, size_t len)
{
    printf("on_header_field\n");
    http_request* request = (http_request *)p->data;
    if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    {
        return 1;
    }
    request->headers[request->header_count].field.buf = buf;
    request->headers[request->header_count].field.len = len;
    return 0;
}
static int on_header_value(http_parser *p, const char *buf, size_t len)
{
    printf("on_header_value\n");
    http_request* request = (http_request *)p->data;
    if (request->header_count >= MAX_HTTP_HEADER_COUNT) 
    {
        return 1;
    }
    request->headers[request->header_count].value.buf = buf;
    request->headers[request->header_count].value.len = len;
    request->header_count++;
    return 0;
}
static int on_url(http_parser *p, const char *buf, size_t len)
{
    printf("on_url\n");
    http_request* request = (http_request *)p->data;
    request->url.buf = buf;
    request->url.len = len;
    return 0;
}
static int on_status(http_parser *p, const char *buf, size_t len)
{
    printf("on_status\n");
    return 0;
}
static int on_body(http_parser *p, const char *buf, size_t len)
{
    printf("on_body\n");
    http_request* request = (http_request *)p->data;
    request->body.buf = buf;
    request->body.len = len;
    return 0;
}

int HttpComponent::recv_new_connection(MsgHeader* header, const void* data, size_t datalen)
{
    int sockfd = *(int*)data;
    printf("new connection %d\n", sockfd);
    return 0;
}

int HttpComponent::recv_net_raw_data(MsgHeader* header, const void* data, size_t datalen)
{
    http_parser_settings settings;
    settings.on_message_begin = on_message_begin;
    settings.on_header_field = on_header_field;
    settings.on_header_value = on_header_value;
    settings.on_url = on_url;
    settings.on_status = on_status;
    settings.on_body = on_body;
    settings.on_headers_complete = on_headers_complete;
    settings.on_message_complete = on_message_complete;
    settings.on_chunk_header = on_chunk_header;
    settings.on_chunk_complete = on_chunk_complete;
    //http_parser parser;
    http_parser parser;
    http_parser_init(&parser, HTTP_REQUEST);

    http_request request;
    memset(&request, 0, sizeof(request));
    parser.data = &request;

    size_t parsed = http_parser_execute(&parser, &settings, (const char*)data, datalen);
    //static const char* aa = "GET";
    //size_t parsed = http_parser_execute(&parser, &settings, (const char*)aa, 3);
    /*  
     *  Start up / continue the parser.
     *  Note we pass recved==0 to signal that EOF has been received.
     */
    //printf("parsed %d nread %d\n", parsed, parser.nread);
    if(parsed != datalen)
    {
        /*  Handle error. Usually just close the connection. */ 
        return datalen;
    }
    else if (parser.upgrade)
    {
        /*  handle new protocol */ 
        //printf("handle new proto %s\n", data);
        for (int i = 0; i < request.header_count; i++)
        {
            http_header* header = &request.headers[i];
            if(strncmp(header->field.buf, "Sec-WebSocket-Key", header->field.len))
            {
                continue;
            }

            //printf("Sec-WebSocket-Key: %s", header->value.buf);

            static unsigned char sha1_out[20];
            static unsigned char sec_websocket_key[128];
            static char sec_websocket_accept[128];
            static char datestr[128];

            SHA1_CTX context; 
            SHA1Init(&context); 
            //计算sha1
            memcpy(sec_websocket_key, header->value.buf, header->value.len);
            sec_websocket_key[header->value.len] = 0;
            strcat((char*)sec_websocket_key, "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
            SHA1Update(&context, sec_websocket_key, strlen((char *)sec_websocket_key)); 
            SHA1Final(sha1_out, &context); 

            //计算base64
            base64_encode(sha1_out, sizeof(sha1_out), sec_websocket_accept);

           // 计算日期
            time_t t = time(NULL);
            struct tm* tmp = localtime(&t);
            strftime(datestr, sizeof(datestr), "Date:%a, %d %b %Y %H:%M:%S GMT\r\n", tmp);

            //printf("Sec-WebSocket-Accept: %s\n", sec_websocket_accept);

            net_component->send_str(sockfd, "HTTP/1.1 101 Switching Protocols\r\n"
                         "Connection:Upgrade\r\n"
                         "Server:lujingwei002@qq.com\r\n"
                         "Upgrade:WebSocket\r\n"
                         "Access-Control-Allow-Credentials:true\r\n"
                         "Access-Control-Allow-Headers:content-type\r\n");
            net_component->send_str(sockfd, datestr);
            net_component->send_str(sockfd, "Sec-WebSocket-Accept:");
            net_component->send_str(sockfd, sec_websocket_accept);
            net_component->send_str(sockfd, "\r\n\r\n");
            //session->had_shake = 1;
        }
        return datalen;
    } else
    {
        return datalen;
    }
    //printf("datalen %d %s\n", datalen, data);
}


void HttpComponent::awake()
{
    this->net_component = (NetComponent*)this->entity->get_component("NetComponent");
    this->entity->reg_msg(MSG_NEW_CONNECTION, this);
    this->entity->reg_msg(MSG_NET_RAW_DATA, this);
}

