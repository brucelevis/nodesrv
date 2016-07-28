#ifndef _SCRIPT_COMPONENT_H_
#define _SCRIPT_COMPONENT_H_

#include "component/component.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class ScriptComponent : public Component {//tolua_export
    public:
        ScriptComponent(const char* modname);//tolua_export
        virtual ~ScriptComponent(); //tolua_export

        virtual void awake();//tolua_export
        virtual void update(uint64_t cur_tick);//tolua_export
        virtual int recv(Message* msg);//tolua_export

        int addtimer(lua_State *L);//tolua_export
    public:
        char modname[64];//tolua_export

    private:
        int init_script(const char* modname);

DECLAR(ScriptComponent);
};//tolua_export

#endif
