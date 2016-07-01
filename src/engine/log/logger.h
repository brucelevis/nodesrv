#ifndef __LOGGER_H__
#define __LOGGER_H__

//日志类

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>

#define FATAL   0
#define ERROR   1
#define WARN    2
#define INFO    3
#define DEBUG   4

#define LOG_LEVEL_MAX = 5

class Logger
{
public:
    Logger();
public:
    void fatal(const char* fmt, ...);
    void error(const char* fmt, ...);
    void warn(const char* fmt, ...);
    void info(const char* fmt, ...);
    void debug(const char* fmt, ...);

    void fatal(const char* fmt, va_list args); 
    void error(const char* fmt, va_list args);
    void warn(const char* fmt, va_list args);
    void info(const char* fmt, va_list args);
    void debug(const char* fmt, va_list args);

    void openlevel(int level);
    void closelevel(int level);

    void set_tag(const char* val);
    void set_format(const char* val);

    virtual void log(const char* str);

protected:
    int _vsprintf(char *buf, const char* fmt, const char* level, const char *msg);
private:
    void log_vprint(int level, const char *fmt, va_list ap);
private:
    int32_t flag;
    char tag[64];
    char format[64];
};

#endif
