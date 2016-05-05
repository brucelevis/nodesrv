/*
** Lua binding: nodeapi
** Generated automatically by tolua++-1.0.92 on Wed May  4 18:16:58 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_nodeapi_open (lua_State* tolua_S);

#include "type/type.h"
#include "entity/entity.h"
#include "component/component.h"
#include "components/testcomponent.h"
#include "components/scriptcomponent.h"
#include "components/netcomponent.h"
#include "components/httpcomponent.h"
#include "node/node.h"
#include "node/nodemgr.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Component (lua_State* tolua_S)
{
 Component* self = (Component*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TestComponent (lua_State* tolua_S)
{
 TestComponent* self = (TestComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_ScriptComponent (lua_State* tolua_S)
{
 ScriptComponent* self = (ScriptComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_HttpComponent (lua_State* tolua_S)
{
 HttpComponent* self = (HttpComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Entity (lua_State* tolua_S)
{
 Entity* self = (Entity*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_NetComponent (lua_State* tolua_S)
{
 NetComponent* self = (NetComponent*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Node (lua_State* tolua_S)
{
 Node* self = (Node*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_Type (lua_State* tolua_S)
{
 Type* self = (Type*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TestComponent");
 tolua_usertype(tolua_S,"ScriptComponent");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"NetComponent");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"HttpComponent");
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Type");
 tolua_usertype(tolua_S,"aeFileProc");
 tolua_usertype(tolua_S,"MsgHeader");
}

/* method: new of class  Type */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Type_new00
static int tolua_nodeapi_Type_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Type_new00_local
static int tolua_nodeapi_Type_new00_local(lua_State* tolua_S)
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

/* method: new of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_new00
static int tolua_nodeapi_Entity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Entity* tolua_ret = (Entity*)  new Entity();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
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

/* method: new_local of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_new00_local
static int tolua_nodeapi_Entity_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Entity* tolua_ret = (Entity*)  new Entity();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Entity");
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

/* method: delete of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_delete00
static int tolua_nodeapi_Entity_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: test of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_test00
static int tolua_nodeapi_Entity_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_create00
static int tolua_nodeapi_Entity_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: save of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_save00
static int tolua_nodeapi_Entity_save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: update of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_update00
static int tolua_nodeapi_Entity_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: awake of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_awake00
static int tolua_nodeapi_Entity_awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: recv of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_recv00
static int tolua_nodeapi_Entity_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t datalen = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   int tolua_ret = (int)  self->recv(header,data,datalen);
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

/* method: unreach of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_unreach00
static int tolua_nodeapi_Entity_unreach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t datalen = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreach'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreach(header,data,datalen);
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

/* method: add_component of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_add_component00
static int tolua_nodeapi_Entity_add_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: add_script of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_add_script00
static int tolua_nodeapi_Entity_add_script00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: del_component of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_del_component00
static int tolua_nodeapi_Entity_del_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: get_component of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_component00
static int tolua_nodeapi_Entity_get_component00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_component'",NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->get_component(index);
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

/* method: get_component of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_component01
static int tolua_nodeapi_Entity_get_component01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_nodeapi_Entity_get_component00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_component of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_component02
static int tolua_nodeapi_Entity_get_component02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     false
 )
  goto tolua_lerror;
 else
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_nodeapi_Entity_get_component01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_script of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_script00
static int tolua_nodeapi_Entity_get_script00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: reg_msg of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_reg_msg00
static int tolua_nodeapi_Entity_reg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  unsigned int id = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
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

/* method: unreg_msg of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_unreg_msg00
static int tolua_nodeapi_Entity_unreg_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  unsigned int id = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
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

/* method: get_child of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_child00
static int tolua_nodeapi_Entity_get_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_child'",NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->get_child(index);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
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

/* method: add_child of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_add_child00
static int tolua_nodeapi_Entity_add_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_child'",NULL);
#endif
  {
   int tolua_ret = (int)  self->add_child(entity);
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

/* method: del_child of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_del_child00
static int tolua_nodeapi_Entity_del_child00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: del_child of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_del_child01
static int tolua_nodeapi_Entity_del_child01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'del_child'",NULL);
#endif
  {
   int tolua_ret = (int)  self->del_child(entity);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_nodeapi_Entity_del_child00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: indexof of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_indexof00
static int tolua_nodeapi_Entity_indexof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'indexof'",NULL);
#endif
  {
   int tolua_ret = (int)  self->indexof(entity);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'indexof'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_parent of class  Entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Entity_get_parent00
static int tolua_nodeapi_Entity_get_parent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_parent'",NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->get_parent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
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

/* get function: id of class  Entity */
#ifndef TOLUA_DISABLE_tolua_get_Entity_id
static int tolua_get_Entity_id(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  Entity */
#ifndef TOLUA_DISABLE_tolua_set_Entity_id
static int tolua_set_Entity_id(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: data of class  Entity */
#ifndef TOLUA_DISABLE_tolua_get_Entity_data
static int tolua_get_Entity_data(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'data'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->data);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: data of class  Entity */
#ifndef TOLUA_DISABLE_tolua_set_Entity_data
static int tolua_set_Entity_data(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: node of class  Entity */
#ifndef TOLUA_DISABLE_tolua_get_Entity_node_ptr
static int tolua_get_Entity_node_ptr(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->node,"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: node of class  Entity */
#ifndef TOLUA_DISABLE_tolua_set_Entity_node_ptr
static int tolua_set_Entity_node_ptr(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: name of class  Entity */
#ifndef TOLUA_DISABLE_tolua_get_Entity_name
static int tolua_get_Entity_name(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  Entity */
#ifndef TOLUA_DISABLE_tolua_set_Entity_name
static int tolua_set_Entity_name(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_new00
static int tolua_nodeapi_Component_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_new00_local
static int tolua_nodeapi_Component_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_delete00
static int tolua_nodeapi_Component_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_awake00
static int tolua_nodeapi_Component_awake00(lua_State* tolua_S)
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

/* method: update of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_update00
static int tolua_nodeapi_Component_update00(lua_State* tolua_S)
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

/* method: recv of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_recv00
static int tolua_nodeapi_Component_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t datalen = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   int tolua_ret = (int)  self->recv(header,data,datalen);
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_unreach00
static int tolua_nodeapi_Component_unreach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t datalen = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unreach'",NULL);
#endif
  {
   int tolua_ret = (int)  self->unreach(header,data,datalen);
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

/* method: pushluafunction of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_pushluafunction00
static int tolua_nodeapi_Component_pushluafunction00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushluafunction'",NULL);
#endif
  {
   int tolua_ret = (int)  self->pushluafunction(func);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushluafunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_printstack of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_lua_printstack00
static int tolua_nodeapi_Component_lua_printstack00(lua_State* tolua_S)
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

/* method: get_entity of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_get_entity00
static int tolua_nodeapi_Component_get_entity00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_entity'",NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->get_entity();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_entity of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_set_entity00
static int tolua_nodeapi_Component_set_entity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_entity'",NULL);
#endif
  {
   self->set_entity(entity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_file_event of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_create_file_event00
static int tolua_nodeapi_Component_create_file_event00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_delete_file_event00
static int tolua_nodeapi_Component_delete_file_event00(lua_State* tolua_S)
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

/* method: get_node of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_get_node00
static int tolua_nodeapi_Component_get_node00(lua_State* tolua_S)
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

/* method: send_entity_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_send_entity_msg00
static int tolua_nodeapi_Component_send_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int dst_entityid = ((int)  tolua_tonumber(tolua_S,2,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,4,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_entity_msg'",NULL);
#endif
  {
   self->send_entity_msg(dst_entityid,msgid,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forward_entity_msg of class  Component */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Component_forward_entity_msg00
static int tolua_nodeapi_Component_forward_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  int dst_entityid = ((int)  tolua_tonumber(tolua_S,3,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,5,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forward_entity_msg'",NULL);
#endif
  {
   self->forward_entity_msg(dst_nodeid,dst_entityid,msgid,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forward_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  TestComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_TestComponent_new00
static int tolua_nodeapi_TestComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestComponent* tolua_ret = (TestComponent*)  new TestComponent();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestComponent");
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

/* method: new_local of class  TestComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_TestComponent_new00_local
static int tolua_nodeapi_TestComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestComponent* tolua_ret = (TestComponent*)  new TestComponent();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TestComponent");
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

/* method: delete of class  TestComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_TestComponent_delete00
static int tolua_nodeapi_TestComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestComponent* self = (TestComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: test of class  TestComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_TestComponent_test00
static int tolua_nodeapi_TestComponent_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestComponent* self = (TestComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_new00
static int tolua_nodeapi_ScriptComponent_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_new00_local
static int tolua_nodeapi_ScriptComponent_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_delete00
static int tolua_nodeapi_ScriptComponent_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_awake00
static int tolua_nodeapi_ScriptComponent_awake00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_update00
static int tolua_nodeapi_ScriptComponent_update00(lua_State* tolua_S)
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

/* method: call of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_call00
static int tolua_nodeapi_ScriptComponent_call00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptComponent* self = (ScriptComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'call'",NULL);
#endif
  {
   int tolua_ret = (int)  self->call(str);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'call'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: test of class  ScriptComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_ScriptComponent_test00
static int tolua_nodeapi_ScriptComponent_test00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_new00
static int tolua_nodeapi_NetComponent_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_new00_local
static int tolua_nodeapi_NetComponent_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_delete00
static int tolua_nodeapi_NetComponent_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_update00
static int tolua_nodeapi_NetComponent_update00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_listen00
static int tolua_nodeapi_NetComponent_listen00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NetComponent_send00
static int tolua_nodeapi_NetComponent_send00(lua_State* tolua_S)
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
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
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

/* method: new of class  HttpComponent */
#ifndef TOLUA_DISABLE_tolua_nodeapi_HttpComponent_new00
static int tolua_nodeapi_HttpComponent_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_HttpComponent_new00_local
static int tolua_nodeapi_HttpComponent_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_HttpComponent_delete00
static int tolua_nodeapi_HttpComponent_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_HttpComponent_recv00
static int tolua_nodeapi_HttpComponent_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HttpComponent",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HttpComponent* self = (HttpComponent*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  size_t datalen = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   int tolua_ret = (int)  self->recv(header,data,datalen);
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_HttpComponent_awake00
static int tolua_nodeapi_HttpComponent_awake00(lua_State* tolua_S)
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

/* method: new of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_new00
static int tolua_nodeapi_Node_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_new00_local
static int tolua_nodeapi_Node_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_delete00
static int tolua_nodeapi_Node_delete00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_main00
static int tolua_nodeapi_Node_main00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* mainfile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'main'",NULL);
#endif
  {
   self->main(mainfile);
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_update00
static int tolua_nodeapi_Node_update00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_connect00
static int tolua_nodeapi_Node_connect00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_listen00
static int tolua_nodeapi_Node_listen00(lua_State* tolua_S)
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

/* method: send of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_send00
static int tolua_nodeapi_Node_send00(lua_State* tolua_S)
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
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'",NULL);
#endif
  {
   int tolua_ret = (int)  self->send(data,size);
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

/* method: find_entity of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_find_entity00
static int tolua_nodeapi_Node_find_entity00(lua_State* tolua_S)
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
  int entityid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'find_entity'",NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->find_entity(entityid);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'find_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_entity of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_add_entity00
static int tolua_nodeapi_Node_add_entity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_entity'",NULL);
#endif
  {
   int tolua_ret = (int)  self->add_entity(entity);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_id of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_get_id00
static int tolua_nodeapi_Node_get_id00(lua_State* tolua_S)
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
   int tolua_ret = (int)  self->get_id();
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_is_local00
static int tolua_nodeapi_Node_is_local00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_set_local00
static int tolua_nodeapi_Node_set_local00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_is_disconnect00
static int tolua_nodeapi_Node_is_disconnect00(lua_State* tolua_S)
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

/* method: create_entity_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_create_entity_local00
static int tolua_nodeapi_Node_create_entity_local00(lua_State* tolua_S)
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
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_entity_local'",NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->create_entity_local(filepath);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_entity_local'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ev_accept of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_ev_accept00
static int tolua_nodeapi_Node_ev_accept00(lua_State* tolua_S)
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
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ev_accept'",NULL);
#endif
  {
   self->ev_accept(sockfd);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ev_accept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ev_writable of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_ev_writable00
static int tolua_nodeapi_Node_ev_writable00(lua_State* tolua_S)
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
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ev_writable'",NULL);
#endif
  {
   self->ev_writable(sockfd);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ev_writable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ev_readable of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_ev_readable00
static int tolua_nodeapi_Node_ev_readable00(lua_State* tolua_S)
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
  int sockfd = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ev_readable'",NULL);
#endif
  {
   self->ev_readable(sockfd);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ev_readable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_recv00
static int tolua_nodeapi_Node_recv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv'",NULL);
#endif
  {
   self->recv(header,data,size);
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

/* method: recv_entity_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_recv_entity_msg00
static int tolua_nodeapi_Node_recv_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_entity_msg'",NULL);
#endif
  {
   self->recv_entity_msg(header,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: recv_node_reg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_recv_node_reg00
static int tolua_nodeapi_Node_recv_node_reg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_node_reg'",NULL);
#endif
  {
   self->recv_node_reg(header,data,size);
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

/* method: recv_create_entity of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_recv_create_entity00
static int tolua_nodeapi_Node_recv_create_entity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'recv_create_entity'",NULL);
#endif
  {
   self->recv_create_entity(header,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'recv_create_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_entity_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_send_entity_msg00
static int tolua_nodeapi_Node_send_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Entity* src_entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
  int dst_entityid = ((int)  tolua_tonumber(tolua_S,3,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,5,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_entity_msg'",NULL);
#endif
  {
   self->send_entity_msg(src_entity,dst_entityid,msgid,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forward_entity_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_forward_entity_msg00
static int tolua_nodeapi_Node_forward_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Entity* src_entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
  int dst_entityid = ((int)  tolua_tonumber(tolua_S,3,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,5,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forward_entity_msg'",NULL);
#endif
  {
   self->forward_entity_msg(src_entity,dst_entityid,msgid,data,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forward_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: forward_entity_msg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_forward_entity_msg01
static int tolua_nodeapi_Node_forward_entity_msg01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MsgHeader",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  MsgHeader* header = ((MsgHeader*)  tolua_tousertype(tolua_S,2,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,3,0));
  size_t size = ((size_t)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'forward_entity_msg'",NULL);
#endif
  {
   self->forward_entity_msg(header,data,size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_nodeapi_Node_forward_entity_msg00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_node_reg of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_send_node_reg00
static int tolua_nodeapi_Node_send_node_reg00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_node_reg'",NULL);
#endif
  {
   self->send_node_reg();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_node_reg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_create_entity of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_send_create_entity00
static int tolua_nodeapi_Node_send_create_entity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Entity* src_entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_create_entity'",NULL);
#endif
  {
   self->send_create_entity(src_entity,filepath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_create_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_file_event of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_create_file_event00
static int tolua_nodeapi_Node_create_file_event00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
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
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: delete_file_event of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_delete_file_event00
static int tolua_nodeapi_Node_delete_file_event00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: dofile of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_dofile00
static int tolua_nodeapi_Node_dofile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dofile'",NULL);
#endif
  {
   int tolua_ret = (int)  self->dofile(filepath);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dofile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushluafunction of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_pushluafunction00
static int tolua_nodeapi_Node_pushluafunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const char* func = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushluafunction'",NULL);
#endif
  {
   int tolua_ret = (int)  self->pushluafunction(func);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushluafunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_printstack of class  Node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_Node_lua_printstack00
static int tolua_nodeapi_Node_lua_printstack00(lua_State* tolua_S)
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

/* function: NodeMgr::update */
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_update00
static int tolua_nodeapi_NodeMgr_update00(lua_State* tolua_S)
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
  long long cur_tick = ((long long)  tolua_tonumber(tolua_S,1,0));
  {
   NodeMgr::update(cur_tick);
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

/* function: NodeMgr::find_node */
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_find_node00
static int tolua_nodeapi_NodeMgr_find_node00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_create_temp_node00
static int tolua_nodeapi_NodeMgr_create_temp_node00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_create_node_local00
static int tolua_nodeapi_NodeMgr_create_node_local00(lua_State* tolua_S)
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
  int nodeid = ((int)  tolua_tonumber(tolua_S,1,0));
  const char* mainfile = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Node* tolua_ret = (Node*)  NodeMgr::create_node_local(nodeid,mainfile);
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
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_create_node_remote00
static int tolua_nodeapi_NodeMgr_create_node_remote00(lua_State* tolua_S)
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

/* function: NodeMgr::forward_entity_msg */
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_forward_entity_msg00
static int tolua_nodeapi_NodeMgr_forward_entity_msg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* src_entity = ((Entity*)  tolua_tousertype(tolua_S,1,0));
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  int dst_entityid = ((int)  tolua_tonumber(tolua_S,3,0));
  int msgid = ((int)  tolua_tonumber(tolua_S,4,0));
  const char* data = ((const char*)  tolua_tostring(tolua_S,5,0));
  size_t len = ((size_t)  tolua_tonumber(tolua_S,6,0));
  {
   NodeMgr::forward_entity_msg(src_entity,dst_nodeid,dst_entityid,msgid,data,len);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'forward_entity_msg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeMgr::send_create_entity */
#ifndef TOLUA_DISABLE_tolua_nodeapi_NodeMgr_send_create_entity00
static int tolua_nodeapi_NodeMgr_send_create_entity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* src_entity = ((Entity*)  tolua_tousertype(tolua_S,1,0));
  int dst_nodeid = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* filepath = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   NodeMgr::send_create_entity(src_entity,dst_nodeid,filepath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_create_entity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_nodeapi_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Type","Type","",tolua_collect_Type);
  #else
  tolua_cclass(tolua_S,"Type","Type","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Type");
   tolua_function(tolua_S,"new",tolua_nodeapi_Type_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_Type_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_Type_new00_local);
   tolua_variable(tolua_S,"name",tolua_get_Type_name,tolua_set_Type_name);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Entity","Entity","",tolua_collect_Entity);
  #else
  tolua_cclass(tolua_S,"Entity","Entity","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Entity");
   tolua_function(tolua_S,"new",tolua_nodeapi_Entity_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_Entity_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_Entity_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_Entity_delete00);
   tolua_function(tolua_S,"test",tolua_nodeapi_Entity_test00);
   tolua_function(tolua_S,"create",tolua_nodeapi_Entity_create00);
   tolua_function(tolua_S,"save",tolua_nodeapi_Entity_save00);
   tolua_function(tolua_S,"update",tolua_nodeapi_Entity_update00);
   tolua_function(tolua_S,"awake",tolua_nodeapi_Entity_awake00);
   tolua_function(tolua_S,"recv",tolua_nodeapi_Entity_recv00);
   tolua_function(tolua_S,"unreach",tolua_nodeapi_Entity_unreach00);
   tolua_function(tolua_S,"add_component",tolua_nodeapi_Entity_add_component00);
   tolua_function(tolua_S,"add_script",tolua_nodeapi_Entity_add_script00);
   tolua_function(tolua_S,"del_component",tolua_nodeapi_Entity_del_component00);
   tolua_function(tolua_S,"get_component",tolua_nodeapi_Entity_get_component00);
   tolua_function(tolua_S,"get_component",tolua_nodeapi_Entity_get_component01);
   tolua_function(tolua_S,"get_component",tolua_nodeapi_Entity_get_component02);
   tolua_function(tolua_S,"get_script",tolua_nodeapi_Entity_get_script00);
   tolua_function(tolua_S,"reg_msg",tolua_nodeapi_Entity_reg_msg00);
   tolua_function(tolua_S,"unreg_msg",tolua_nodeapi_Entity_unreg_msg00);
   tolua_function(tolua_S,"get_child",tolua_nodeapi_Entity_get_child00);
   tolua_function(tolua_S,"add_child",tolua_nodeapi_Entity_add_child00);
   tolua_function(tolua_S,"del_child",tolua_nodeapi_Entity_del_child00);
   tolua_function(tolua_S,"del_child",tolua_nodeapi_Entity_del_child01);
   tolua_function(tolua_S,"indexof",tolua_nodeapi_Entity_indexof00);
   tolua_function(tolua_S,"get_parent",tolua_nodeapi_Entity_get_parent00);
   tolua_variable(tolua_S,"id",tolua_get_Entity_id,tolua_set_Entity_id);
   tolua_variable(tolua_S,"data",tolua_get_Entity_data,tolua_set_Entity_data);
   tolua_variable(tolua_S,"node",tolua_get_Entity_node_ptr,tolua_set_Entity_node_ptr);
   tolua_variable(tolua_S,"name",tolua_get_Entity_name,tolua_set_Entity_name);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Component","Component","",tolua_collect_Component);
  #else
  tolua_cclass(tolua_S,"Component","Component","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Component");
   tolua_function(tolua_S,"new",tolua_nodeapi_Component_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_Component_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_Component_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_Component_delete00);
   tolua_function(tolua_S,"awake",tolua_nodeapi_Component_awake00);
   tolua_function(tolua_S,"update",tolua_nodeapi_Component_update00);
   tolua_function(tolua_S,"recv",tolua_nodeapi_Component_recv00);
   tolua_function(tolua_S,"unreach",tolua_nodeapi_Component_unreach00);
   tolua_function(tolua_S,"pushluafunction",tolua_nodeapi_Component_pushluafunction00);
   tolua_function(tolua_S,"lua_printstack",tolua_nodeapi_Component_lua_printstack00);
   tolua_function(tolua_S,"get_entity",tolua_nodeapi_Component_get_entity00);
   tolua_function(tolua_S,"set_entity",tolua_nodeapi_Component_set_entity00);
   tolua_function(tolua_S,"create_file_event",tolua_nodeapi_Component_create_file_event00);
   tolua_function(tolua_S,"delete_file_event",tolua_nodeapi_Component_delete_file_event00);
   tolua_function(tolua_S,"get_node",tolua_nodeapi_Component_get_node00);
   tolua_function(tolua_S,"send_entity_msg",tolua_nodeapi_Component_send_entity_msg00);
   tolua_function(tolua_S,"forward_entity_msg",tolua_nodeapi_Component_forward_entity_msg00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TestComponent","TestComponent","Component",tolua_collect_TestComponent);
  #else
  tolua_cclass(tolua_S,"TestComponent","TestComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TestComponent");
   tolua_function(tolua_S,"new",tolua_nodeapi_TestComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_TestComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_TestComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_TestComponent_delete00);
   tolua_function(tolua_S,"test",tolua_nodeapi_TestComponent_test00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ScriptComponent","ScriptComponent","Component",tolua_collect_ScriptComponent);
  #else
  tolua_cclass(tolua_S,"ScriptComponent","ScriptComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ScriptComponent");
   tolua_function(tolua_S,"new",tolua_nodeapi_ScriptComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_ScriptComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_ScriptComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_ScriptComponent_delete00);
   tolua_function(tolua_S,"awake",tolua_nodeapi_ScriptComponent_awake00);
   tolua_function(tolua_S,"update",tolua_nodeapi_ScriptComponent_update00);
   tolua_function(tolua_S,"call",tolua_nodeapi_ScriptComponent_call00);
   tolua_function(tolua_S,"test",tolua_nodeapi_ScriptComponent_test00);
   tolua_variable(tolua_S,"modname",tolua_get_ScriptComponent_modname,tolua_set_ScriptComponent_modname);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"NetComponent","NetComponent","Component",tolua_collect_NetComponent);
  #else
  tolua_cclass(tolua_S,"NetComponent","NetComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"NetComponent");
   tolua_function(tolua_S,"new",tolua_nodeapi_NetComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_NetComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_NetComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_NetComponent_delete00);
   tolua_function(tolua_S,"update",tolua_nodeapi_NetComponent_update00);
   tolua_function(tolua_S,"listen",tolua_nodeapi_NetComponent_listen00);
   tolua_function(tolua_S,"send",tolua_nodeapi_NetComponent_send00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HttpComponent","HttpComponent","Component",tolua_collect_HttpComponent);
  #else
  tolua_cclass(tolua_S,"HttpComponent","HttpComponent","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HttpComponent");
   tolua_function(tolua_S,"new",tolua_nodeapi_HttpComponent_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_HttpComponent_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_HttpComponent_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_HttpComponent_delete00);
   tolua_function(tolua_S,"recv",tolua_nodeapi_HttpComponent_recv00);
   tolua_function(tolua_S,"awake",tolua_nodeapi_HttpComponent_awake00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Node","Node","",tolua_collect_Node);
  #else
  tolua_cclass(tolua_S,"Node","Node","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Node");
   tolua_function(tolua_S,"new",tolua_nodeapi_Node_new00);
   tolua_function(tolua_S,"new_local",tolua_nodeapi_Node_new00_local);
   tolua_function(tolua_S,".call",tolua_nodeapi_Node_new00_local);
   tolua_function(tolua_S,"delete",tolua_nodeapi_Node_delete00);
   tolua_function(tolua_S,"main",tolua_nodeapi_Node_main00);
   tolua_function(tolua_S,"update",tolua_nodeapi_Node_update00);
   tolua_function(tolua_S,"connect",tolua_nodeapi_Node_connect00);
   tolua_function(tolua_S,"listen",tolua_nodeapi_Node_listen00);
   tolua_function(tolua_S,"send",tolua_nodeapi_Node_send00);
   tolua_function(tolua_S,"find_entity",tolua_nodeapi_Node_find_entity00);
   tolua_function(tolua_S,"add_entity",tolua_nodeapi_Node_add_entity00);
   tolua_function(tolua_S,"get_id",tolua_nodeapi_Node_get_id00);
   tolua_function(tolua_S,"is_local",tolua_nodeapi_Node_is_local00);
   tolua_function(tolua_S,"set_local",tolua_nodeapi_Node_set_local00);
   tolua_function(tolua_S,"is_disconnect",tolua_nodeapi_Node_is_disconnect00);
   tolua_function(tolua_S,"create_entity_local",tolua_nodeapi_Node_create_entity_local00);
   tolua_function(tolua_S,"ev_accept",tolua_nodeapi_Node_ev_accept00);
   tolua_function(tolua_S,"ev_writable",tolua_nodeapi_Node_ev_writable00);
   tolua_function(tolua_S,"ev_readable",tolua_nodeapi_Node_ev_readable00);
   tolua_function(tolua_S,"recv",tolua_nodeapi_Node_recv00);
   tolua_function(tolua_S,"recv_entity_msg",tolua_nodeapi_Node_recv_entity_msg00);
   tolua_function(tolua_S,"recv_node_reg",tolua_nodeapi_Node_recv_node_reg00);
   tolua_function(tolua_S,"recv_create_entity",tolua_nodeapi_Node_recv_create_entity00);
   tolua_function(tolua_S,"send_entity_msg",tolua_nodeapi_Node_send_entity_msg00);
   tolua_function(tolua_S,"forward_entity_msg",tolua_nodeapi_Node_forward_entity_msg00);
   tolua_function(tolua_S,"forward_entity_msg",tolua_nodeapi_Node_forward_entity_msg01);
   tolua_function(tolua_S,"send_node_reg",tolua_nodeapi_Node_send_node_reg00);
   tolua_function(tolua_S,"send_create_entity",tolua_nodeapi_Node_send_create_entity00);
   tolua_function(tolua_S,"create_file_event",tolua_nodeapi_Node_create_file_event00);
   tolua_function(tolua_S,"delete_file_event",tolua_nodeapi_Node_delete_file_event00);
   tolua_function(tolua_S,"dofile",tolua_nodeapi_Node_dofile00);
   tolua_function(tolua_S,"pushluafunction",tolua_nodeapi_Node_pushluafunction00);
   tolua_function(tolua_S,"lua_printstack",tolua_nodeapi_Node_lua_printstack00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"NodeMgr",0);
  tolua_beginmodule(tolua_S,"NodeMgr");
   tolua_function(tolua_S,"update",tolua_nodeapi_NodeMgr_update00);
   tolua_function(tolua_S,"find_node",tolua_nodeapi_NodeMgr_find_node00);
   tolua_function(tolua_S,"create_temp_node",tolua_nodeapi_NodeMgr_create_temp_node00);
   tolua_function(tolua_S,"create_node_local",tolua_nodeapi_NodeMgr_create_node_local00);
   tolua_function(tolua_S,"create_node_remote",tolua_nodeapi_NodeMgr_create_node_remote00);
   tolua_function(tolua_S,"forward_entity_msg",tolua_nodeapi_NodeMgr_forward_entity_msg00);
   tolua_function(tolua_S,"send_create_entity",tolua_nodeapi_NodeMgr_send_create_entity00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 extern "C"{
 TOLUA_API int luaopen_nodeapi (lua_State* tolua_S) {
 return tolua_nodeapi_open(tolua_S);
};
}
#endif

