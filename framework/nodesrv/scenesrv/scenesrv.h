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
        int recv_net_raw_data(Message* msg);
        int recv_new_connection(Message* msg);
        int recv_close_connection(Message* msg);
DECLAR(SceneSrv);

};//tolua_export

#endif


