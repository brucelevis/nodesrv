#ifndef _HTTP_CLIENT_H_
#define _HTTP_CLIENT_H_
#include "container/buffer.h"

//tolua_begin
class HttpClient
{
    public:
        HttpClient();
        ~HttpClient();

        bool connect(const char* host, unsigned short port);
        bool is_connect();
        void send(const char* val);
        bool recv();
        bool recv_frame();
        void close();
        bool send_open_websock();
        bool send_binary_frame(Buffer* buffer);
        bool send_binary_frame(const void* data, unsigned short datalen);
        bool send_string_frame(const char* str);
        bool send_frame(int opcode, const void* data, unsigned short datalen);
    public:
        Buffer buffer;
        uint32_t content_length;
//tolua_end
    private:
        int sockfd;
        bool is_connect_;
        int timeout_sec;
//tolua_begin
};
//tolua_end

#endif
