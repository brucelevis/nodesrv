#ifndef _SCRIPT_COMPONENT_H_
#define _SCRIPT_COMPONENT_H_

#include "component/component.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

//tolua_begin
class ScriptComponent : public Component
{
    public:
        ScriptComponent(const char* modname);
        virtual ~ScriptComponent();

        virtual void awake();
        virtual void update(uint64_t cur_tick);
        virtual int recv(Message* msg);

    public:
        char modname[64];
//tolua_end
DECLAR(ScriptComponent);
    private:
        int init_script(const char* modname);
};//tolua_export

#endif
