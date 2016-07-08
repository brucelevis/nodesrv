#ifndef __FILE_H__
#define __FILE_H__ 

extern "C" 
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

//tolua_begin
namespace File 
{

    enum 
    {
        TYPE_FILE = 1,
        TYPE_DIR = 2,
    };

    char *getcwd();

    bool chdir(const char* dir);

    bool mkdirs(char* dir);

    bool mkdir(char* dir);

    bool exists(char* dir);

    bool remove(const char* dir);

    bool rename(char* src, char* dst);

    int basename(lua_State* L);

    const char* dirname(const char* path);

    int listdir(lua_State* L);

    bool cdself();
};
//tolua_end

#endif
