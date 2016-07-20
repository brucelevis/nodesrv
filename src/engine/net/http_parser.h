#ifndef _HTTP_PARSER_H_
#define _HTTP_PARSER_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct frame_header
{
    uint8_t opcode:4;
    uint8_t rsv:3;
    uint8_t fin:1;
    uint8_t payload_len:7;
    uint8_t mask:1;
}frame_header;

typedef struct http_frame_request
{
    uint64_t payload_len;
    char* payload;
    uint32_t header_len;
    uint64_t frame_len;
    frame_header header;
}http_frame_request;

typedef struct http_string
{
    char* buf;
    size_t len;
}http_string;

typedef struct http_header
{
    http_string field; 
    http_string value;
}http_header;

#define MAX_HTTP_HEADER_COUNT 32
#define MAX_HTTP_GET_COUNT 32
#define MAX_HTTP_POST_COUNT 32
#define MAX_HTTP_COOKIE_COUNT 32
typedef struct http_request
{
    uint32_t content_length;
    bool is_upgrade;
    http_header headers[MAX_HTTP_HEADER_COUNT];
    unsigned char header_count;
    http_string url; 
    http_string query_string; 
    http_string body;
    http_string method;
    http_header get[MAX_HTTP_GET_COUNT];
    unsigned char get_count;
    http_header post[MAX_HTTP_POST_COUNT];
    unsigned char post_count;
    http_header cookie[MAX_HTTP_COOKIE_COUNT];
    unsigned char cookie_count;
}http_request;

int http_parse(http_request& request, char* data, int datalen, uint32_t header_len);

//分析post参数
int http_post_parse(http_request& request, char* data, uint32_t datalen);

int http_frame_parse(http_frame_request& frame, char* data, size_t datalen);
#endif
