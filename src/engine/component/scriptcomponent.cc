
#include "component/scriptcomponent.h"
#include "entity/entity.h"
#include "node/node.h"

#include <string.h>

IMPLEMENT(ScriptComponent)

ScriptComponent::ScriptComponent(const char* modname)
{
    init_script(modname);
}

int ScriptComponent::init_script(const char* modname)
{
    strcpy(this->modname, modname);
    return 0;
}

ScriptComponent::~ScriptComponent()
{

}

void ScriptComponent::awake()
{
    lua_State* L = get_lua_state(); 
    static char funcname[128];
    sprintf(funcname, "%s.awake", modname);
    lua_pushfunction(funcname);
    tolua_pushusertype(L, this, "ScriptComponent");
    if (lua_pcall(L, 1, 0, 0) != 0)
    {
        printf("ScriptComponent %s awake error %s\n", this->modname, lua_tostring(L, -1));
        lua_printstack();
    }
    lua_pop(L, lua_gettop(L));
}

void ScriptComponent::update(uint64_t cur_tick)
{
    lua_State* L = get_lua_state(); 
    static char funcname[128];
    sprintf(funcname, "%s.update", modname);
    lua_pushfunction(funcname);
    tolua_pushusertype(L, this, "ScriptComponent");
    lua_pushnumber(L, cur_tick);
    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        printf("ScriptComponent %s update error %s\n", this->modname, lua_tostring(L, -1));
        lua_printstack();
    }
    lua_pop(L, lua_gettop(L));
}

int ScriptComponent::recv(Message* msg)
{
    lua_State* L = get_lua_state(); 
    static char funcname[128];
    sprintf(funcname, "%s.recv", modname);
    lua_pushfunction(funcname);
    tolua_pushusertype(L, this, "ScriptComponent");
    tolua_pushusertype(L, msg, "Message");
    if (lua_pcall(L, 2, 0, 0) != 0)
    {
        printf("ScriptComponent %s recv error %s\n", this->modname, lua_tostring(L, -1));
        lua_printstack();
    }
    lua_pop(L, lua_gettop(L));
    return 0;
}


