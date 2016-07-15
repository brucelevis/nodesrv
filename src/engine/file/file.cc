#include "file.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

namespace File 
{

bool cdself()
{
    //static char dir[1024];
    //int count = readlink( "/proc/self/exe", dir, sizeof(dir));
    //if(count < 0 || count >= sizeof(dir)) 
    //{
        //return false;
    //}
	//if(::chdir(dir)) 
    //{
        //return false;
    //}
    return true;
}

//功能：当前目录
char* getcwd()
{
    static char buf[128];
    buf[0] = 0;
	::getcwd(buf, sizeof(buf));
    return buf;
}

//功能：切换目录
bool chdir(const char *dir)
{
	if(::chdir(dir)) 
    {
        return false;
    }
    return true;
}

//功能：创建目录
bool mkdirs(char *dir)
{
    size_t i;
    size_t dir_len = 0;
    for(i = 0; i < dir_len; i++)
    {
        if(dir[i] == '/'){
            char c = dir[i];
            dir[i] = 0;
            if(access(dir, 0))
            {
                ::mkdir(dir, 0777);    
            }
            dir[i] = c;
        }
    }
    if(access(dir, 0))
    {
        ::mkdir(dir, 0777);    
    }
    return true;
}


//功能：创建目录
bool mkdir(char* dir)
{
    if(::mkdir(dir, 0777))
    {
        return true;
    }
    return false;
}

//功能：目录或者文件是否已经存在
bool exists(char *dir)
{
    int amode = 0;
    if(::access(dir, amode)) 
    {
        return false;
    }
    return true;
}

//功能：删除文件或者目录
bool remove(const char *filepath)
{
    if(::remove(filepath)) 
    {
        return false;
    }
    return true;
}

//功能：返回文件名

//功能：重命名
bool rename(char *src, char *dst)
{
    if(::rename(src, dst)) 
    {
        return false;
    }
    return true;
}

const char* dirname(const char* path)
{
    static char result[128];
    int str_len = strlen(path);
    int startpos = 0;
    int endpos = str_len - 1;
    for (int i = str_len - 1; i >= 0; i--) 
    {
        if (path[i] == '/' or path[i] == '\\') 
        {
            endpos = i;
            break;
        }
    }
    if (startpos < endpos)
    {
        memcpy(result, path, endpos - startpos + 1);
        result[endpos - startpos + 1] = 0;
        return result;
    } else 
    {
        strcpy(result, path);
        return result;
    }
}

int extname(lua_State* L)
{
    char *name;
    size_t str_len = 0;
    name = (char *)lua_tolstring(L, 1, &str_len);
    int startpos = 0;
    for (int i = str_len - 1; i >= 0; i--) 
    {
        if (name[i] == '.') 
        {
            startpos = i + 1;
            break;
        }
    }
    int endpos = str_len - 1;
    lua_pushlstring(L, name + startpos, endpos - startpos + 1);
    return 1;
}

int basename(lua_State* L)
{
    char *name;
    size_t str_len = 0;
    name = (char *)lua_tolstring(L, 1, &str_len);
    int startpos = 0;
    for (int i = str_len - 1; i >= 0; i--) 
    {
        if (name[i] == '/') 
        {
            startpos = i + 1;
            break;
        }
    }
    int endpos = str_len - 1;
    for (int i = str_len - 1; i >= 0; i--) 
    {
        if (name[i] == '.') 
        {
            endpos = i - 1;
            break;
        }
    }
    if (startpos > endpos) 
    {
        lua_pushstring(L, "");
        return 1;
    } else 
    {
        lua_pushlstring(L, name + startpos, endpos - startpos + 1);
        return 1;
    }
}

/*
 * 
 * 返回值 {{type = 'file|dir', name = ''}, ...}
 */
int listdir(lua_State *L)
{
	if (lua_gettop(L) == 1 && lua_isstring(L, 1))
    {
		const char *dir_name = (const char *)lua_tostring(L, 1);
        struct dirent *ent;
        DIR *dir = opendir(dir_name);
        if(dir == NULL)
        {
            return 0;
        }
        lua_newtable(L);
        int idx = 1;
        while((ent = readdir(dir)) != NULL)
        {
            if(ent->d_type & DT_DIR || ent->d_type & DT_REG)
            {
                if(strcmp(ent->d_name, ".") == 0)
                {
                    continue;
                }
                if(strcmp(ent->d_name, "..") == 0)
                {
                    continue;
                }
                lua_pushnumber(L, idx++);

                lua_newtable(L);
                lua_pushstring(L, "type");
                if(ent->d_type & DT_DIR)
                {
                    lua_pushnumber(L, TYPE_DIR);
                }
                else
                {
                    lua_pushnumber(L, TYPE_FILE);
                }
                lua_settable(L, -3);

                lua_pushstring(L, "name");
                lua_pushstring(L, ent->d_name);
                lua_settable(L, -3);

                lua_settable(L, -3);
            }
        }
        closedir(dir);
        return 1;
	}
    return 0;
}


};
