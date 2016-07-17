#ifndef _DATASRV_H_
#define _DATASRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class DataSrv: public Component
{
    public:
        DataSrv();
        virtual ~DataSrv();
        virtual void awake();
//tolua_end

DECLAR(DataSrv);

};//tolua_export

#endif


