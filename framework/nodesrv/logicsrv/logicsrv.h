#ifndef _LOGICSRV_H_
#define _LOGICSRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class LogicSrv: public Component
{
    public:
        LogicSrv();
        virtual ~LogicSrv();
        virtual void awake();
        virtual int recv(Message* msg);

//tolua_end
    private:
DECLAR(LogicSrv);

};//tolua_export

#endif


