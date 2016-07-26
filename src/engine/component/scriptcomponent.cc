
#include "component/scriptcomponent.h"
#include "node/gameobject.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "log/log.h"

#include <string.h>

IMPLEMENT(ScriptComponent)

static int s_min_msec = 0x7fffffff;
static int s_timer_counter = 0;
static int s_call_lua_time = 0;
typedef struct TimerData 
{
    char callback[64];
    int msec;
    int timerid;
    int msgid;
    void* userdata;
    lua_State* L;
}TimerData;

static void timer_finalizer_proc(struct aeEventLoop *eventLoop, void *clientData) 
{
    TimerData *timedata = (TimerData *)clientData;
    if (timedata) 
    {
        free(timedata);
    }
    s_timer_counter--;
}


/*
 * 如果lua返回0则删除timer, 
 * 如果n=0, 则以上次的时间再次触发
 * 如果n>0, 则n毫秒后再次触发
 */
static int timer_proc(struct aeEventLoop *eventLoop, long long id, void *clientData)
{
    TimerData *timerdata = (TimerData *)clientData;
    if(timerdata == NULL)
    {
        LOG_ERROR("timer is null");
        return AE_NOMORE;
    }
    lua_State *L = timerdata->L;
    ScriptComponent* component = (ScriptComponent*)timerdata->userdata;

    if(component->lua_pushfunction(timerdata->callback))
    {
        LOG_ERROR("push func %s fail", timerdata->callback);
        return AE_NOMORE;
    }
    //LOG_LOG("[TIMER_START] %s", timerdata->callback);
    s_call_lua_time++;
    tolua_pushusertype(L, component, "ScriptComponent");
    lua_pushnumber(L, timerdata->timerid);
    
    if(lua_pcall(L, 2, 1, 0) != 0)
    {
        LOG_ERROR("%s", lua_tostring(L, -1));
        lua_pop(L, lua_gettop(L));
        return timerdata->msec;
    }
    //LOG_LOG("[TIMER_END] %s", timerdata->callback);
    int ir = (int)lua_tointeger(L, -1);
    lua_pop(L, lua_gettop(L));
    if(ir == 1)
    {
        return timerdata->msec;
    }else if(ir != 0)
    {
        return ir;
    }else
    {
        return AE_NOMORE;
    }
} 


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
    //LOG_INFO("%s %s", __FUNCTION__, funcname);
    if(lua_pushfunction(funcname))
    {
        //LOG_ERROR("lua_pushfunction error %s.update", modname);
        lua_pop(L, lua_gettop(L));
        return;
    }
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
    if(lua_pushfunction(funcname))
    {
        LOG_ERROR("lua_pushfunction error %s.recv", modname);
        return 0;
    }
    tolua_pushusertype(L, this, "ScriptComponent");
    tolua_pushusertype(L, msg, "Message");
    if (lua_pcall(L, 2, 1, 0) != 0)
    {
        LOG_ERROR("ScriptComponent %s recv error %s", this->modname, lua_tostring(L, -1));
        lua_pop(L, lua_gettop(L));
        return 0;
    } else 
    {
        int result = (int)lua_tonumber(L, -1);
        lua_pop(L, lua_gettop(L));
        return result;
    }
}

int ScriptComponent::addtimer(lua_State *L)
{
    if (lua_gettop(L) == 3 && lua_isnumber(L, 2) && lua_isstring(L, 3)) 
    {
        aeEventLoop *loop = NodeMgr::loop;
        int msec;
        char *funcname;
        msec = (int)lua_tonumber(L, 2);
        funcname = (char *)lua_tostring(L, 3);
        TimerData *timerdata = (TimerData *)malloc(sizeof(TimerData));
        if(timerdata == NULL)
        {
            LOG_ERROR("malloc fail");
            return 0;
        }
        timerdata->userdata = this;
        timerdata->msec = msec;
        timerdata->L = L;
        s_timer_counter++;
        strcpy(timerdata->callback, funcname);
        if(s_min_msec > msec)s_min_msec = msec;
        int timerid = aeCreateTimeEvent(loop, msec, timer_proc, timerdata, timer_finalizer_proc);
        timerdata->timerid = timerid;
        return timerid;
    }
    LOG_ERROR("args wrong");
    return 0;
}


