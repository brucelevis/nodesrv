#include "components/rediscomponent.h"

#define LOG(str, ...)     printf("%s:%d", __FILE__, __LINE__);printf(str, ## __VA_ARGS__);printf("\n");

REDISComponent::REDISComponent()
{
    context_ = 0;
}

REDISComponent::~REDISComponent()
{

}


void REDISComponent::update(long long cur_tick)
{

}

int REDISComponent::connect(const char* ip, unsigned short port)
{
    redisContext *c = redisConnect(ip, port);
    if(c == NULL)
    {
        LOG("connect error");
        return 0;
    }
    if(!(c->flags & REDIS_CONNECTED))
    {
        redisFree(c);
        printf("connect error");
        return 0;
    }
    this->context_ = c;
    return 0;
}


int REDISComponent::command(const char* str)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, str);
    if(reply == NULL){
        LOG("Command:redisCommand fail command:%s", str);
        return 0;
    }
    return 0;
}

int REDISComponent::command_argv(int argc, const char** argv, const size_t* argvlen)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is nil");
        return 1;
    }
    redisReply * reply = (redisReply *)redisCommandArgv(c, argc, argv, argvlen);
    if(reply == NULL){
        LOG("command_argv fail");
        return 1;
    }
    return 0;
}

int REDISComponent::select(const char* str)
{
    return 0;
}

int REDISComponent::set(const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "set %s %b", key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::freeReply(redisReply* reply)
{
    freeReplyObject(reply);
    return 0;
}

int REDISComponent::hset(const char* table, const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "hset %s %s %b", table, key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::lpush(const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "lpush %s %b", key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::zadd(const char* key, float score, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "zadd %s %f %b", key, score, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::zrank(const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "zrank %s %b", key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::zrem(const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "zrem %s %b", key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}

int REDISComponent::zrevrank(const char* key, const char* data, size_t size)
{
    struct redisContext *c = this->context_;
    if(c == NULL){
        LOG("context is null");
        return 0;
    }
    redisReply * reply = (redisReply *)redisCommand(c, "zrevrank %s %b", key, data, size);
    if(reply == NULL){
        LOG("Set:redisCommand fail key:%s", key);
        return 0;
    }
    return 0;
}


