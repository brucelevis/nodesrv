
#ifndef _LOG_H_
#define _LOG_H_

#include "log/logger.h"

namespace Log 
{

extern Logger logger;

void fatal(const char *fmt, ...);
void error(const char *fmt, ...);
void warn(const char *fmt, ...);
void info(const char *fmt, ...);
void debug(const char *fmt, ...);

void openlevel(int level);
void closelevel(int level);
void closeall();

int stdout2file(const char *file_path);

};

#define LOG_FATAL(str, ...)     Log::fatal("%s:%d", __FILE__, __LINE__);\
                                Log::fatal(str, ## __VA_ARGS__);

#define LOG_ERROR(str, ...)     Log::error("%s:%d", __FILE__, __LINE__);\
                                Log::error(str, ## __VA_ARGS__);

#define LOG_WARN(str, ...)      Log::warn("%s:%d", __FILE__, __LINE__);\
                                Log::warn(str, ## __VA_ARGS__);

#define LOG_INFO(str, ...)      Log::info(str, ## __VA_ARGS__);

#define LOG_DEBUG(str, ...)     Log::debug("%s:%d", __FILE__, __LINE__);\
                                Log::debug(str, ## __VA_ARGS__);

#endif
