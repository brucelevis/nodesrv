#ifndef _GATE_H_
#define _GATE_H_


class Gate : public Component
{
    public:
        Gate();
        virtual ~Gate();

    public:
        /*
         * 登录
         */
        int recv_login(MsgHeader* header, const char* data, size_t size);
        /*
         * 登出
         */
        int recv_logout(MsgHeader* header, const char* data, size_t size);
};


#endif
