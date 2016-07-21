
#include "component/postcomponent.h"
#include "lualib/pblua/pblua.h"
#include "log/log.h"
#include "node/nodemgr.h"
#include "lualib/json/json.h"

#include <string.h>

#define TYPE_NIL  1
#define TYPE_NUMBER  2
#define TYPE_STRING  3
#define TYPE_PROTOBUF 4
#define TYPE_JSON 5

IMPLEMENT(POSTComponent)


POSTMethod& POSTMethod::operator <<(const char* val)
{
    buffer.write_int8(TYPE_STRING);
    buffer.write_utf8(val);
    return *this;
}


POSTMethod& POSTMethod::operator <<(int val)
{
    buffer.write_int8(TYPE_NUMBER);
    buffer.write_int32(val);
    return *this;
}

POSTMethod& POSTMethod::operator <<(::google::protobuf::Message* message)
{
    const char *msg_name = message->GetDescriptor()->full_name().data();
    if(msg_name == NULL)
    {
        LOG_ERROR("msg_name is nil");
        return *this;
    }
    int msg_len = message->ByteSize();
    buffer.write_int8(TYPE_PROTOBUF);
    buffer.write_utf8(msg_name);
    if (!buffer.ensure_size(msg_len))
    {
        LOG_ERROR("memory limit");
        return *this; 
    }
    buffer.write_int32(msg_len);
    char* buf = buffer.get_write_buffer();
    char * buf_end = (char *)message->SerializeWithCachedSizesToArray((google::protobuf::uint8 *)buf);
    int real_len = buf_end - buf;
    if(real_len != msg_len)
    {
        LOG_ERROR("serialize fail %d/%d msg_name:%s\n", buf_end - buf, msg_len, msg_name);
        return *this;
    }
    buffer.write_buf(NULL, real_len);
    if(message->ByteSize() < 1024)
    {
        LOG_DEBUG("byte_size %d\n%s", msg_len, message->DebugString().data());
    }
    return *this;
}

void POSTMethod::reset()
{
    buffer.reset();
}

void POSTMethod::invoke(Component* component, int dst_nodeid, int dst_objectid)
{
    if (!component)
    {
        return;
    }
    Message *msg = component->alloc_msg();
    msg->header.id = MSG_POST;
    //结束
    buffer.write_int8(0);
    msg->payload.write(&buffer);
    msg->option.cache = true;
    component->send_gameobject_msg(dst_nodeid, dst_objectid, msg);
}

POSTComponent::POSTComponent()
{
}

POSTComponent::~POSTComponent()
{

}

void POSTComponent::awake()
{
    LOG_DEBUG("POSTComponent::awake");
    this->gameobject->reg_msg(MSG_POST, this);
}

int POSTComponent::recv_post(Message* msg)
{
    lua_State* L = get_lua_state(); 
    int8_t arg_type = 0;
    int8_t arg_count = 0;
    //char* b = msg->payload.get_buffer();
    //for (int i = 0; i < 20; i++)
    //{
        //printf("%d\n", b[i]);
    //}
    arg_type = msg->payload.read_int8();
    const char* funcname = msg->payload.read_utf8();
    if(lua_pushfunction(funcname))
    {
        LOG_ERROR("lua_pushfunction error %s", funcname);
        lua_pop(L, lua_gettop(L));
        return 1;
    }
    LOG_MSG("RECV POST func(%s)", funcname);
    lua_pushnumber(L, msg->header.src_nodeid);
    while(msg->payload.size() >= 1)
    {
        arg_type = msg->payload.read_int8();
        if (arg_type == 0)
        {
            break;
        }
        arg_count++;
        switch(arg_type)
        {
            case TYPE_NIL:
                {
                    lua_pushnil(L);
                }
                break;
            case TYPE_NUMBER:
                {
                    int32_t val = (int32_t)msg->payload.read_int32();
                    LOG_MSG("recv arg%d number %d", arg_count, val);
                    lua_pushnumber(L, val);
                }break;
            case TYPE_STRING:
                {
                    const char* val = (const char*)msg->payload.read_utf8();
                    LOG_MSG("recv arg%d string %s", arg_count, val);
                    lua_pushstring(L, val);
                }break;
            case TYPE_JSON:
                {
                    unsigned int str_len = msg->payload.read_int16();
                    char* val = msg->payload.get_buffer();
                    Json::decode(L, val);
                    LOG_MSG("recv arg%d json %s", arg_count, val);
                    msg->payload.read_buf(NULL, str_len + 1);
                }
                break;

            case TYPE_PROTOBUF:
                {
                    const char* msg_name = msg->payload.read_utf8();
                    if(msg_name == NULL)
                    {
                        LOG_ERROR("msg name error");
                        lua_pop(L, lua_gettop(L));
                        return 0;
                    }
                    LOG_MSG("recv arg%d protobuf %s", arg_count, msg_name);
                    google::protobuf::Message* message = pblua_load_msg(msg_name);
                    if(message == NULL)
                    {
                        LOG_ERROR("can not load msg %s", msg_name);
                        lua_pop(L, lua_gettop(L));
                        return 0;
                    }
                    int32_t msg_len = msg->payload.read_int32();
                    google::protobuf::io::ArrayInputStream stream(msg->payload.get_buffer(), msg_len);
                    if(message->ParseFromZeroCopyStream(&stream) == 0)
                    {
                        LOG_ERROR("parse fail size(%d) %s\n", msg->payload.size(), msg_name);
                        lua_pop(L, lua_gettop(L));
                        return 0;
                    }    
                    LuaMessage *message_lua = (LuaMessage *)lua_newuserdata(L, sizeof(LuaMessage));
                    if(message_lua == NULL)
                    {
                        LOG_ERROR("newuserdata null %s", msg_name);
                        lua_pop(L, lua_gettop(L));
                        return 0;
                    }
                    msg->payload.read_buf(NULL, msg_len);
                    message_lua->message = message;
                    message_lua->root_message = message_lua;
                    message_lua->dirty = 0;
                    luaL_getmetatable(L, "LuaMessage");
                    lua_setmetatable(L, -2);
                    if(message->ByteSize() < 1024)
                    {
                        LOG_DEBUG("%s", message->DebugString().data());
                    }
                }
                break;

        }
    }
    if(lua_pcall(L, arg_count + 1, 0, 0) != 0)
    {
        LOG_ERROR("post call %s(%d) error %s\n", funcname, arg_count, lua_tostring(L, -1));
        lua_printstack();
    }
    lua_pop(L, lua_gettop(L));
    LOG_MSG("RECV POST func(%s) FINISH", funcname);
    return 0;
}

int POSTComponent::recv(Message* msg)
{
    switch(msg->header.id)
    {
        case MSG_POST:
            {
                return recv_post(msg);
            }
            break;
    }
    return 0;
}

int POSTComponent::post(lua_State* L)
{
    if (!lua_isnumber(L, 2) || !lua_isstring(L, 3))
    {
        LOG_ERROR("arg error");
        return 0;
    }
    int dst_nodeid = (int)lua_tonumber(L, 2);
    int dst_objectid = 0;
    const char* func = (const char*)lua_tostring(L, 3);

    LOG_MSG("POST %s TO %d %d", func, dst_nodeid, dst_objectid);
    method.reset();
    method << func;
    int arg_count = lua_gettop(L);
    for (int i = 4; i <= arg_count; i++)
    {
        if (lua_isnumber(L, i))
        {
            int32_t val =  (int32_t)lua_tonumber(L, i);
            LOG_MSG("post arg%d number %d", i - 3, val);
            method << val;
        } else if(lua_isstring(L, i))
        {
            const char* val = (const char*)lua_tostring(L, i);
            LOG_MSG("post arg%d string %s", i - 3, val);
            method << val;
        } else if(lua_isuserdata(L, i))
        {
            LuaMessage *message_lua = (LuaMessage *)luaL_checkudata(L, i, "LuaMessage");
            if(message_lua == NULL)
            {
                LOG_ERROR("checkuserdata is null");
                return 0;
            }
            google::protobuf::Message *message = message_lua->message;
            const char *msg_name = message->GetDescriptor()->full_name().data();
            LOG_DEBUG("post arg%d protobuf %s", i - 3, msg_name);
            if(message == NULL)
            {
                LOG_ERROR("message is null");
                return 0;
            }
            method << message;
        } else if(lua_istable(L, i))
        {
            method.buffer.write_int8(TYPE_JSON);

            lua_pushvalue(L, i);
            char *val= Json::encode(L);
            lua_pop(L, 1);
            if(val == NULL){
                return 0;
            }
            int str_len = strlen(val);
            LOG_MSG("post arg%d json %s", i - 3, val);
            method.buffer.write_int16(str_len);
            method.buffer.write_buf(val, str_len);
            method.buffer.write_int8(0);
            //释放 
            free(val);
        }
    }
    method.invoke(this, dst_nodeid, dst_objectid);
    LOG_MSG("POST %s TO %d %d FINISH", func, dst_nodeid, dst_objectid);
    lua_pushboolean(L, 1);
    return 1;
}
