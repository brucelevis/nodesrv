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
        virtual int recv(Message* msg);

//tolua_end
    private:
        int recv_net_raw_data(Message* msg);
        int recv_new_connection(Message* msg);
        int recv_close_connection(Message* msg);
DECLAR(GateSrv);

};//tolua_export

#endif


