#ifndef _MYSQL_COMPONENT_H_
#define _MYSQL_COMPONENT_H_

extern "C" {
#include <mysql.h>
}
#include <stdio.h>

#include "component/component.h"

class MYSQLComponent : public Component
{
    public:
        MYSQLComponent();
        virtual ~MYSQLComponent();

    public:
        virtual void update(long long cur_tick);
        int connect(const char*host, const char* dbname, const char* user, const char* passwd);
        int command(const char* str);
        int select(const char* str);

    private:
        MYSQL* conn_;
};

#endif
