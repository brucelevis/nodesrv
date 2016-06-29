#ifndef __FILE_H__
#define __FILE_H__ 

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

//tolua_begin
namespace File {
    char *getcwd();
    bool chdir(char* dir);
    bool mkdirs(char* dir);
    bool mkdir(char* dir);
    bool exists(char* dir);
    bool remove(char* dir);
    bool rename(char* src, char* dst);
    int basename(lua_State* L);
    int listdir(lua_State* L);
};
//tolua_end

#endif
