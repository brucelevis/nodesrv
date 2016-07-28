
#ifndef _POST_COMPONENT_H_
#define _POST_COMPONENT_H_

#include "component/component.h"
#include "container/buffer.h"
#include <google/protobuf/message.h>
#include <google/protobuf/dynamic_message.h>



class POSTComponent;
/*
 * 兼容之前的代码
 * POSTComponent是与实体无关的, POSTComponent约定好挂在实体0上
 *
 * POSTMethod method;
 * method << "Login.PLAYER_EXIT" << uid;
 * method.invoke(this, nodeid, entityid);
 */

class POSTMethod
{
    public:
        struct Option
        {
        };
    public:
        Option option;
        Buffer buffer;
    public:
        void reset();
        void invoke(Component* component, int dst_nodeid, int dst_entityid);
        POSTMethod& operator <<(int val);
        POSTMethod& operator <<(const char* val);
        POSTMethod& operator <<(::google::protobuf::Message* msg);
};

class POSTComponent : public Component {//tolua_export

    public:
        POSTComponent();//tolua_export
        ~POSTComponent();//tolua_export

        int post(lua_State* L);
        void awake();
        int recv(Message* msg);
        int recv_post(Message* msg);
    public:
        POSTMethod method;
DECLAR(POSTComponent);
};//tolua_export


#endif
