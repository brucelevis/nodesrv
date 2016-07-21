/*
** Lua binding: client
** Generated automatically by tolua++-1.0.92 on Thu Jul 21 16:56:11 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_client_open (lua_State* tolua_S);

#include "client.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Client (lua_State* tolua_S)
{
 Client* self = (Client*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Client");
}

/* method: new of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_new00
static int tolua_client_Client_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Client* tolua_ret = (Client*)  new Client();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Client");
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

/* method: new_local of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_new00_local
static int tolua_client_Client_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Client* tolua_ret = (Client*)  new Client();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Client");
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

/* method: delete of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_delete00
static int tolua_client_Client_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_awake00
static int tolua_client_Client_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
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

/* method: recv of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_recv00
static int tolua_client_Client_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  lua_State* L =  tolua_S;
  {
return Client::recv(L);
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

/* method: send of class  Client */
#ifndef TOLUA_DISABLE_tolua_client_Client_send00
static int tolua_client_Client_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  lua_State* L =  tolua_S;
  {
return Client::send(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_client_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Client","Client","Component",tolua_collect_Client);
  #else
  tolua_cclass(tolua_S,"Client","Client","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Client");
   tolua_function(tolua_S,"new",tolua_client_Client_new00);
   tolua_function(tolua_S,"new_local",tolua_client_Client_new00_local);
   tolua_function(tolua_S,".call",tolua_client_Client_new00_local);
   tolua_function(tolua_S,"delete",tolua_client_Client_delete00);
   tolua_function(tolua_S,"awake",tolua_client_Client_awake00);
   tolua_function(tolua_S,"recv",tolua_client_Client_recv00);
   tolua_function(tolua_S,"send",tolua_client_Client_send00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_client (lua_State* tolua_S) {
 return tolua_client_open(tolua_S);
};
}
#endif

