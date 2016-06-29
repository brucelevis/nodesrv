#ifndef _GATESRV_H_
#define _GATESRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class GateSrv: public Component
{
    public:
        GateSrv();
        virtual ~GateSrv();
        virtual void awake();
//tolua_end

DECLAR(GateSrv);

};//tolua_export

#endif


