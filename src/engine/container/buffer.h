#ifndef __BUFFER_H__
#define __BUFFER_H__
#include <google/protobuf/message.h>
#include <google/protobuf/dynamic_message.h>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include <stdint.h>
//tolua_begin
class Buffer
{
    public:
        Buffer();
        Buffer(uint32_t init_size);
        Buffer(const void* buf, uint32_t buflen);
        ~Buffer();

        int64_t read_int64(int64_t def = 0);
        int32_t read_int32(int32_t def = 0);
        int16_t read_int16(int16_t def = 0);
        int8_t read_int8(int8_t def = 0);
        int read_buf(void* data, uint32_t datalen);
        const char* read_utf8();
        int read_protobuf(lua_State* L);

        int write_utf8(const char* str, uint16_t str_len);
        int write_utf8(const char* str);
        int write_int64(int64_t val);
        int write_int32(int32_t val);
        int write_int16(int16_t val);
        int write_int8(int8_t val);
        int write_buf(const void* data, uint32_t datalen);
        int write(const Buffer* other);

        void buf2line();
        uint32_t already_read();
        uint32_t size() const;
        uint32_t maxsize();
        void reset();
        char* get_buffer() const;
        char* get_write_buffer() const;

        bool ensure_size(int size);
        void debug();
    public:
        static Buffer* temp();
//tolua_end
    public:
        const Buffer& operator=(const Buffer& other);
    private:
        Buffer(const Buffer& other);
        bool expand_buf(uint32_t newsize = 0);

    private:
        char* buf;
        uint32_t buflen;
        uint32_t rptr;//读指针
        uint32_t wptr;//写指针
        bool use_extern_buf;
        static Buffer* instance_;
};//tolua_export

#endif
