#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdint.h>
//tolua_begin
class Buffer
{
    public:
        Buffer();
        Buffer(uint32_t init_size);
        ~Buffer();

        int64_t read_int64(int64_t def = 0);
        int32_t read_int32(int32_t def = 0);
        int16_t read_int16(int16_t def = 0);
        int8_t read_int8(int8_t def = 0);
        int read_buf(void* data, uint32_t datalen);

        int write_utf8(const char* str, uint16_t str_len);
        int write_int64(int64_t val);
        int write_int32(int32_t val);
        int write_int16(int16_t val);
        int write_int8(int8_t val);
        int write_buf(const void* data, uint32_t datalen);

        uint32_t size();
        void reset();
        const char* get_buffer();
    public:
        static Buffer* temp();
//tolua_end
    private:
        int expand_buf(uint32_t newsize = 0);

    private:
        char* buf;
        uint32_t buflen;
        uint32_t rptr;
        uint32_t wptr;
        static Buffer* instance_;
};//tolua_export

#endif
