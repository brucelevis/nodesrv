#include "log/filelogger.h"



FileLogger::FileLogger()
{
    current_file = NULL;
    linecounter = 0;
    max_linenum = 0;
    max_filesize = 0;
    set_file_format("log_%Y_%M_%D");
    set_bak_file_format("log_%Y_%M_%D_%H_%m_%S");
}

void FileLogger::set_bak_file_format(const char* val)
{
    strcpy(this->bak_file_format, val);
}

void FileLogger::set_file_format(const char* val)
{
    strcpy(this->file_format, val);
    _vsprintf(this->current_file_path, this->file_format, "", "");
}

void FileLogger::rotate_log_file(bool force)
{
    if(force)
    {
        goto rotate;
    }
    if(max_linenum != 0)
    {
        if(linecounter++ >= max_linenum)
        {
            linecounter = 0;
            goto rotate;
        }
    }
    if(max_filesize != 0)
    {
        struct stat statbuff;
        if (!stat(current_file_path, &statbuff))
        {
            if(statbuff.st_size >= max_filesize)
            {
                goto rotate;
            }
        }
    }
    return;
rotate:
    static char bak_file_path[FILENAME_MAX];
    _vsprintf(bak_file_path, this->bak_file_format, "", "");
    //重命名文件
    rename(current_file_path, bak_file_path);
}

void FileLogger::log(const char* str)
{
    rotate_log_file(false);
    if(access(current_file_path, 0))
    {
        if(current_file)
        {
            fclose(current_file);
            current_file = NULL;
        }
    }
    if(!current_file)
    {
        current_file = fopen(current_file_path, "a+");
    }
    if(!current_file)
    {
        return;
    }
    size_t str_len = strlen(str);
    fwrite(str, 1, str_len, current_file);
    fflush(current_file);
}


