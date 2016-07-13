#ifndef _MSG_COMPONENT_H_
#define _MSG_COMPONENT_H_

#include "component/component.h"
#include "google/protobuf/message.h"
#include <map>

class MsgComponent : public Component
{
    public:
        MsgComponent();
        virtual ~MsgComponent();
        virtual int recv(Message* msg);
    public:
        typedef int (MsgComponent::*MsgHandler)(Message*, ::google::protobuf::Message*);

        void send_msg(::google::protobuf::Message* msg);
        void regist_msg(int id, MsgHandler handler);
    private:
        std::map<int, MsgHandler> handler_map_;
};

#endif
