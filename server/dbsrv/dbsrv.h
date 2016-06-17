#ifndef _DBSRV_H_
#define _DBSRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class DbSrv: public Component
{
    public:
        DbSrv();
        virtual ~DbSrv();
        virtual void awake();
//tolua_end

DECLAR(DbSrv);

};//tolua_export

#endif


