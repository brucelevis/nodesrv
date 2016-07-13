#ifndef _SCENESRV_H_
#define _SCENESRV_H_

#include "component/component.h"
#include <map>

//tolua_begin
class SceneSrv: public Component
{
    public:
        SceneSrv();
        virtual ~SceneSrv();
        virtual void awake();
        virtual int recv(Message* msg);

//tolua_end
    private:
DECLAR(SceneSrv);

};//tolua_export

#endif


