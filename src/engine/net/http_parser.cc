#include "http_parser.h"
#include "log/log.h"
#include "net/http.h"
#include <arpa/inet.h>

int http_frame_parse(http_frame_request& frame, char* data, size_t datalen)
{
    frame.header_len = 0;
    frame.payload_len = 0;
    frame.frame_len = 0;
    if(datalen < sizeof(frame_header))
    {
        return 0;
    }
    frame_header* header = (frame_header*)data;
    LOG_DEBUG("fin(%d) rsv(%d) mask(%d) opcode(%d) payload_len(%d)", header->fin, header->rsv, header->mask, header->opcode, header->payload_len);

    uint64_t real_header_len = sizeof(frame_header);
    uint64_t real_payload_len = header->payload_len;
    uint64_t real_frame_len = 0;
    //掩码
    unsigned char *mask = 0;
    //负载
    char *payload_data = 0;
    if (header->payload_len == 126)
    {
        real_header_len = sizeof(frame_header) + 2;
    }
    else if (header->payload_len == 127)
    {
        real_header_len = sizeof(frame_header) + 8;
    }
    if (header->mask == 1)
    {
        mask = (unsigned char *)data + real_header_len;
        real_header_len += 4;
    }
    //负载
    payload_data = (char *)data + real_header_len;

    //测试数据长度
    if (datalen < real_header_len)
    {
        return 0;
    }

    //解释负载长度
    if (header->payload_len == 126)
    {
        //2个字节的长度
        real_payload_len = ntohs(*((uint16_t*)(data + sizeof(frame_header))));
    }
    else if (header->payload_len == 127)
    {
        real_payload_len = ntohl(*((uint64_t*)(data + sizeof(frame_header))));
    }
    real_frame_len = real_header_len + real_payload_len;
    //测试数据长度
    if (datalen < real_frame_len)
    {
        return 0;
    }
    LOG_DEBUG("real_payload_len(%ld)", real_payload_len);
    //用掩码修改数据
    if (header->mask == 1)
    {
        for (uint64_t i = 0; i < real_payload_len; i++)
        {
            payload_data[i] = payload_data[i] ^ mask[i % 4];
        }
    }
    frame.header = *header;
    frame.payload_len = real_payload_len;
    frame.header_len = real_header_len;
    frame.frame_len = real_frame_len;
    frame.payload = payload_data;
    return 0;
}

int http_parse(http_request& request, char* data, int datalen, uint32_t header_len)
{
    request.content_length = 0;
    request.is_upgrade = false;
    //抽出消息头
    request.header_count = 0;
    char* header_field = data;
    char* header_value = NULL;
    for (uint32_t i = 0; i < header_len; i++)
    {
        //寻找field
        if (header_value == NULL)
        {
            if (data[i] == ':' || data[i] == ' ')
            {
                request.headers[request.header_count].field.buf = header_field;
                request.headers[request.header_count].field.len = data + i - header_field;
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
            if (data[i] == '\r')
            {
                request.headers[request.header_count].value.buf = header_value;
                request.headers[request.header_count].value.len = data + i - header_value;
                request.header_count++;
                if (request.header_count >= MAX_HTTP_HEADER_COUNT)
                {
                    break;
                }
                header_field = data + i + 2;
                header_value = NULL;
            }
        }
    }
    //分析header
    request.cookie_count = 0;
    for (int i = 0; i < request.header_count; i++)
    {
        http_header& header = request.headers[i];

        char c1 = header.value.buf[header.value.len];
        header.value.buf[header.value.len] = 0;
        char c2 = header.field.buf[header.field.len];
        header.field.buf[header.field.len] = 0;

        LOG_MSG("header key %s", header.field.buf);
        LOG_MSG("header value %s", header.value.buf);
        if(strncmp(header.field.buf, "Content-Length", 14) == 0)
        {
            request.content_length = atoi(header.value.buf);
        }
        if(strcmp(header.field.buf, "Upgrade") == 0)
        {
            LOG_DEBUG("Upgrade");
            request.is_upgrade = 1;
        }
        if(strcmp(header.field.buf, "Cookie") ==  0)
        {
            request.cookie[request.cookie_count].field.buf = header.value.buf;
            for(uint32_t i = 0; i < header.value.len; i++)
            {
                if(header.value.buf[i] == '=')
                {
                    request.cookie[request.cookie_count].field.len = header.value.buf + i - request.cookie[request.cookie_count].field.buf;;
                    request.cookie[request.cookie_count].value.buf = header.value.buf + i + 1;
                }
                if(header.value.buf[i] == ';')
                {
                    request.cookie[request.cookie_count].value.len = header.value.buf + i - request.cookie[request.cookie_count].value.buf;;
                    request.cookie_count++;
                    if (request.cookie_count >= MAX_HTTP_COOKIE_COUNT)
                    {
                        break;
                    }
                    request.cookie[request.cookie_count].field.buf = header.value.buf + i + 2;
                }
                if(i == header.value.len - 1)
                {
                    request.cookie[request.cookie_count].value.len = header.value.buf + i + 1 - request.cookie[request.cookie_count].value.buf;;
                    request.cookie_count++;
                }
            }
        }
        if(i == 0)
        {
            request.method.buf = header.field.buf;
            request.method.len = header.field.len;

            request.url.buf = header.value.buf;
            request.query_string.len = 0;
            bool has_query_string = false;
            for(uint32_t k = 0; k < header.value.len; k++)
            {
                if (header.value.buf[k] == '?')
                {
                    request.url.len = k;
                    request.query_string.buf = header.value.buf + k + 1;
                    has_query_string = true;
                }
                if (header.value.buf[k] == ' ')
                {
                    if (has_query_string)
                    {
                        request.query_string.len = header.value.buf + k - request.query_string.buf;
                    } else 
                    {
                        request.url.len = k;
                    }
                }
            }
        }
        header.value.buf[header.value.len] = c1;
        header.field.buf[header.field.len] = c2;
    }
    //分析header
    //GET协议
    request.get_count = 0;
    request.get[request.get_count].field.buf = request.query_string.buf;
    for(uint32_t i = 0; i < request.query_string.len; i++)
    {
        if(request.query_string.buf[i] == '=')
        {
            request.get[request.get_count].field.len = request.query_string.buf + i - request.get[request.get_count].field.buf;;
            request.get[request.get_count].value.buf = request.query_string.buf + i + 1;
        }
        if(request.query_string.buf[i] == '&')
        {
            request.get[request.get_count].value.len = request.query_string.buf + i - request.get[request.get_count].value.buf;;
            request.get_count++;
            if (request.get_count >= MAX_HTTP_GET_COUNT)
            {
                break;
            }
            request.get[request.get_count].field.buf = request.query_string.buf + i + 1;
        }
        if(i == request.query_string.len - 1)
        {
            request.get[request.get_count].value.len = request.query_string.buf + i + 1 - request.get[request.get_count].value.buf;;
            request.get_count++;
        }
    }
    for (int i = 0; i < request.get_count; i++)
    {
        http_header& get = request.get[i];
        get.field.len = Http::urldecode(get.field.buf, get.field.len, get.field.buf, get.field.len);
        get.value.len = Http::urldecode(get.value.buf, get.value.len, get.value.buf, get.value.len);
    }
    //POST协议
    request.post_count = 0;
    request.body.buf = data + header_len;
    request.body.len = datalen - header_len;
    return 0;
}

int http_post_parse(http_request& request, char* data, uint32_t datalen)
{
    //POST协议
    request.post_count = 0;
    if (strncmp(request.method.buf, "POST", 4))
    {
        return 0;
    }
    request.post[request.post_count].field.buf = data;
    for(uint32_t i = 0; i < datalen; i++)
    {
        if(data[i] == '=')
        {
            request.post[request.post_count].field.len = data + i - request.post[request.post_count].field.buf;;
            request.post[request.post_count].value.buf = data + i + 1;
        }
        if(data[i] == '&')
        {
            request.post[request.post_count].value.len = data + i - request.post[request.post_count].value.buf;;
            request.post_count++;
            if (request.post_count >= MAX_HTTP_POST_COUNT)
            {
                break;
            }
            request.post[request.post_count].field.buf = data + i + 1;
        }
        if(i == datalen - 1)
        {
            request.post[request.post_count].value.len = data + i + 1 - request.post[request.post_count].value.buf;;
            request.post_count++;
        }
    }
    for (int i = 0; i < request.post_count; i++)
    {
        http_header& post = request.post[i];
        post.field.len = Http::urldecode(post.field.buf, post.field.len, post.field.buf, post.field.len);
        post.value.len = Http::urldecode(post.value.buf, post.value.len, post.value.buf, post.value.len);
    }
    return 0;
}


