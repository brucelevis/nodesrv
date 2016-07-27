/*
** Lua binding: neox
** Generated automatically by tolua++-1.0.92 on Wed Jul 27 17:52:22 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_neox_open (lua_State* tolua_S);

#include "neox.h"
#include "type/type.h"
#include "net/httpclient.h"
#include "node/gameobject.h"
#include "node/node.h"
#include "node/nodemgr.h"
#include "node/router.h"
#include "component/component.h"
#include "component/scriptcomponent.h"
#include "component/netcomponent.h"
#include "component/httpcomponent.h"
#include "component/postcomponent.h"
#include "msg/msg.h"
#include "container/buffer.h"
#include "file/file.h"
#include "display/transform.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Type (lua_State* tolua_S)
{
 Type* self = (Type*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_ScriptComponent (lua_State* tolua_S)
{
 ScriptComponent* self = (ScriptComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_GameObject (lua_State* tolua_S)
{
 GameObject* self = (GameObject*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Transform (lua_State* tolua_S)
{
 Transform* self = (Transform*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Component (lua_State* tolua_S)
{
 Component* self = (Component*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_NetComponent (lua_State* tolua_S)
{
 NetComponent* self = (NetComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_HttpClient (lua_State* tolua_S)
{
 HttpClient* self = (HttpClient*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Buffer (lua_State* tolua_S)
{
 Buffer* self = (Buffer*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_HttpComponent (lua_State* tolua_S)
{
 HttpComponent* self = (HttpComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Message (lua_State* tolua_S)
{
 Message* self = (Message*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Node (lua_State* tolua_S)
{
 Node* self = (Node*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_POSTComponent (lua_State* tolua_S)
{
 POSTComponent* self = (POSTComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"MessageHeader");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"HttpClient");
 tolua_usertype(tolua_S,"HttpComponent");
 tolua_usertype(tolua_S,"aeFileProc");
 tolua_usertype(tolua_S,"Type");
 tolua_usertype(tolua_S,"MessageOption");
 tolua_usertype(tolua_S,"ScriptComponent");
 tolua_usertype(tolua_S,"GameObject");
 tolua_usertype(tolua_S,"Message");
 tolua_usertype(tolua_S,"NetComponent");
 tolua_usertype(tolua_S,"Router");
 tolua_usertype(tolua_S,"POSTComponent");
 tolua_usertype(tolua_S,"Buffer");
 tolua_usertype(tolua_S,"CreateGameObjectMsg");
 tolua_usertype(tolua_S,"Node");
}

/* function: Neox::main */
#ifndef TOLUA_DISABLE_tolua_neox_Neox_main00
static int tolua_neox_Neox_main00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int argc = ((int)  tolua_tonumber(tolua_S,1,0));
  char* argv = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  Neox::main(argc,&argv);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushstring(tolua_S,(const char*)argv);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'main'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Neox::create_node_remote */
#ifndef TOLUA_DISABLE_tolua_neox_Neox_create_node_remote00
static int tolua_neox_Neox_create_node_remote00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   Node* tolua_ret = (Node*)  Neox::create_node_remote(nodeid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_node_remote'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Neox::create_gameobject_local */
#ifndef TOLUA_DISABLE_tolua_neox_Neox_create_gameobject_local00
static int tolua_neox_Neox_create_gameobject_local00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,2,""));
  {
   GameObject* tolua_ret = (GameObject*)  Neox::create_gameobject_local(nodeid,filepath);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_gameobject_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Neox::fork_daemon */
#ifndef TOLUA_DISABLE_tolua_neox_Neox_fork_daemon00
static int tolua_neox_Neox_fork_daemon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Neox::fork_daemon();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fork_daemon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: Neox::loop */
#ifndef TOLUA_DISABLE_tolua_neox_Neox_loop00
static int tolua_neox_Neox_loop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Neox::loop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Type */
#ifndef TOLUA_DISABLE_tolua_neox_Type_new00
static int tolua_neox_Type_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Type",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Type* tolua_ret = (Type*)  new Type(name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Type");
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

/* method: new_local of class  Type */
#ifndef TOLUA_DISABLE_tolua_neox_Type_new00_local
static int tolua_neox_Type_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Type",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Type* tolua_ret = (Type*)  new Type(name);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Type");
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

/* get function: name of class  Type */
#ifndef TOLUA_DISABLE_tolua_get_Type_name
static int tolua_get_Type_name(lua_State* tolua_S)
{
  Type* self = (Type*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  Type */
#ifndef TOLUA_DISABLE_tolua_set_Type_name
static int tolua_set_Type_name(lua_State* tolua_S)
{
  Type* self = (Type*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->name,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_new00
static int tolua_neox_HttpClient_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpClient* tolua_ret = (HttpClient*)  new HttpClient();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpClient");
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

/* method: new_local of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_new00_local
static int tolua_neox_HttpClient_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpClient* tolua_ret = (HttpClient*)  new HttpClient();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"HttpClient");
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

/* method: delete of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_delete00
static int tolua_neox_HttpClient_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
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

/* method: connect of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_connect00
static int tolua_neox_HttpClient_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  const char* host = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->connect(host,port);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_connect of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_is_connect00
static int tolua_neox_HttpClient_is_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_connect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_connect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send00
static int tolua_neox_HttpClient_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  const char* val = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'",NULL);
#endif
  {
   self->send(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_recv00
static int tolua_neox_HttpClient_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->recv();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
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

/* method: recv_frame of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_recv_frame00
static int tolua_neox_HttpClient_recv_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_frame'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->recv_frame();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: close of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_close00
static int tolua_neox_HttpClient_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'close'",NULL);
#endif
  {
   self->close();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_open_websock of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send_open_websock00
static int tolua_neox_HttpClient_send_open_websock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_open_websock'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send_open_websock();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_open_websock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_binary_frame of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send_binary_frame00
static int tolua_neox_HttpClient_send_binary_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  Buffer* buffer = ((Buffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_binary_frame'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send_binary_frame(buffer);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_binary_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_binary_frame of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send_binary_frame01
static int tolua_neox_HttpClient_send_binary_frame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  const void* data = ((const void*)  tolua_touserdata(tolua_S,2,0));
  unsigned short datalen = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_binary_frame'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send_binary_frame(data,datalen);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_HttpClient_send_binary_frame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_string_frame of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send_string_frame00
static int tolua_neox_HttpClient_send_string_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_string_frame'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send_string_frame(str);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_string_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_frame of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_neox_HttpClient_send_frame00
static int tolua_neox_HttpClient_send_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpClient",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
  int opcode = ((int)  tolua_tonumber(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  unsigned short datalen = ((unsigned short)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_frame'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send_frame(opcode,data,datalen);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: buffer of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_get_HttpClient_buffer
static int tolua_get_HttpClient_buffer(lua_State* tolua_S)
{
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buffer'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->buffer,"Buffer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: buffer of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_set_HttpClient_buffer
static int tolua_set_HttpClient_buffer(lua_State* tolua_S)
{
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buffer'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Buffer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->buffer = *((Buffer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: content_length of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_get_HttpClient_content_length
static int tolua_get_HttpClient_content_length(lua_State* tolua_S)
{
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content_length'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->content_length);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: content_length of class  HttpClient */
#ifndef TOLUA_DISABLE_tolua_set_HttpClient_content_length
static int tolua_set_HttpClient_content_length(lua_State* tolua_S)
{
  HttpClient* self = (HttpClient*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content_length'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->content_length = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_new00
static int tolua_neox_GameObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameObject* tolua_ret = (GameObject*)  new GameObject();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
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

/* method: new_local of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_new00_local
static int tolua_neox_GameObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameObject* tolua_ret = (GameObject*)  new GameObject();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"GameObject");
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

/* method: delete of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_delete00
static int tolua_neox_GameObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: test of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_test00
static int tolua_neox_GameObject_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'test'",NULL);
#endif
  {
   int tolua_ret = (int)  self->test();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_create00
static int tolua_neox_GameObject_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create'",NULL);
#endif
  {
   self->create();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: save of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_save00
static int tolua_neox_GameObject_save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'save'",NULL);
#endif
  {
   int tolua_ret = (int)  self->save();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_update00
static int tolua_neox_GameObject_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  uint64_t cur_tick = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
  {
   self->update(cur_tick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: awake of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_awake00
static int tolua_neox_GameObject_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: destory of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_destory00
static int tolua_neox_GameObject_destory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory'",NULL);
#endif
  {
   self->destory();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_recv00
static int tolua_neox_GameObject_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: unreach of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_unreach00
static int tolua_neox_GameObject_unreach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreach'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreach(msg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unreach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_component of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_add_component00
static int tolua_neox_GameObject_add_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_component'",NULL);
#endif
  {
   int tolua_ret = (int)  self->add_component(component);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_component'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_script of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_add_script00
static int tolua_neox_GameObject_add_script00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* scriptname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_script'",NULL);
#endif
  {
   ScriptComponent* tolua_ret = (ScriptComponent*)  self->add_script(scriptname);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScriptComponent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_script'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: del_component of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_del_component00
static int tolua_neox_GameObject_del_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del_component'",NULL);
#endif
  {
   int tolua_ret = (int)  self->del_component(component);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'del_component'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_component00
static int tolua_neox_GameObject_get_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Type",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  Type* type = ((Type*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->get_component(type);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_component'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_component01
static int tolua_neox_GameObject_get_component01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->get_component(name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_GameObject_get_component00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_component02
static int tolua_neox_GameObject_get_component02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
return self->get_component(L);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_GameObject_get_component01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_script of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_script00
static int tolua_neox_GameObject_get_script00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* classname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_script'",NULL);
#endif
  {
   ScriptComponent* tolua_ret = (ScriptComponent*)  self->get_script(classname);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScriptComponent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_script'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reg_msg of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_reg_msg00
static int tolua_neox_GameObject_reg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  uint32_t id = ((uint32_t)  tolua_tonumber(tolua_S,2,0));
  Component* component = ((Component*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reg_msg'",NULL);
#endif
  {
   int tolua_ret = (int)  self->reg_msg(id,component);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reg_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unreg_msg of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_unreg_msg00
static int tolua_neox_GameObject_unreg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  uint32_t id = ((uint32_t)  tolua_tonumber(tolua_S,2,0));
  Component* component = ((Component*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreg_msg'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreg_msg(id,component);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unreg_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_child of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_child00
static int tolua_neox_GameObject_get_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_child'",NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->get_child(index);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_child'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_child of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_add_child00
static int tolua_neox_GameObject_add_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* obj = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_child'",NULL);
#endif
  {
   int tolua_ret = (int)  self->add_child(obj);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_child'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: del_child of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_del_child00
static int tolua_neox_GameObject_del_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del_child'",NULL);
#endif
  {
   int tolua_ret = (int)  self->del_child(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'del_child'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: del_child of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_del_child01
static int tolua_neox_GameObject_del_child01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* obj = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del_child'",NULL);
#endif
  {
   int tolua_ret = (int)  self->del_child(obj);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_GameObject_del_child00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: child_index of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_child_index00
static int tolua_neox_GameObject_child_index00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* obj = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'child_index'",NULL);
#endif
  {
   int tolua_ret = (int)  self->child_index(obj);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'child_index'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_parent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_get_parent00
static int tolua_neox_GameObject_get_parent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_parent'",NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->get_parent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_parent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: obj_dump of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_neox_GameObject_obj_dump00
static int tolua_neox_GameObject_obj_dump00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int deep = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'obj_dump'",NULL);
#endif
  {
   self->obj_dump(deep);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'obj_dump'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: id of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_id
static int tolua_get_GameObject_id(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_id
static int tolua_set_GameObject_id(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: data of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_data
static int tolua_get_GameObject_data(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->data);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: data of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_data
static int tolua_set_GameObject_data(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->data = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: node of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_node_ptr
static int tolua_get_GameObject_node_ptr(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->node,"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: node of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_node_ptr
static int tolua_set_GameObject_node_ptr(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->node = ((Node*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_name
static int tolua_get_GameObject_name(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_name
static int tolua_set_GameObject_name(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->name,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_new00
static int tolua_neox_Node_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Node* tolua_ret = (Node*)  new Node(nodeid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: new_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_new00_local
static int tolua_neox_Node_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Node* tolua_ret = (Node*)  new Node(nodeid);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Node");
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

/* method: delete of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_delete00
static int tolua_neox_Node_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: main of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_main00
static int tolua_neox_Node_main00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'main'",NULL);
#endif
  {
   self->main();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'main'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_update00
static int tolua_neox_Node_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  long long cur_tick = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
  {
   self->update(cur_tick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connect of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_connect00
static int tolua_neox_Node_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* host = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'",NULL);
#endif
  {
   int tolua_ret = (int)  self->connect(host,port);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: listen of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_listen00
static int tolua_neox_Node_listen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* host = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'listen'",NULL);
#endif
  {
   int tolua_ret = (int)  self->listen(host,port);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'listen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: find_gameobject of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_find_gameobject00
static int tolua_neox_Node_find_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  int objid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'find_gameobject'",NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->find_gameobject(objid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'find_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_gameobject of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_add_gameobject00
static int tolua_neox_Node_add_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_gameobject'",NULL);
#endif
  {
   int tolua_ret = (int)  self->add_gameobject(object);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_id of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_get_id00
static int tolua_neox_Node_get_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_id'",NULL);
#endif
  {
   uint32_t tolua_ret = (uint32_t)  self->get_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_is_local00
static int tolua_neox_Node_is_local00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_local'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_local();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_set_local00
static int tolua_neox_Node_set_local00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool v = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_local'",NULL);
#endif
  {
   self->set_local(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_disconnect of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_is_disconnect00
static int tolua_neox_Node_is_disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_disconnect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_disconnect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_gameobject_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_create_gameobject_local00
static int tolua_neox_Node_create_gameobject_local00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,2,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_gameobject_local'",NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->create_gameobject_local(filepath);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_gameobject_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_gameobject_remote of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_create_gameobject_remote00
static int tolua_neox_Node_create_gameobject_remote00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  GameObject* src_object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_gameobject_remote'",NULL);
#endif
  {
   self->create_gameobject_remote(src_object,filepath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_gameobject_remote'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: alloc_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_alloc_msg00
static int tolua_neox_Node_alloc_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'alloc_msg'",NULL);
#endif
  {
   Message* tolua_ret = (Message*)  self->alloc_msg();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Message");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'alloc_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_destory_msg00
static int tolua_neox_Node_destory_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_msg'",NULL);
#endif
  {
   self->destory_msg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_retain_msg00
static int tolua_neox_Node_retain_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain_msg'",NULL);
#endif
  {
   self->retain_msg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_recv00
static int tolua_neox_Node_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   self->recv(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv_gameobject_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_recv_gameobject_msg00
static int tolua_neox_Node_recv_gameobject_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_gameobject_msg'",NULL);
#endif
  {
   self->recv_gameobject_msg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_gameobject_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv_node_reg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_recv_node_reg00
static int tolua_neox_Node_recv_node_reg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_node_reg'",NULL);
#endif
  {
   self->recv_node_reg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_node_reg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv_create_gameobject of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_recv_create_gameobject00
static int tolua_neox_Node_recv_create_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_create_gameobject'",NULL);
#endif
  {
   self->recv_create_gameobject(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_create_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_gameobject_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_send_gameobject_msg00
static int tolua_neox_Node_send_gameobject_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  GameObject* src_object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_gameobject_msg'",NULL);
#endif
  {
   self->send_gameobject_msg(src_object,msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_gameobject_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forward_gameobject_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_forward_gameobject_msg00
static int tolua_neox_Node_forward_gameobject_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forward_gameobject_msg'",NULL);
#endif
  {
   self->forward_gameobject_msg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forward_gameobject_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: post of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_post00
static int tolua_neox_Node_post00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'post'",NULL);
#endif
  {
return self->post(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'post'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: run_background of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_run_background00
static int tolua_neox_Node_run_background00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run_background'",NULL);
#endif
  {
   self->run_background();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run_background'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addtimer of class  Node */
#ifndef TOLUA_DISABLE_tolua_neox_Node_addtimer00
static int tolua_neox_Node_addtimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addtimer'",NULL);
#endif
  {
return self->addtimer(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addtimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: id of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_id
static int tolua_get_Node_id(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_id
static int tolua_set_Node_id(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_name
static int tolua_get_Node_name(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_name
static int tolua_set_Node_name(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->name,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::runloop */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_runloop00
static int tolua_neox_NodeMgr_runloop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NodeMgr::runloop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runloop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::find_node */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_find_node00
static int tolua_neox_NodeMgr_find_node00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   Node* tolua_ret = (Node*)  NodeMgr::find_node(nodeid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'find_node'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::create_temp_node */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_create_temp_node00
static int tolua_neox_NodeMgr_create_temp_node00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Node* tolua_ret = (Node*)  NodeMgr::create_temp_node();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_temp_node'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::create_node_local */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_create_node_local00
static int tolua_neox_NodeMgr_create_node_local00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   Node* tolua_ret = (Node*)  NodeMgr::create_node_local(nodeid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_node_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::create_node_remote */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_create_node_remote00
static int tolua_neox_NodeMgr_create_node_remote00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   Node* tolua_ret = (Node*)  NodeMgr::create_node_remote(nodeid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_node_remote'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::transfer_gameobject */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_transfer_gameobject00
static int tolua_neox_NodeMgr_transfer_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* src_object = ((GameObject*)  tolua_tousertype(tolua_S,1,0));
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   NodeMgr::transfer_gameobject(src_object,dst_nodeid);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transfer_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::create_gameobject_remote */
#ifndef TOLUA_DISABLE_tolua_neox_NodeMgr_create_gameobject_remote00
static int tolua_neox_NodeMgr_create_gameobject_remote00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* src_object = ((GameObject*)  tolua_tousertype(tolua_S,1,0));
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   NodeMgr::create_gameobject_remote(src_object,dst_nodeid,filepath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_gameobject_remote'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: center_node of class  Router */
#ifndef TOLUA_DISABLE_tolua_get_Router_center_node_ptr
static int tolua_get_Router_center_node_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)Router::center_node,"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: center_node of class  Router */
#ifndef TOLUA_DISABLE_tolua_set_Router_center_node_ptr
static int tolua_set_Router_center_node_ptr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Router::center_node = ((Node*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_new00
static int tolua_neox_Component_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Component* tolua_ret = (Component*)  new Component();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
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

/* method: new_local of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_new00_local
static int tolua_neox_Component_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Component* tolua_ret = (Component*)  new Component();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Component");
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

/* method: delete of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_delete00
static int tolua_neox_Component_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_awake00
static int tolua_neox_Component_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
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

/* method: destory of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_destory00
static int tolua_neox_Component_destory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory'",NULL);
#endif
  {
   self->destory();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_update00
static int tolua_neox_Component_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  uint64_t cur_tick = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
  {
   self->update(cur_tick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_recv00
static int tolua_neox_Component_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
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

/* method: unreach of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_unreach00
static int tolua_neox_Component_unreach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreach'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreach(msg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unreach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_pushfunction of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_lua_pushfunction00
static int tolua_neox_Component_lua_pushfunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  const char* func = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_pushfunction'",NULL);
#endif
  {
   int tolua_ret = (int)  self->lua_pushfunction(func);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_pushfunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_printstack of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_lua_printstack00
static int tolua_neox_Component_lua_printstack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_printstack'",NULL);
#endif
  {
   int tolua_ret = (int)  self->lua_printstack();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_printstack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_getstring of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_lua_getstring00
static int tolua_neox_Component_lua_getstring00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  const char* fieldname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_getstring'",NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->lua_getstring(fieldname);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_getstring'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_getnumber of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_lua_getnumber00
static int tolua_neox_Component_lua_getnumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  const char* fieldname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_getnumber'",NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->lua_getnumber(fieldname);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_getnumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_gameobject of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_get_gameobject00
static int tolua_neox_Component_get_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_gameobject'",NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->get_gameobject();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_gameobject of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_set_gameobject00
static int tolua_neox_Component_set_gameobject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_gameobject'",NULL);
#endif
  {
   self->set_gameobject(object);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_gameobject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_node of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_get_node00
static int tolua_neox_Component_get_node00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_node'",NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->get_node();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_node'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_file_event of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_create_file_event00
static int tolua_neox_Component_create_file_event00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"aeFileProc",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int fd = ((int)  tolua_tonumber(tolua_S,2,0));
  int mask = ((int)  tolua_tonumber(tolua_S,3,0));
  aeFileProc* proc = ((aeFileProc*)  tolua_tousertype(tolua_S,4,0));
  void* clientData = ((void*)  tolua_touserdata(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_file_event'",NULL);
#endif
  {
   int tolua_ret = (int)  self->create_file_event(fd,mask,proc,clientData);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_file_event'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete_file_event of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_delete_file_event00
static int tolua_neox_Component_delete_file_event00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int fd = ((int)  tolua_tonumber(tolua_S,2,0));
  int mask = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete_file_event'",NULL);
#endif
  {
   self->delete_file_event(fd,mask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete_file_event'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reg_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_reg_msg00
static int tolua_neox_Component_reg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  unsigned int id = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reg_msg'",NULL);
#endif
  {
   int tolua_ret = (int)  self->reg_msg(id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reg_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unreg_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_unreg_msg00
static int tolua_neox_Component_unreg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  unsigned int id = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreg_msg'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreg_msg(id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unreg_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_gameobject_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_send_gameobject_msg00
static int tolua_neox_Component_send_gameobject_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  int dst_objectid = ((int)  tolua_tonumber(tolua_S,3,0));
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_gameobject_msg'",NULL);
#endif
  {
   self->send_gameobject_msg(dst_nodeid,dst_objectid,msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_gameobject_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_gameobject_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_send_gameobject_msg01
static int tolua_neox_Component_send_gameobject_msg01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"const Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  int dst_objectid = ((int)  tolua_tonumber(tolua_S,3,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,4,0));
  const Buffer* buffer = ((const Buffer*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_gameobject_msg'",NULL);
#endif
  {
   self->send_gameobject_msg(dst_nodeid,dst_objectid,msgid,buffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_neox_Component_send_gameobject_msg00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_get_component00
static int tolua_neox_Component_get_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
return self->get_component(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_component'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: alloc_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_alloc_msg00
static int tolua_neox_Component_alloc_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'alloc_msg'",NULL);
#endif
  {
   Message* tolua_ret = (Message*)  self->alloc_msg();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Message");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'alloc_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destory_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_destory_msg00
static int tolua_neox_Component_destory_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  Message* msg = ((Message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destory_msg'",NULL);
#endif
  {
   self->destory_msg(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destory_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  Component */
#ifndef TOLUA_DISABLE_tolua_neox_Component_get_component01
static int tolua_neox_Component_get_component01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->get_component(name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Component_get_component00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gameobject of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_gameobject_ptr
static int tolua_get_Component_gameobject_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gameobject'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->gameobject,"GameObject");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gameobject of class  Component */
#ifndef TOLUA_DISABLE_tolua_set_Component_gameobject_ptr
static int tolua_set_Component_gameobject_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gameobject'",NULL);
  if (!tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->gameobject = ((GameObject*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_new00
static int tolua_neox_ScriptComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* modname = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ScriptComponent* tolua_ret = (ScriptComponent*)  new ScriptComponent(modname);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScriptComponent");
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

/* method: new_local of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_new00_local
static int tolua_neox_ScriptComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* modname = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ScriptComponent* tolua_ret = (ScriptComponent*)  new ScriptComponent(modname);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"ScriptComponent");
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

/* method: delete of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_delete00
static int tolua_neox_ScriptComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_awake00
static int tolua_neox_ScriptComponent_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_update00
static int tolua_neox_ScriptComponent_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
  uint64_t cur_tick = ((uint64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
  {
   self->update(cur_tick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_recv00
static int tolua_neox_ScriptComponent_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addtimer of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_neox_ScriptComponent_addtimer00
static int tolua_neox_ScriptComponent_addtimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addtimer'",NULL);
#endif
  {
return self->addtimer(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addtimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modname of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_get_ScriptComponent_modname
static int tolua_get_ScriptComponent_modname(lua_State* tolua_S)
{
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modname'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->modname);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modname of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_set_ScriptComponent_modname
static int tolua_set_ScriptComponent_modname(lua_State* tolua_S)
{
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modname'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->modname,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_new00
static int tolua_neox_NetComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetComponent* tolua_ret = (NetComponent*)  new NetComponent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetComponent");
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

/* method: new_local of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_new00_local
static int tolua_neox_NetComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetComponent* tolua_ret = (NetComponent*)  new NetComponent();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"NetComponent");
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

/* method: delete of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_delete00
static int tolua_neox_NetComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_update00
static int tolua_neox_NetComponent_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  long long cur_tick = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
  {
   self->update(cur_tick);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: listen of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_listen00
static int tolua_neox_NetComponent_listen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* host = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'listen'",NULL);
#endif
  {
   int tolua_ret = (int)  self->listen(host,port);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'listen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_send00
static int tolua_neox_NetComponent_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send(sockfd,data,size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: send_str of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_send_str00
static int tolua_neox_NetComponent_send_str00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_str'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_str(sockfd,data);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_str'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: alloc_send_buf of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_alloc_send_buf00
static int tolua_neox_NetComponent_alloc_send_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'alloc_send_buf'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->alloc_send_buf(sockfd,size);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'alloc_send_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flush_send_buf of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_flush_send_buf00
static int tolua_neox_NetComponent_flush_send_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
  char* buf = ((char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flush_send_buf'",NULL);
#endif
  {
   self->flush_send_buf(sockfd,buf,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flush_send_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: awake of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_neox_NetComponent_awake00
static int tolua_neox_NetComponent_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: host of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_get_NetComponent_host
static int tolua_get_NetComponent_host(lua_State* tolua_S)
{
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'host'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->host);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: host of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_set_NetComponent_host
static int tolua_set_NetComponent_host(lua_State* tolua_S)
{
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'host'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->host,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: port of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_get_NetComponent_port
static int tolua_get_NetComponent_port(lua_State* tolua_S)
{
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->port);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: port of class  NetComponent */
#ifndef TOLUA_DISABLE_tolua_set_NetComponent_port
static int tolua_set_NetComponent_port(lua_State* tolua_S)
{
  NetComponent* self = (NetComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->port = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_new00
static int tolua_neox_HttpComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpComponent* tolua_ret = (HttpComponent*)  new HttpComponent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpComponent");
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

/* method: new_local of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_new00_local
static int tolua_neox_HttpComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HttpComponent* tolua_ret = (HttpComponent*)  new HttpComponent();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"HttpComponent");
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

/* method: delete of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_delete00
static int tolua_neox_HttpComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: recv of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_recv00
static int tolua_neox_HttpComponent_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_awake00
static int tolua_neox_HttpComponent_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: send_binary_frame of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_binary_frame00
static int tolua_neox_HttpComponent_send_binary_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  int sid = ((int)  tolua_tonumber(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  unsigned short datalen = ((unsigned short)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_binary_frame'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_binary_frame(sid,data,datalen);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_binary_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_binary_frame of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_binary_frame01
static int tolua_neox_HttpComponent_send_binary_frame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  int sid = ((int)  tolua_tonumber(tolua_S,2,0));
  Buffer* buffer = ((Buffer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_binary_frame'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_binary_frame(sid,buffer);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_HttpComponent_send_binary_frame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_string_frame of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_string_frame00
static int tolua_neox_HttpComponent_send_string_frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  int sid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* str = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_string_frame'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_string_frame(sid,str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_string_frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_string of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_string00
static int tolua_neox_HttpComponent_send_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  int sid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* str = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_string'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_string(sid,str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_string of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_string01
static int tolua_neox_HttpComponent_send_string01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_string'",NULL);
#endif
  {
return self->send_string(L);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_HttpComponent_send_string00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_buffer of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_neox_HttpComponent_send_buffer00
static int tolua_neox_HttpComponent_send_buffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  int sid = ((int)  tolua_tonumber(tolua_S,2,0));
  Buffer* buffer = ((Buffer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_buffer'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send_buffer(sid,buffer);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_buffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  POSTComponent */
#ifndef TOLUA_DISABLE_tolua_neox_POSTComponent_new00
static int tolua_neox_POSTComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"POSTComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   POSTComponent* tolua_ret = (POSTComponent*)  new POSTComponent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"POSTComponent");
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

/* method: new_local of class  POSTComponent */
#ifndef TOLUA_DISABLE_tolua_neox_POSTComponent_new00_local
static int tolua_neox_POSTComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"POSTComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   POSTComponent* tolua_ret = (POSTComponent*)  new POSTComponent();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"POSTComponent");
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

/* method: delete of class  POSTComponent */
#ifndef TOLUA_DISABLE_tolua_neox_POSTComponent_delete00
static int tolua_neox_POSTComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"POSTComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  POSTComponent* self = (POSTComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: len of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_len
static int tolua_get_MessageHeader_len(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'len'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->len);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: len of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_len
static int tolua_set_MessageHeader_len(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'len'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->len = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: src_objectid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_src_objectid
static int tolua_get_MessageHeader_src_objectid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src_objectid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->src_objectid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: src_objectid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_src_objectid
static int tolua_set_MessageHeader_src_objectid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src_objectid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->src_objectid = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: src_nodeid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_src_nodeid
static int tolua_get_MessageHeader_src_nodeid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src_nodeid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->src_nodeid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: src_nodeid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_src_nodeid
static int tolua_set_MessageHeader_src_nodeid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'src_nodeid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->src_nodeid = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dst_objectid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_dst_objectid
static int tolua_get_MessageHeader_dst_objectid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst_objectid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dst_objectid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dst_objectid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_dst_objectid
static int tolua_set_MessageHeader_dst_objectid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst_objectid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dst_objectid = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dst_nodeid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_dst_nodeid
static int tolua_get_MessageHeader_dst_nodeid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst_nodeid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dst_nodeid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dst_nodeid of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_dst_nodeid
static int tolua_set_MessageHeader_dst_nodeid(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dst_nodeid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dst_nodeid = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: id of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_get_MessageHeader_id
static int tolua_get_MessageHeader_id(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  MessageHeader */
#ifndef TOLUA_DISABLE_tolua_set_MessageHeader_id
static int tolua_set_MessageHeader_id(lua_State* tolua_S)
{
  MessageHeader* self = (MessageHeader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cache of class  MessageOption */
#ifndef TOLUA_DISABLE_tolua_get_MessageOption_cache
static int tolua_get_MessageOption_cache(lua_State* tolua_S)
{
  MessageOption* self = (MessageOption*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cache'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->cache);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cache of class  MessageOption */
#ifndef TOLUA_DISABLE_tolua_set_MessageOption_cache
static int tolua_set_MessageOption_cache(lua_State* tolua_S)
{
  MessageOption* self = (MessageOption*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cache'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cache = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: alloc_count of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_alloc_count
static int tolua_get_Message_alloc_count(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Message::alloc_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: alloc_count of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_alloc_count
static int tolua_set_Message_alloc_count(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Message::alloc_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Message */
#ifndef TOLUA_DISABLE_tolua_neox_Message_new00
static int tolua_neox_Message_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Message* tolua_ret = (Message*)  new Message();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Message");
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

/* method: new_local of class  Message */
#ifndef TOLUA_DISABLE_tolua_neox_Message_new00_local
static int tolua_neox_Message_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Message* tolua_ret = (Message*)  new Message();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Message");
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

/* method: delete of class  Message */
#ifndef TOLUA_DISABLE_tolua_neox_Message_delete00
static int tolua_neox_Message_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: magic_code of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_magic_code
static int tolua_get_Message_magic_code(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_code'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magic_code);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magic_code of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_magic_code
static int tolua_set_Message_magic_code(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_code'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magic_code = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: header of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_header
static int tolua_get_Message_header(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'header'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->header,"MessageHeader");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: header of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_header
static int tolua_set_Message_header(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'header'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MessageHeader",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->header = *((MessageHeader*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: magic_code2 of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_magic_code2
static int tolua_get_Message_magic_code2(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_code2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->magic_code2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: magic_code2 of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_magic_code2
static int tolua_set_Message_magic_code2(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'magic_code2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->magic_code2 = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: option of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_option
static int tolua_get_Message_option(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'option'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->option,"MessageOption");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: option of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_option
static int tolua_set_Message_option(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'option'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MessageOption",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->option = *((MessageOption*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: byte_sent of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_byte_sent
static int tolua_get_Message_byte_sent(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'byte_sent'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->byte_sent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: byte_sent of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_byte_sent
static int tolua_set_Message_byte_sent(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'byte_sent'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->byte_sent = ((uint32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sockfd of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_sockfd
static int tolua_get_Message_sockfd(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sockfd'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->sockfd);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sockfd of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_sockfd
static int tolua_set_Message_sockfd(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sockfd'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sockfd = ((int32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sid of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_sid
static int tolua_get_Message_sid(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sid'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->sid);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sid of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_sid
static int tolua_set_Message_sid(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sid'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sid = ((int32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ref_count of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_ref_count
static int tolua_get_Message_ref_count(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ref_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ref_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ref_count of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_ref_count
static int tolua_set_Message_ref_count(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ref_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ref_count = ((int32_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: payload of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_payload
static int tolua_get_Message_payload(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'payload'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->payload,"Buffer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: payload of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_payload
static int tolua_set_Message_payload(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'payload'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Buffer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->payload = *((Buffer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: data of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_data
static int tolua_get_Message_data(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->data);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: data of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_data
static int tolua_set_Message_data(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->data = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: datalen of class  Message */
#ifndef TOLUA_DISABLE_tolua_get_Message_datalen
static int tolua_get_Message_datalen(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'datalen'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->datalen);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: datalen of class  Message */
#ifndef TOLUA_DISABLE_tolua_set_Message_datalen
static int tolua_set_Message_datalen(lua_State* tolua_S)
{
  Message* self = (Message*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'datalen'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->datalen = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: len of class  CreateGameObjectMsg */
#ifndef TOLUA_DISABLE_tolua_get_CreateGameObjectMsg_len
static int tolua_get_CreateGameObjectMsg_len(lua_State* tolua_S)
{
  CreateGameObjectMsg* self = (CreateGameObjectMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'len'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->len);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: len of class  CreateGameObjectMsg */
#ifndef TOLUA_DISABLE_tolua_set_CreateGameObjectMsg_len
static int tolua_set_CreateGameObjectMsg_len(lua_State* tolua_S)
{
  CreateGameObjectMsg* self = (CreateGameObjectMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'len'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->len = ((uint16_t)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: filepath of class  CreateGameObjectMsg */
#ifndef TOLUA_DISABLE_tolua_get_CreateGameObjectMsg_filepath
static int tolua_get_CreateGameObjectMsg_filepath(lua_State* tolua_S)
{
  CreateGameObjectMsg* self = (CreateGameObjectMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filepath'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->filepath);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: filepath of class  CreateGameObjectMsg */
#ifndef TOLUA_DISABLE_tolua_set_CreateGameObjectMsg_filepath
static int tolua_set_CreateGameObjectMsg_filepath(lua_State* tolua_S)
{
  CreateGameObjectMsg* self = (CreateGameObjectMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filepath'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->filepath,tolua_tostring(tolua_S,2,0),64-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new00
static int tolua_neox_Buffer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Buffer");
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

/* method: new_local of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new00_local
static int tolua_neox_Buffer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Buffer");
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

/* method: new of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new01
static int tolua_neox_Buffer_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  uint32_t init_size = ((uint32_t)  tolua_tonumber(tolua_S,2,0));
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer(init_size);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Buffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Buffer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new01_local
static int tolua_neox_Buffer_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  uint32_t init_size = ((uint32_t)  tolua_tonumber(tolua_S,2,0));
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer(init_size);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Buffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Buffer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new02
static int tolua_neox_Buffer_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const void* buf = ((const void*)  tolua_touserdata(tolua_S,2,0));
  uint32_t buflen = ((uint32_t)  tolua_tonumber(tolua_S,3,0));
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer(buf,buflen);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Buffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Buffer_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_new02_local
static int tolua_neox_Buffer_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const void* buf = ((const void*)  tolua_touserdata(tolua_S,2,0));
  uint32_t buflen = ((uint32_t)  tolua_tonumber(tolua_S,3,0));
  {
   Buffer* tolua_ret = (Buffer*)  new Buffer(buf,buflen);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Buffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Buffer_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_delete00
static int tolua_neox_Buffer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: read_int64 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_int6400
static int tolua_neox_Buffer_read_int6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int64_t def = ((int64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_int64'",NULL);
#endif
  {
   int64_t tolua_ret = (int64_t)  self->read_int64(def);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_int64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_int32 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_int3200
static int tolua_neox_Buffer_read_int3200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int32_t def = ((int32_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_int32'",NULL);
#endif
  {
   int32_t tolua_ret = (int32_t)  self->read_int32(def);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_int32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_int16 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_int1600
static int tolua_neox_Buffer_read_int1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int16_t def = ((int16_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_int16'",NULL);
#endif
  {
   int16_t tolua_ret = (int16_t)  self->read_int16(def);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_int16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_int8 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_int800
static int tolua_neox_Buffer_read_int800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int8_t def = ((int8_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_int8'",NULL);
#endif
  {
   int8_t tolua_ret = (int8_t)  self->read_int8(def);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_int8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_buf of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_buf00
static int tolua_neox_Buffer_read_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  void* data = ((void*)  tolua_touserdata(tolua_S,2,0));
  uint32_t datalen = ((uint32_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_buf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->read_buf(data,datalen);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_utf8 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_utf800
static int tolua_neox_Buffer_read_utf800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_utf8'",NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->read_utf8();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_utf8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read_protobuf of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_read_protobuf00
static int tolua_neox_Buffer_read_protobuf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read_protobuf'",NULL);
#endif
  {
return self->read_protobuf(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read_protobuf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_utf8 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_utf800
static int tolua_neox_Buffer_write_utf800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
  uint16_t str_len = ((uint16_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_utf8'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_utf8(str,str_len);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_utf8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_utf8 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_utf801
static int tolua_neox_Buffer_write_utf801(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_utf8'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_utf8(str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_neox_Buffer_write_utf800(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_int64 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_int6400
static int tolua_neox_Buffer_write_int6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int64_t val = ((int64_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_int64'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_int64(val);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_int64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_int32 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_int3200
static int tolua_neox_Buffer_write_int3200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int32_t val = ((int32_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_int32'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_int32(val);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_int32'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_int16 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_int1600
static int tolua_neox_Buffer_write_int1600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int16_t val = ((int16_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_int16'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_int16(val);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_int16'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_int8 of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_int800
static int tolua_neox_Buffer_write_int800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int8_t val = ((int8_t)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_int8'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_int8(val);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_int8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_buf of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_buf00
static int tolua_neox_Buffer_write_buf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  const void* data = ((const void*)  tolua_touserdata(tolua_S,2,0));
  uint32_t datalen = ((uint32_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_buf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write_buf(data,datalen);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_buf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_string of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_string00
static int tolua_neox_Buffer_write_string00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_string'",NULL);
#endif
  {
return self->write_string(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_string'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write00
static int tolua_neox_Buffer_write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  const Buffer* other = ((const Buffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'",NULL);
#endif
  {
   int tolua_ret = (int)  self->write(other);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write_protobuf of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_write_protobuf00
static int tolua_neox_Buffer_write_protobuf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  lua_State* L =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write_protobuf'",NULL);
#endif
  {
return self->write_protobuf(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write_protobuf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: buf2line of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_buf2line00
static int tolua_neox_Buffer_buf2line00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'buf2line'",NULL);
#endif
  {
   self->buf2line();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'buf2line'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: already_read of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_already_read00
static int tolua_neox_Buffer_already_read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'already_read'",NULL);
#endif
  {
   uint32_t tolua_ret = (uint32_t)  self->already_read();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'already_read'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_size00
static int tolua_neox_Buffer_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Buffer* self = (const Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'",NULL);
#endif
  {
   uint32_t tolua_ret = (uint32_t)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: maxsize of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_maxsize00
static int tolua_neox_Buffer_maxsize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'maxsize'",NULL);
#endif
  {
   uint32_t tolua_ret = (uint32_t)  self->maxsize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maxsize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_reset00
static int tolua_neox_Buffer_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
  {
   self->reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_buffer of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_get_buffer00
static int tolua_neox_Buffer_get_buffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Buffer* self = (const Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_buffer'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->get_buffer();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_buffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_write_buffer of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_get_write_buffer00
static int tolua_neox_Buffer_get_write_buffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Buffer* self = (const Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_write_buffer'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->get_write_buffer();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_write_buffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ensure_size of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_ensure_size00
static int tolua_neox_Buffer_ensure_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ensure_size'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ensure_size(size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ensure_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: debug of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_debug00
static int tolua_neox_Buffer_debug00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Buffer* self = (Buffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'debug'",NULL);
#endif
  {
   self->debug();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'debug'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: temp of class  Buffer */
#ifndef TOLUA_DISABLE_tolua_neox_Buffer_temp00
static int tolua_neox_Buffer_temp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Buffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Buffer* tolua_ret = (Buffer*)  Buffer::temp();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Buffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'temp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::getcwd */
#ifndef TOLUA_DISABLE_tolua_neox_File_getcwd00
static int tolua_neox_File_getcwd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   char* tolua_ret = (char*)  File::getcwd();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getcwd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::chdir */
#ifndef TOLUA_DISABLE_tolua_neox_File_chdir00
static int tolua_neox_File_chdir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* dir = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  File::chdir(dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'chdir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::mkdirs */
#ifndef TOLUA_DISABLE_tolua_neox_File_mkdirs00
static int tolua_neox_File_mkdirs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* dir = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  File::mkdirs(dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mkdirs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::mkdir */
#ifndef TOLUA_DISABLE_tolua_neox_File_mkdir00
static int tolua_neox_File_mkdir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* dir = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  File::mkdir(dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mkdir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::exists */
#ifndef TOLUA_DISABLE_tolua_neox_File_exists00
static int tolua_neox_File_exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* dir = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  File::exists(dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'exists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::remove */
#ifndef TOLUA_DISABLE_tolua_neox_File_remove00
static int tolua_neox_File_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* dir = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   bool tolua_ret = (bool)  File::remove(dir);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::rename */
#ifndef TOLUA_DISABLE_tolua_neox_File_rename00
static int tolua_neox_File_rename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* src = ((char*)  tolua_tostring(tolua_S,1,0));
  char* dst = ((char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  File::rename(src,dst);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::basename */
#ifndef TOLUA_DISABLE_tolua_neox_File_basename00
static int tolua_neox_File_basename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  lua_State* L =  tolua_S;
  {
return File::basename(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'basename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::extname */
#ifndef TOLUA_DISABLE_tolua_neox_File_extname00
static int tolua_neox_File_extname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  lua_State* L =  tolua_S;
  {
return File::extname(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'extname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::dirname */
#ifndef TOLUA_DISABLE_tolua_neox_File_dirname00
static int tolua_neox_File_dirname00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   const char* tolua_ret = (const char*)  File::dirname(path);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dirname'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::listdir */
#ifndef TOLUA_DISABLE_tolua_neox_File_listdir00
static int tolua_neox_File_listdir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     false
 )
  goto tolua_lerror;
 else
#endif
 {
  lua_State* L =  tolua_S;
  {
return File::listdir(L);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'listdir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: File::cdself */
#ifndef TOLUA_DISABLE_tolua_neox_File_cdself00
static int tolua_neox_File_cdself00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  File::cdself();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cdself'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Transform */
#ifndef TOLUA_DISABLE_tolua_neox_Transform_new00
static int tolua_neox_Transform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Transform* tolua_ret = (Transform*)  new Transform();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Transform");
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

/* method: new_local of class  Transform */
#ifndef TOLUA_DISABLE_tolua_neox_Transform_new00_local
static int tolua_neox_Transform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Transform* tolua_ret = (Transform*)  new Transform();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Transform");
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

/* method: delete of class  Transform */
#ifndef TOLUA_DISABLE_tolua_neox_Transform_delete00
static int tolua_neox_Transform_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_neox_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Neox",0);
  tolua_beginmodule(tolua_S,"Neox");
   tolua_function(tolua_S,"main",tolua_neox_Neox_main00);
   tolua_function(tolua_S,"create_node_remote",tolua_neox_Neox_create_node_remote00);
   tolua_function(tolua_S,"create_gameobject_local",tolua_neox_Neox_create_gameobject_local00);
   tolua_function(tolua_S,"fork_daemon",tolua_neox_Neox_fork_daemon00);
   tolua_function(tolua_S,"loop",tolua_neox_Neox_loop00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Type","Type","",tolua_collect_Type);
  #else
  tolua_cclass(tolua_S,"Type","Type","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Type");
   tolua_function(tolua_S,"new",tolua_neox_Type_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Type_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Type_new00_local);
   tolua_variable(tolua_S,"name",tolua_get_Type_name,tolua_set_Type_name);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HttpClient","HttpClient","",tolua_collect_HttpClient);
  #else
  tolua_cclass(tolua_S,"HttpClient","HttpClient","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HttpClient");
   tolua_function(tolua_S,"new",tolua_neox_HttpClient_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_HttpClient_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_HttpClient_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_HttpClient_delete00);
   tolua_function(tolua_S,"connect",tolua_neox_HttpClient_connect00);
   tolua_function(tolua_S,"is_connect",tolua_neox_HttpClient_is_connect00);
   tolua_function(tolua_S,"send",tolua_neox_HttpClient_send00);
   tolua_function(tolua_S,"recv",tolua_neox_HttpClient_recv00);
   tolua_function(tolua_S,"recv_frame",tolua_neox_HttpClient_recv_frame00);
   tolua_function(tolua_S,"close",tolua_neox_HttpClient_close00);
   tolua_function(tolua_S,"send_open_websock",tolua_neox_HttpClient_send_open_websock00);
   tolua_function(tolua_S,"send_binary_frame",tolua_neox_HttpClient_send_binary_frame00);
   tolua_function(tolua_S,"send_binary_frame",tolua_neox_HttpClient_send_binary_frame01);
   tolua_function(tolua_S,"send_string_frame",tolua_neox_HttpClient_send_string_frame00);
   tolua_function(tolua_S,"send_frame",tolua_neox_HttpClient_send_frame00);
   tolua_variable(tolua_S,"buffer",tolua_get_HttpClient_buffer,tolua_set_HttpClient_buffer);
   tolua_variable(tolua_S,"content_length",tolua_get_HttpClient_content_length,tolua_set_HttpClient_content_length);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GameObject","GameObject","",tolua_collect_GameObject);
  #else
  tolua_cclass(tolua_S,"GameObject","GameObject","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GameObject");
   tolua_function(tolua_S,"new",tolua_neox_GameObject_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_GameObject_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_GameObject_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_GameObject_delete00);
   tolua_function(tolua_S,"test",tolua_neox_GameObject_test00);
   tolua_function(tolua_S,"create",tolua_neox_GameObject_create00);
   tolua_function(tolua_S,"save",tolua_neox_GameObject_save00);
   tolua_function(tolua_S,"update",tolua_neox_GameObject_update00);
   tolua_function(tolua_S,"awake",tolua_neox_GameObject_awake00);
   tolua_function(tolua_S,"destory",tolua_neox_GameObject_destory00);
   tolua_function(tolua_S,"recv",tolua_neox_GameObject_recv00);
   tolua_function(tolua_S,"unreach",tolua_neox_GameObject_unreach00);
   tolua_function(tolua_S,"add_component",tolua_neox_GameObject_add_component00);
   tolua_function(tolua_S,"add_script",tolua_neox_GameObject_add_script00);
   tolua_function(tolua_S,"del_component",tolua_neox_GameObject_del_component00);
   tolua_function(tolua_S,"get_component",tolua_neox_GameObject_get_component00);
   tolua_function(tolua_S,"get_component",tolua_neox_GameObject_get_component01);
   tolua_function(tolua_S,"get_component",tolua_neox_GameObject_get_component02);
   tolua_function(tolua_S,"get_script",tolua_neox_GameObject_get_script00);
   tolua_function(tolua_S,"reg_msg",tolua_neox_GameObject_reg_msg00);
   tolua_function(tolua_S,"unreg_msg",tolua_neox_GameObject_unreg_msg00);
   tolua_function(tolua_S,"get_child",tolua_neox_GameObject_get_child00);
   tolua_function(tolua_S,"add_child",tolua_neox_GameObject_add_child00);
   tolua_function(tolua_S,"del_child",tolua_neox_GameObject_del_child00);
   tolua_function(tolua_S,"del_child",tolua_neox_GameObject_del_child01);
   tolua_function(tolua_S,"child_index",tolua_neox_GameObject_child_index00);
   tolua_function(tolua_S,"get_parent",tolua_neox_GameObject_get_parent00);
   tolua_function(tolua_S,"obj_dump",tolua_neox_GameObject_obj_dump00);
   tolua_variable(tolua_S,"id",tolua_get_GameObject_id,tolua_set_GameObject_id);
   tolua_variable(tolua_S,"data",tolua_get_GameObject_data,tolua_set_GameObject_data);
   tolua_variable(tolua_S,"node",tolua_get_GameObject_node_ptr,tolua_set_GameObject_node_ptr);
   tolua_variable(tolua_S,"name",tolua_get_GameObject_name,tolua_set_GameObject_name);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Node","Node","",tolua_collect_Node);
  #else
  tolua_cclass(tolua_S,"Node","Node","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Node");
   tolua_function(tolua_S,"new",tolua_neox_Node_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Node_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Node_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_Node_delete00);
   tolua_function(tolua_S,"main",tolua_neox_Node_main00);
   tolua_function(tolua_S,"update",tolua_neox_Node_update00);
   tolua_function(tolua_S,"connect",tolua_neox_Node_connect00);
   tolua_function(tolua_S,"listen",tolua_neox_Node_listen00);
   tolua_function(tolua_S,"find_gameobject",tolua_neox_Node_find_gameobject00);
   tolua_function(tolua_S,"add_gameobject",tolua_neox_Node_add_gameobject00);
   tolua_function(tolua_S,"get_id",tolua_neox_Node_get_id00);
   tolua_function(tolua_S,"is_local",tolua_neox_Node_is_local00);
   tolua_function(tolua_S,"set_local",tolua_neox_Node_set_local00);
   tolua_function(tolua_S,"is_disconnect",tolua_neox_Node_is_disconnect00);
   tolua_function(tolua_S,"create_gameobject_local",tolua_neox_Node_create_gameobject_local00);
   tolua_function(tolua_S,"create_gameobject_remote",tolua_neox_Node_create_gameobject_remote00);
   tolua_function(tolua_S,"alloc_msg",tolua_neox_Node_alloc_msg00);
   tolua_function(tolua_S,"destory_msg",tolua_neox_Node_destory_msg00);
   tolua_function(tolua_S,"retain_msg",tolua_neox_Node_retain_msg00);
   tolua_function(tolua_S,"recv",tolua_neox_Node_recv00);
   tolua_function(tolua_S,"recv_gameobject_msg",tolua_neox_Node_recv_gameobject_msg00);
   tolua_function(tolua_S,"recv_node_reg",tolua_neox_Node_recv_node_reg00);
   tolua_function(tolua_S,"recv_create_gameobject",tolua_neox_Node_recv_create_gameobject00);
   tolua_function(tolua_S,"send_gameobject_msg",tolua_neox_Node_send_gameobject_msg00);
   tolua_function(tolua_S,"forward_gameobject_msg",tolua_neox_Node_forward_gameobject_msg00);
   tolua_function(tolua_S,"post",tolua_neox_Node_post00);
   tolua_function(tolua_S,"run_background",tolua_neox_Node_run_background00);
   tolua_function(tolua_S,"addtimer",tolua_neox_Node_addtimer00);
   tolua_variable(tolua_S,"id",tolua_get_Node_id,tolua_set_Node_id);
   tolua_variable(tolua_S,"name",tolua_get_Node_name,tolua_set_Node_name);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"NodeMgr",0);
  tolua_beginmodule(tolua_S,"NodeMgr");
   tolua_function(tolua_S,"runloop",tolua_neox_NodeMgr_runloop00);
   tolua_function(tolua_S,"find_node",tolua_neox_NodeMgr_find_node00);
   tolua_function(tolua_S,"create_temp_node",tolua_neox_NodeMgr_create_temp_node00);
   tolua_function(tolua_S,"create_node_local",tolua_neox_NodeMgr_create_node_local00);
   tolua_function(tolua_S,"create_node_remote",tolua_neox_NodeMgr_create_node_remote00);
   tolua_function(tolua_S,"transfer_gameobject",tolua_neox_NodeMgr_transfer_gameobject00);
   tolua_function(tolua_S,"create_gameobject_remote",tolua_neox_NodeMgr_create_gameobject_remote00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Router","Router","",NULL);
  tolua_beginmodule(tolua_S,"Router");
   tolua_variable(tolua_S,"center_node",tolua_get_Router_center_node_ptr,tolua_set_Router_center_node_ptr);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Component","Component","",tolua_collect_Component);
  #else
  tolua_cclass(tolua_S,"Component","Component","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Component");
   tolua_function(tolua_S,"new",tolua_neox_Component_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Component_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Component_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_Component_delete00);
   tolua_function(tolua_S,"awake",tolua_neox_Component_awake00);
   tolua_function(tolua_S,"destory",tolua_neox_Component_destory00);
   tolua_function(tolua_S,"update",tolua_neox_Component_update00);
   tolua_function(tolua_S,"recv",tolua_neox_Component_recv00);
   tolua_function(tolua_S,"unreach",tolua_neox_Component_unreach00);
   tolua_function(tolua_S,"lua_pushfunction",tolua_neox_Component_lua_pushfunction00);
   tolua_function(tolua_S,"lua_printstack",tolua_neox_Component_lua_printstack00);
   tolua_function(tolua_S,"lua_getstring",tolua_neox_Component_lua_getstring00);
   tolua_function(tolua_S,"lua_getnumber",tolua_neox_Component_lua_getnumber00);
   tolua_function(tolua_S,"get_gameobject",tolua_neox_Component_get_gameobject00);
   tolua_function(tolua_S,"set_gameobject",tolua_neox_Component_set_gameobject00);
   tolua_function(tolua_S,"get_node",tolua_neox_Component_get_node00);
   tolua_function(tolua_S,"create_file_event",tolua_neox_Component_create_file_event00);
   tolua_function(tolua_S,"delete_file_event",tolua_neox_Component_delete_file_event00);
   tolua_function(tolua_S,"reg_msg",tolua_neox_Component_reg_msg00);
   tolua_function(tolua_S,"unreg_msg",tolua_neox_Component_unreg_msg00);
   tolua_function(tolua_S,"send_gameobject_msg",tolua_neox_Component_send_gameobject_msg00);
   tolua_function(tolua_S,"send_gameobject_msg",tolua_neox_Component_send_gameobject_msg01);
   tolua_function(tolua_S,"get_component",tolua_neox_Component_get_component00);
   tolua_function(tolua_S,"alloc_msg",tolua_neox_Component_alloc_msg00);
   tolua_function(tolua_S,"destory_msg",tolua_neox_Component_destory_msg00);
   tolua_function(tolua_S,"get_component",tolua_neox_Component_get_component01);
   tolua_variable(tolua_S,"gameobject",tolua_get_Component_gameobject_ptr,tolua_set_Component_gameobject_ptr);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ScriptComponent","ScriptComponent","Component",tolua_collect_ScriptComponent);
  #else
  tolua_cclass(tolua_S,"ScriptComponent","ScriptComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ScriptComponent");
   tolua_function(tolua_S,"new",tolua_neox_ScriptComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_ScriptComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_ScriptComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_ScriptComponent_delete00);
   tolua_function(tolua_S,"awake",tolua_neox_ScriptComponent_awake00);
   tolua_function(tolua_S,"update",tolua_neox_ScriptComponent_update00);
   tolua_function(tolua_S,"recv",tolua_neox_ScriptComponent_recv00);
   tolua_function(tolua_S,"addtimer",tolua_neox_ScriptComponent_addtimer00);
   tolua_variable(tolua_S,"modname",tolua_get_ScriptComponent_modname,tolua_set_ScriptComponent_modname);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"NetComponent","NetComponent","Component",tolua_collect_NetComponent);
  #else
  tolua_cclass(tolua_S,"NetComponent","NetComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"NetComponent");
   tolua_function(tolua_S,"new",tolua_neox_NetComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_NetComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_NetComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_NetComponent_delete00);
   tolua_function(tolua_S,"update",tolua_neox_NetComponent_update00);
   tolua_function(tolua_S,"listen",tolua_neox_NetComponent_listen00);
   tolua_function(tolua_S,"send",tolua_neox_NetComponent_send00);
   tolua_function(tolua_S,"send_str",tolua_neox_NetComponent_send_str00);
   tolua_function(tolua_S,"alloc_send_buf",tolua_neox_NetComponent_alloc_send_buf00);
   tolua_function(tolua_S,"flush_send_buf",tolua_neox_NetComponent_flush_send_buf00);
   tolua_function(tolua_S,"awake",tolua_neox_NetComponent_awake00);
   tolua_variable(tolua_S,"host",tolua_get_NetComponent_host,tolua_set_NetComponent_host);
   tolua_variable(tolua_S,"port",tolua_get_NetComponent_port,tolua_set_NetComponent_port);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HttpComponent","HttpComponent","Component",tolua_collect_HttpComponent);
  #else
  tolua_cclass(tolua_S,"HttpComponent","HttpComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HttpComponent");
   tolua_function(tolua_S,"new",tolua_neox_HttpComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_HttpComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_HttpComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_HttpComponent_delete00);
   tolua_function(tolua_S,"recv",tolua_neox_HttpComponent_recv00);
   tolua_function(tolua_S,"awake",tolua_neox_HttpComponent_awake00);
   tolua_function(tolua_S,"send_binary_frame",tolua_neox_HttpComponent_send_binary_frame00);
   tolua_function(tolua_S,"send_binary_frame",tolua_neox_HttpComponent_send_binary_frame01);
   tolua_function(tolua_S,"send_string_frame",tolua_neox_HttpComponent_send_string_frame00);
   tolua_function(tolua_S,"send_string",tolua_neox_HttpComponent_send_string00);
   tolua_function(tolua_S,"send_string",tolua_neox_HttpComponent_send_string01);
   tolua_function(tolua_S,"send_buffer",tolua_neox_HttpComponent_send_buffer00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"POSTComponent","POSTComponent","Component",tolua_collect_POSTComponent);
  #else
  tolua_cclass(tolua_S,"POSTComponent","POSTComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"POSTComponent");
   tolua_function(tolua_S,"new",tolua_neox_POSTComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_POSTComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_POSTComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_POSTComponent_delete00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MessageHeader","MessageHeader","",NULL);
  tolua_beginmodule(tolua_S,"MessageHeader");
   tolua_variable(tolua_S,"len",tolua_get_MessageHeader_len,tolua_set_MessageHeader_len);
   tolua_variable(tolua_S,"src_objectid",tolua_get_MessageHeader_src_objectid,tolua_set_MessageHeader_src_objectid);
   tolua_variable(tolua_S,"src_nodeid",tolua_get_MessageHeader_src_nodeid,tolua_set_MessageHeader_src_nodeid);
   tolua_variable(tolua_S,"dst_objectid",tolua_get_MessageHeader_dst_objectid,tolua_set_MessageHeader_dst_objectid);
   tolua_variable(tolua_S,"dst_nodeid",tolua_get_MessageHeader_dst_nodeid,tolua_set_MessageHeader_dst_nodeid);
   tolua_variable(tolua_S,"id",tolua_get_MessageHeader_id,tolua_set_MessageHeader_id);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MessageOption","MessageOption","",NULL);
  tolua_beginmodule(tolua_S,"MessageOption");
   tolua_variable(tolua_S,"cache",tolua_get_MessageOption_cache,tolua_set_MessageOption_cache);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Message","Message","",tolua_collect_Message);
  #else
  tolua_cclass(tolua_S,"Message","Message","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Message");
   tolua_variable(tolua_S,"alloc_count",tolua_get_Message_alloc_count,tolua_set_Message_alloc_count);
   tolua_function(tolua_S,"new",tolua_neox_Message_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Message_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Message_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_Message_delete00);
   tolua_variable(tolua_S,"magic_code",tolua_get_Message_magic_code,tolua_set_Message_magic_code);
   tolua_variable(tolua_S,"header",tolua_get_Message_header,tolua_set_Message_header);
   tolua_variable(tolua_S,"magic_code2",tolua_get_Message_magic_code2,tolua_set_Message_magic_code2);
   tolua_variable(tolua_S,"option",tolua_get_Message_option,tolua_set_Message_option);
   tolua_variable(tolua_S,"byte_sent",tolua_get_Message_byte_sent,tolua_set_Message_byte_sent);
   tolua_variable(tolua_S,"sockfd",tolua_get_Message_sockfd,tolua_set_Message_sockfd);
   tolua_variable(tolua_S,"sid",tolua_get_Message_sid,tolua_set_Message_sid);
   tolua_variable(tolua_S,"ref_count",tolua_get_Message_ref_count,tolua_set_Message_ref_count);
   tolua_variable(tolua_S,"payload",tolua_get_Message_payload,tolua_set_Message_payload);
   tolua_variable(tolua_S,"data",tolua_get_Message_data,tolua_set_Message_data);
   tolua_variable(tolua_S,"datalen",tolua_get_Message_datalen,tolua_set_Message_datalen);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"MSG_SEND",MSG_SEND);
  tolua_constant(tolua_S,"MSG_NODE_REG",MSG_NODE_REG);
  tolua_constant(tolua_S,"MSG_CREATE_GAMEOBJECT",MSG_CREATE_GAMEOBJECT);
  tolua_constant(tolua_S,"MSG_NET_RAW_DATA",MSG_NET_RAW_DATA);
  tolua_constant(tolua_S,"MSG_NET_PACKET",MSG_NET_PACKET);
  tolua_constant(tolua_S,"MSG_NEW_CONNECTION",MSG_NEW_CONNECTION);
  tolua_constant(tolua_S,"MSG_CLOSE_CONNECTION",MSG_CLOSE_CONNECTION);
  tolua_constant(tolua_S,"MSG_POST",MSG_POST);
  tolua_constant(tolua_S,"MSG_NEW_SESSION",MSG_NEW_SESSION);
  tolua_constant(tolua_S,"MSG_CLOSE_SESSION",MSG_CLOSE_SESSION);
  tolua_cclass(tolua_S,"CreateGameObjectMsg","CreateGameObjectMsg","",NULL);
  tolua_beginmodule(tolua_S,"CreateGameObjectMsg");
   tolua_variable(tolua_S,"len",tolua_get_CreateGameObjectMsg_len,tolua_set_CreateGameObjectMsg_len);
   tolua_variable(tolua_S,"filepath",tolua_get_CreateGameObjectMsg_filepath,tolua_set_CreateGameObjectMsg_filepath);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Buffer","Buffer","",tolua_collect_Buffer);
  #else
  tolua_cclass(tolua_S,"Buffer","Buffer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Buffer");
   tolua_function(tolua_S,"new",tolua_neox_Buffer_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Buffer_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Buffer_new00_local);
   tolua_function(tolua_S,"new",tolua_neox_Buffer_new01);
   tolua_function(tolua_S,"new_local",tolua_neox_Buffer_new01_local);
   tolua_function(tolua_S,".call",tolua_neox_Buffer_new01_local);
   tolua_function(tolua_S,"new",tolua_neox_Buffer_new02);
   tolua_function(tolua_S,"new_local",tolua_neox_Buffer_new02_local);
   tolua_function(tolua_S,".call",tolua_neox_Buffer_new02_local);
   tolua_function(tolua_S,"delete",tolua_neox_Buffer_delete00);
   tolua_function(tolua_S,"read_int64",tolua_neox_Buffer_read_int6400);
   tolua_function(tolua_S,"read_int32",tolua_neox_Buffer_read_int3200);
   tolua_function(tolua_S,"read_int16",tolua_neox_Buffer_read_int1600);
   tolua_function(tolua_S,"read_int8",tolua_neox_Buffer_read_int800);
   tolua_function(tolua_S,"read_buf",tolua_neox_Buffer_read_buf00);
   tolua_function(tolua_S,"read_utf8",tolua_neox_Buffer_read_utf800);
   tolua_function(tolua_S,"read_protobuf",tolua_neox_Buffer_read_protobuf00);
   tolua_function(tolua_S,"write_utf8",tolua_neox_Buffer_write_utf800);
   tolua_function(tolua_S,"write_utf8",tolua_neox_Buffer_write_utf801);
   tolua_function(tolua_S,"write_int64",tolua_neox_Buffer_write_int6400);
   tolua_function(tolua_S,"write_int32",tolua_neox_Buffer_write_int3200);
   tolua_function(tolua_S,"write_int16",tolua_neox_Buffer_write_int1600);
   tolua_function(tolua_S,"write_int8",tolua_neox_Buffer_write_int800);
   tolua_function(tolua_S,"write_buf",tolua_neox_Buffer_write_buf00);
   tolua_function(tolua_S,"write_string",tolua_neox_Buffer_write_string00);
   tolua_function(tolua_S,"write",tolua_neox_Buffer_write00);
   tolua_function(tolua_S,"write_protobuf",tolua_neox_Buffer_write_protobuf00);
   tolua_function(tolua_S,"buf2line",tolua_neox_Buffer_buf2line00);
   tolua_function(tolua_S,"already_read",tolua_neox_Buffer_already_read00);
   tolua_function(tolua_S,"size",tolua_neox_Buffer_size00);
   tolua_function(tolua_S,"maxsize",tolua_neox_Buffer_maxsize00);
   tolua_function(tolua_S,"reset",tolua_neox_Buffer_reset00);
   tolua_function(tolua_S,"get_buffer",tolua_neox_Buffer_get_buffer00);
   tolua_function(tolua_S,"get_write_buffer",tolua_neox_Buffer_get_write_buffer00);
   tolua_function(tolua_S,"ensure_size",tolua_neox_Buffer_ensure_size00);
   tolua_function(tolua_S,"debug",tolua_neox_Buffer_debug00);
   tolua_function(tolua_S,"temp",tolua_neox_Buffer_temp00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"File",0);
  tolua_beginmodule(tolua_S,"File");
   tolua_constant(tolua_S,"TYPE_FILE",File::TYPE_FILE);
   tolua_constant(tolua_S,"TYPE_DIR",File::TYPE_DIR);
   tolua_function(tolua_S,"getcwd",tolua_neox_File_getcwd00);
   tolua_function(tolua_S,"chdir",tolua_neox_File_chdir00);
   tolua_function(tolua_S,"mkdirs",tolua_neox_File_mkdirs00);
   tolua_function(tolua_S,"mkdir",tolua_neox_File_mkdir00);
   tolua_function(tolua_S,"exists",tolua_neox_File_exists00);
   tolua_function(tolua_S,"remove",tolua_neox_File_remove00);
   tolua_function(tolua_S,"rename",tolua_neox_File_rename00);
   tolua_function(tolua_S,"basename",tolua_neox_File_basename00);
   tolua_function(tolua_S,"extname",tolua_neox_File_extname00);
   tolua_function(tolua_S,"dirname",tolua_neox_File_dirname00);
   tolua_function(tolua_S,"listdir",tolua_neox_File_listdir00);
   tolua_function(tolua_S,"cdself",tolua_neox_File_cdself00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Transform","Transform","Component",tolua_collect_Transform);
  #else
  tolua_cclass(tolua_S,"Transform","Transform","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Transform");
   tolua_function(tolua_S,"new",tolua_neox_Transform_new00);
   tolua_function(tolua_S,"new_local",tolua_neox_Transform_new00_local);
   tolua_function(tolua_S,".call",tolua_neox_Transform_new00_local);
   tolua_function(tolua_S,"delete",tolua_neox_Transform_delete00);
  tolua_endmodule(tolua_S);

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = {
    10, 95, 95, 67, 79, 77, 80, 79, 78, 69, 78, 84, 83, 32, 61,
     32, 49, 10, 95, 95, 67, 72, 73, 76, 68, 82, 69, 78, 32, 61,
     32, 50, 10,102,117,110, 99,116,105,111,110, 32,105,110,115,
    116, 97,110,116,105, 97,116,101, 40, 99,111,110,102, 41, 10,
    108,111, 99, 97,108, 32,111, 98,106,101, 99,116, 32, 61, 32,
     71, 97,109,101, 79, 98,106,101, 99,116, 58,110,101,119, 40,
     41, 10,102,111,114, 32,107, 44, 32,118, 32,105,110, 32,112,
     97,105,114,115, 40, 99,111,110,102, 41, 32,100,111, 10,105,
    102, 32,107, 32, 61, 61, 32, 95, 95, 67, 79, 77, 80, 79, 78,
     69, 78, 84, 83, 32,116,104,101,110, 10,102,111,114, 32, 99,
    108, 97,115,115, 44, 32, 99,111,109,112,111,110,101,110,116,
     95, 99,111,110,102, 32,105,110, 32,112, 97,105,114,115, 40,
    118, 41, 32,100,111, 10,105,102, 32, 99,111,109,112,111,110,
    101,110,116, 95, 99,111,110,102, 46, 95, 95,115, 99,114,105,
    112,116, 32,116,104,101,110, 10,108,111, 99, 97,108, 32, 99,
    111,109,112,111,110,101,110,116, 32, 61, 32,111, 98,106,101,
     99,116, 58, 97,100,100, 95,115, 99,114,105,112,116, 40, 99,
    111,109,112,111,110,101,110,116, 95, 99,111,110,102, 46, 95,
     95,115, 99,114,105,112,116, 41, 10,102,111,114, 32,118, 97,
    114,110, 97,109,101, 44, 32,118, 97,108,117,101, 32,105,110,
     32,112, 97,105,114,115, 40, 99,111,109,112,111,110,101,110,
    116, 95, 99,111,110,102, 41, 32,100,111, 10, 99,111,109,112,
    111,110,101,110,116, 91,118, 97,114,110, 97,109,101, 93, 32,
     61, 32,118, 97,108,117,101, 10,101,110,100, 10,101,108,115,
    101, 10,108,111, 99, 97,108, 32, 99,111,109,112,111,110,101,
    110,116, 95, 99,108, 97,115,115, 32, 61, 32, 95, 71, 91, 99,
    108, 97,115,115, 93, 10,105,102, 32,110,111,116, 32, 99,111,
    109,112,111,110,101,110,116, 95, 99,108, 97,115,115, 32,116,
    104,101,110, 10,112,114,105,110,116, 40,115,116,114,105,110,
    103, 46,102,111,114,109, 97,116, 40, 39, 37,115, 32,110,111,
    116, 32,102,111,117,110,100, 39, 44, 32, 99,108, 97,115,115,
     41, 41, 10,101,110,100, 10,108,111, 99, 97,108, 32, 99,111,
    109,112,111,110,101,110,116, 32, 61, 32, 99,111,109,112,111,
    110,101,110,116, 95, 99,108, 97,115,115, 58,110,101,119, 40,
     41, 10,111, 98,106,101, 99,116, 58, 97,100,100, 95, 99,111,
    109,112,111,110,101,110,116, 40, 99,111,109,112,111,110,101,
    110,116, 41, 10,102,111,114, 32,118, 97,114,110, 97,109,101,
     44, 32,118, 97,108,117,101, 32,105,110, 32,112, 97,105,114,
    115, 40, 99,111,109,112,111,110,101,110,116, 95, 99,111,110,
    102, 41, 32,100,111, 10, 99,111,109,112,111,110,101,110,116,
     91,118, 97,114,110, 97,109,101, 93, 32, 61, 32,118, 97,108,
    117,101, 10,101,110,100, 10,101,110,100, 10,101,110,100, 10,
    101,108,115,101,105,102, 32,107, 32, 61, 61, 32, 95, 95, 67,
     72, 73, 76, 68, 82, 69, 78, 32,116,104,101,110, 10,102,111,
    114, 32,107, 50, 44, 32,118, 50, 32,105,110, 32,112, 97,105,
    114,115, 40,118, 41, 32,100,111, 10,108,111, 99, 97,108, 32,
     99,104,105,108,100, 32, 61, 32,105,110,115,116, 97,110,116,
    105, 97,116,101, 40,118, 50, 41, 10, 99,104,105,108,100, 46,
    110, 97,109,101, 32, 61, 32,107, 50, 10,111, 98,106,101, 99,
    116, 58, 97,100,100, 95, 99,104,105,108,100, 40, 99,104,105,
    108,100, 41, 10,101,110,100, 10,101,108,115,101, 10,111, 98,
    106,101, 99,116, 91,107, 93, 32, 61, 32,118, 10,101,110,100,
     10,101,110,100, 10,114,101,116,117,114,110, 32,111, 98,106,
    101, 99,116, 10,101,110,100, 10, 78, 69, 87, 95, 80, 79, 83,
     84, 32, 61, 32,102,117,110, 99,116,105,111,110, 40,115,114,
    118,105,100, 41, 10,108,111, 99, 97,108, 32,115,114,118,105,
    100, 32, 61, 32,115,114,118,105,100, 10,108,111, 99, 97,108,
     32,109,111,100,110, 97,109,101, 32, 61, 32,110,105,108, 10,
    108,111, 99, 97,108, 32,102,117,110,110, 97,109,101, 32, 61,
     32,110,105,108, 10,108,111, 99, 97,108, 32,109,116, 32, 61,
     32,123, 10, 95, 95,105,110,100,101,120, 32, 61, 32,102,117,
    110, 99,116,105,111,110, 40,115,101,108,102, 44, 32,107, 41,
     10,105,102, 32,110,111,116, 32,109,111,100,110, 97,109,101,
     32,116,104,101,110, 10,109,111,100,110, 97,109,101, 32, 61,
     32,107, 10,101,108,115,101, 10,102,117,110, 99,110, 97,109,
    101, 32, 61, 32,107, 10,101,110,100, 10,114,101,116,117,114,
    110, 32,115,101,108,102, 10,101,110,100, 44, 10, 95, 95, 99,
     97,108,108, 32, 61, 32,102,117,110, 99,116,105,111,110, 40,
    115,101,108,102, 44, 32, 46, 46, 46, 41, 10,109,111,100,110,
     97,109,101, 32, 61, 32,110,105,108, 10,102,117,110, 99,110,
     97,109,101, 32, 61, 32,110,105,108, 10,109,121,110,111,100,
    101, 58,112,111,115,116, 40,115,114,118,105,100, 44, 32,109,
    111,100,110, 97,109,101, 44, 32,102,117,110, 99,110, 97,109,
    101, 44, 32, 46, 46, 46, 41, 10,101,110,100, 10,125, 10,108,
    111, 99, 97,108, 32,115,116,117, 98, 32, 61, 32,123,125, 10,
    115,101,116,109,101,116, 97,116, 97, 98,108,101, 40,115,116,
    117, 98, 44, 32,109,116, 41, 10,114,101,116,117,114,110, 32,
    115,116,117, 98, 10,101,110,100, 10, 80, 79, 83, 84, 32, 61,
     32,102,117,110, 99,116,105,111,110, 40, 46, 46, 46, 41, 10,
    109,121,110,111,100,101, 58,112,111,115,116, 40, 46, 46, 46,
     41, 10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32,
    105,109,112,111,114,116, 95,112,114,111,116,111, 40,100,105,
    114, 41, 10, 80, 98,108,117, 97, 46,109, 97,112,112, 97,116,
    104, 40, 39, 39, 44, 32,100,105,114, 41, 10,108,111, 99, 97,
    108, 32,102,105,108,101,115, 32, 61, 32, 70,105,108,101, 46,
    108,105,115,116,100,105,114, 40,100,105,114, 41, 10,102,111,
    114, 32, 95, 44, 32,102,105,108,101, 32,105,110, 32,112, 97,
    105,114,115, 40,102,105,108,101,115, 41, 32,100,111, 10,105,
    102, 32,102,105,108,101, 46,116,121,112,101, 32, 61, 61, 32,
     70,105,108,101, 46, 84, 89, 80, 69, 95, 70, 73, 76, 69, 32,
     97,110,100, 32,115,116,114,105,110,103, 46,102,105,110,100,
     40,102,105,108,101, 46,110, 97,109,101, 44, 32, 39, 46,112,
    114,111,116,111, 36, 39, 41, 32,116,104,101,110, 10,108,111,
    103,100,101, 98,117,103, 40,115,116,114,105,110,103, 46,102,
    111,114,109, 97,116, 40, 39,108,111, 97,100, 32,112,114,111,
    116,111, 40, 37,115, 41, 39, 44, 32,102,105,108,101, 46,110,
     97,109,101, 41, 41, 10, 80, 98,108,117, 97, 46,105,109,112,
    111,114,116, 40,102,105,108,101, 46,110, 97,109,101, 41, 10,
    101,110,100, 10,101,110,100, 10,101,110,100,32
   };
   tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua embedded: data/lib.lua");
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_neox (lua_State* tolua_S) {
 return tolua_neox_open(tolua_S);
};
}
#endif

