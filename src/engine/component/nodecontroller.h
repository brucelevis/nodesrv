#ifndef _NODE_CONTROLLER_H_
#define _NODE_CONTROLLER_H_

#include "component/component.h"

class NodeController : public Component
{
    public:
        NodeController();
        virtual ~NodeController();
    private:
        /*
         * 新节点注册
         */
        void recv_connect(Message* msg);
};

#endif
