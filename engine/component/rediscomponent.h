#ifndef _REDIS_COMPONENT_H_
#define _REDIS_COMPONENT_H_

extern "C" {
#include <hiredis.h>
}
#include <stdio.h>

#include "component/component.h"

class REDISComponent : public Component
{
    public:
        REDISComponent();
        virtual ~REDISComponent();

    public:
        virtual void update(long long cur_tick);
        int connect(const char* ip, unsigned short port);
        int command(const char* str);
        int command_argv(int argc, const char** argv, const size_t* argvlen);
        int select(const char* str);
        int set(const char* key, const char* data, size_t size);
        int hset(const char* table, const char* key, const char* data, size_t size);
        int lpush(const char* key, const char* data, size_t size);
        int zadd(const char* key, float score, const char* data, size_t size);
        int zrank(const char* key, const char* data, size_t size);
        int zrem(const char* key, const char* data, size_t size);
        int zrevrank(const char* key, const char* data, size_t size);

        int freeReply(redisReply* reply);

    private:
        redisContext* context_;
};

#endif
