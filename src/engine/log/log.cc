#include "log/log.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


namespace Log 
{

Logger logger;

static int s_warn_counter = 0;
static int s_error_counter = 0;

void fatal(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    logger.fatal(fmt, args);
    va_end(args);
}

void error(const char *fmt, ...)
{
    s_error_counter++;
    va_list args;
    va_start(args, fmt);
    logger.error(fmt, args);
    va_end(args);
}

void warn(const char *fmt, ...)
{
    s_warn_counter++;
    va_list args;
    va_start(args, fmt);
    logger.warn(fmt, args);
    va_end(args);
}

void info(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    logger.info(fmt, args);
    va_end(args);
}

void debug(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    logger.debug(fmt, args);
    va_end(args);
}

void openlevel(int level)
{
    logger.openlevel(level);
}

void closeall()
{
}

void closelevel(int level)
{
    logger.closelevel(level);
}

int stdout2file(const char *file_path)
{
    int fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd == -1)
    {
        LOG_ERROR("open file fail %s %s", file_path, strerror(errno));
        return 1;
    }else
    {
        if(dup2(fd, STDOUT_FILENO) == -1)
        {
            LOG_ERROR("dup2 FAIL %s", strerror(errno));
            return 1;
        }
        close(fd);
        return 0;
    }
}

};
