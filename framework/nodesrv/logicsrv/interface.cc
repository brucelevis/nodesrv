/*
** Lua binding: logicsrv
** Generated automatically by tolua++-1.0.92 on Wed Jul 13 17:27:08 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_logicsrv_open (lua_State* tolua_S);

#include "logicsrv.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LogicSrv (lua_State* tolua_S)
{
 LogicSrv* self = (LogicSrv*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Message");
 tolua_usertype(tolua_S,"LogicSrv");
}

/* method: new of class  LogicSrv */
#ifndef TOLUA_DISABLE_tolua_logicsrv_LogicSrv_new00
static int tolua_logicsrv_LogicSrv_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LogicSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LogicSrv* tolua_ret = (LogicSrv*)  new LogicSrv();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"LogicSrv");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LogicSrv */
#ifndef TOLUA_DISABLE_tolua_logicsrv_LogicSrv_new00_local
static int tolua_logicsrv_LogicSrv_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LogicSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LogicSrv* tolua_ret = (LogicSrv*)  new LogicSrv();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"LogicSrv");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LogicSrv */
#ifndef TOLUA_DISABLE_tolua_logicsrv_LogicSrv_delete00
static int tolua_logicsrv_LogicSrv_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LogicSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicSrv* self = (LogicSrv*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: awake of class  LogicSrv */
#ifndef TOLUA_DISABLE_tolua_logicsrv_LogicSrv_awake00
static int tolua_logicsrv_LogicSrv_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LogicSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicSrv* self = (LogicSrv*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'awake'",NULL);
#endif
  {
   self->awake();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'awake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  LogicSrv */
#ifndef TOLUA_DISABLE_tolua_logicsrv_LogicSrv_recv00
static int tolua_logicsrv_LogicSrv_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LogicSrv",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LogicSrv* self = (LogicSrv*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   int tolua_ret = (int)  self->recv(msg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_logicsrv_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LogicSrv","LogicSrv","Component",tolua_collect_LogicSrv);
  #else
  tolua_cclass(tolua_S,"LogicSrv","LogicSrv","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LogicSrv");
   tolua_function(tolua_S,"new",tolua_logicsrv_LogicSrv_new00);
   tolua_function(tolua_S,"new_local",tolua_logicsrv_LogicSrv_new00_local);
   tolua_function(tolua_S,".call",tolua_logicsrv_LogicSrv_new00_local);
   tolua_function(tolua_S,"delete",tolua_logicsrv_LogicSrv_delete00);
   tolua_function(tolua_S,"awake",tolua_logicsrv_LogicSrv_awake00);
   tolua_function(tolua_S,"recv",tolua_logicsrv_LogicSrv_recv00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_logicsrv (lua_State* tolua_S) {
 return tolua_logicsrv_open(tolua_S);
};
}
#endif

