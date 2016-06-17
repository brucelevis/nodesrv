/*
** Lua binding: dbsrv
** Generated automatically by tolua++-1.0.92 on Fri Jun 17 16:41:50 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_dbsrv_open (lua_State* tolua_S);

#include "dbsrv.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_DbSrv (lua_State* tolua_S)
{
 DbSrv* self = (DbSrv*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"DbSrv");
}

/* method: new of class  DbSrv */
#ifndef TOLUA_DISABLE_tolua_dbsrv_DbSrv_new00
static int tolua_dbsrv_DbSrv_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DbSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DbSrv* tolua_ret = (DbSrv*)  new DbSrv();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"DbSrv");
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

/* method: new_local of class  DbSrv */
#ifndef TOLUA_DISABLE_tolua_dbsrv_DbSrv_new00_local
static int tolua_dbsrv_DbSrv_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DbSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DbSrv* tolua_ret = (DbSrv*)  new DbSrv();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"DbSrv");
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

/* method: delete of class  DbSrv */
#ifndef TOLUA_DISABLE_tolua_dbsrv_DbSrv_delete00
static int tolua_dbsrv_DbSrv_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DbSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DbSrv* self = (DbSrv*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  DbSrv */
#ifndef TOLUA_DISABLE_tolua_dbsrv_DbSrv_awake00
static int tolua_dbsrv_DbSrv_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DbSrv",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DbSrv* self = (DbSrv*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_dbsrv_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DbSrv","DbSrv","Component",tolua_collect_DbSrv);
  #else
  tolua_cclass(tolua_S,"DbSrv","DbSrv","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DbSrv");
   tolua_function(tolua_S,"new",tolua_dbsrv_DbSrv_new00);
   tolua_function(tolua_S,"new_local",tolua_dbsrv_DbSrv_new00_local);
   tolua_function(tolua_S,".call",tolua_dbsrv_DbSrv_new00_local);
   tolua_function(tolua_S,"delete",tolua_dbsrv_DbSrv_delete00);
   tolua_function(tolua_S,"awake",tolua_dbsrv_DbSrv_awake00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_dbsrv (lua_State* tolua_S) {
 return tolua_dbsrv_open(tolua_S);
};
}
#endif

