#include "container/buffer.h"
#include "lualib/pblua/pblua.h"
#include "log/log.h"
#include <memory.h>
#include <stdlib.h>

Buffer* Buffer::instance_;

#define INIT_SIZE 1024

Buffer::Buffer(const Buffer& other)
{
}

const Buffer& Buffer::operator=(const Buffer& other)
{
    write_buf(other.get_buffer(), other.size());
    return *this;
}

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
    if (use_extern_buf) 
    {
        if(this->buf != NULL)
        {
            free(this->buf);
        }
    }
}

int Buffer::write(const Buffer* other)
{
    return write_buf(other->get_buffer(), other->size());
}

uint32_t Buffer::size() const
{
    return this->wptr - this->rptr;
}


const char* Buffer::read_utf8()
{
    static char str[10240];
    int16_t str_len = read_int16();
    if (str_len + 1 >= (int16_t)sizeof(str))
    {
        LOG_ERROR("str too long %d", str_len);
        read_buf(NULL, str_len);
        return NULL;
    }
    read_buf(str, str_len);
    str[str_len] = 0;
    return str;
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

bool Buffer::ensure_size(int datalen)
{
    if (this->wptr + datalen < this->buflen)
    {
        return true;
    }
    return expand_buf(this->buflen + datalen);
}

int Buffer::write_buf(const void* data, uint32_t datalen)
{
    if (this->wptr + datalen >= this->buflen)
    {
        expand_buf((this->buflen + datalen) * 2);
    }
    if (this->wptr >= this->buflen)
    {
        LOG_ERROR("money limit");
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

bool Buffer::expand_buf(uint32_t newsize)
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


int Buffer::write_utf8(const char* str)
{
    uint16_t str_len = strlen(str);
    this->write_utf8(str, str_len);
    return sizeof(uint16_t) + str_len;
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

char* Buffer::get_write_buffer() const
{
    return this->buf + this->wptr;
}

char* Buffer::get_buffer() const
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

void Buffer::debug()
{
    LOG_DEBUG("buf = > wptr");
    for(uint32_t i = 0; i < this->wptr; i++)
    {
        printf("%d\n", this->buf[i]);
    }
    LOG_DEBUG("rptr = > wptr");
    for(uint32_t i = this->rptr; i < this->wptr; i++)
    {
        printf("%d\n", this->buf[i]);
    }
}


int Buffer::read_protobuf(lua_State* L)
{
    if (!lua_isstring(L, 2))
    {
        return 0;
    }
    if (!lua_isnumber(L, 3))
    {
        return 0;
    }

    const char* msg_name = (const char*)lua_tostring(L, 2);
    int msg_len = (int)lua_tonumber(L, 3);

    google::protobuf::Message* message = pblua_load_msg(msg_name);
    if(message == NULL)
    {
        LOG_ERROR("can not load msg %s", msg_name);
        return 0;
    }
    char* buf = this->buf + this->rptr;
    google::protobuf::io::ArrayInputStream stream(buf, msg_len);
    if(message->ParseFromZeroCopyStream(&stream) == 0)
    {
        LOG_ERROR("parse fail %s\n", msg_name);
        return 0;
    }    
    LuaMessage *message_lua = (LuaMessage *)lua_newuserdata(L, sizeof(LuaMessage));
    if(message_lua == NULL)
    {
        LOG_ERROR("newuserdata null %s", msg_name);
        return 0;
    }
    this->read_buf(NULL, msg_len);
    message_lua->message = message;
    message_lua->root_message = message_lua;
    message_lua->dirty = 0;
    luaL_getmetatable(L, "LuaMessage");
    lua_setmetatable(L, -2);
    return 1;
}


int Buffer::write_protobuf(lua_State* L)
{
    if (!lua_isuserdata(L, 2))
    {
        LOG_ERROR("arg error");
        return 0;
    }
    LuaMessage *message_lua = (LuaMessage *)luaL_checkudata(L, 2, "LuaMessage");
    if(message_lua == NULL)
    {
        LOG_ERROR("checkuserdata is null");
        return 0;
    }
    google::protobuf::Message *message = message_lua->message;
    const char *msg_name = message->GetDescriptor()->full_name().data();
    if(message == NULL)
    {
        LOG_ERROR("message is null");
        return 0;
    }

    int msgdata_len = message->ByteSize();
    if (!this->ensure_size(msgdata_len))
    {
        LOG_ERROR("memory limit");
        return 0;
    }
    char* buf = this->get_write_buffer();
    char * buf_end = (char *)message->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
    int real_len = buf_end - buf;
    if(real_len != msgdata_len)
    {
        LOG_ERROR("serialize fail %d/%d msg_name:%s\n", buf_end - buf, msgdata_len, msg_name);
        return 0;
    }
    this->write_buf(NULL, real_len);
    lua_pushboolean(L, true);
    return 1;
}

