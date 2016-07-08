#include "container/buffer.h"
#include "log/log.h"
#include <memory.h>
#include <stdlib.h>

Buffer* Buffer::instance_;

#define INIT_SIZE 1024

Buffer::Buffer(uint32_t init_size)
{
    this->buf = 0;
    this->buflen = 0;
    this->rptr = this->wptr = 0;
    this->use_extern_buf = false;
    expand_buf(init_size);
}

Buffer::Buffer(const void* buf, uint32_t buflen)
{
    this->buf = (char*)buf;
    this->buflen = buflen;
    this->rptr = this->wptr = 0;
    this->use_extern_buf = true;
}

Buffer::Buffer()
{
    this->buf = 0;
    this->buflen = 0;
    this->rptr = this->wptr = 0;
    this->use_extern_buf = false;
}

Buffer::~Buffer()
{
    if(this->buf != NULL)
    {
        free(this->buf);
    }
}

uint32_t Buffer::size()
{
    return this->wptr - this->rptr;
}

int Buffer::read_buf(void *data, uint32_t datalen)
{
    if (this->size() < datalen)
    {
        return 0;
    }
    if (data != 0)
    {
        memcpy(data, this->buf + this->rptr, datalen);
    }
    this->rptr += datalen;
    return datalen;
}

int Buffer::write_buf(const void* data, uint32_t datalen)
{
    if (this->wptr + datalen >= this->buflen)
    {
        expand_buf((this->buflen + datalen) * 2);
    }
    if (this->wptr >= this->buflen)
    {
        return 0;
    }
    if (data != 0)
    {
        memcpy(this->buf + this->wptr, data, datalen);
    }
    this->wptr += datalen;
    return 0;
}

void Buffer::buf2line()
{
    int size = this->wptr - this->rptr;
    if (size && this->rptr > 0)
    {
        memmove(this->buf, this->buf + this->rptr, size);
        this->rptr = 0;
        this->wptr = size;
    }
}

int Buffer::expand_buf(uint32_t newsize)
{
    if (this->use_extern_buf)
    {
        return 1;
    }
    //LOG_DEBUG("expand buf %d", newsize);
    if (this->buf == 0)
    {
        uint32_t newbuflen = newsize;
        char* newbuf = (char*)malloc(newbuflen);
        if (newbuf == NULL)
        {
            return 1;
        }
        this->buf = newbuf;
        this->buflen = newbuflen;
     //   LOG_DEBUG("new expand buf %d", newsize);
    } else 
    {
        uint32_t newbuflen = newsize;
        char* newbuf = (char*)realloc(this->buf, newbuflen);
        if (newbuf == NULL)
        {
            return 1;
        }
        this->buf = newbuf;
        this->buflen = newbuflen;
    }
    return 0;
}

void Buffer::reset()
{
    this->rptr = this->wptr = 0;
}


int64_t Buffer::read_int64(int64_t def)
{
    int64_t val = 0;    
    if(sizeof(val) == this->read_buf(&val, sizeof(val)))
    {
        return val;
    }
    return def;
}

int32_t Buffer::read_int32(int32_t def)
{
    int32_t val = 0;    
    if(sizeof(val) == this->read_buf(&val, sizeof(val)))
    {
        return val;
    }
    return def;
}

int16_t Buffer::read_int16(int16_t def)
{
    int16_t val = 0;    
    if(sizeof(val) == this->read_buf(&val, sizeof(val)))
    {
        return val;
    }
    return def;
}

int8_t Buffer::read_int8(int8_t def)
{
    int8_t val = 0;    
    if(sizeof(val) == this->read_buf(&val, sizeof(val)))
    {
        return val;
    }
    return def;
}


int Buffer::write_utf8(const char* str, uint16_t str_len)
{
    int ir = write_int16(str_len);
    ir += write_buf(str, str_len);
    return ir;
}

int Buffer::write_int64(int64_t val)
{
    return write_buf(&val, sizeof(val)); 
}

int Buffer::write_int32(int32_t val)
{
    return write_buf(&val, sizeof(val)); 
}

int Buffer::write_int16(int16_t val)
{
    return write_buf(&val, sizeof(val)); 
}

int Buffer::write_int8(int8_t val)
{
    return write_buf(&val, sizeof(val)); 
}

Buffer* Buffer::temp()
{
    if(instance_ == NULL)
    {
        instance_ = new Buffer();
    }
    instance_->reset();
    return instance_;
}

const char* Buffer::get_buffer()
{
    return this->buf + this->rptr;
}


uint32_t Buffer::maxsize()
{
    return this->buflen;
}

uint32_t Buffer::already_read()
{
    return this->rptr;
}
