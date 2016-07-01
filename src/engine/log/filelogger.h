#ifndef __FILE_LOGGER_H__
#define __FILE_LOGGER_H__

#include "log/logger.h"
/*
 * example:
 *
 *  FileLogger logger;
    logger.set_tag("gatesrv1");
    logger.set_format("[%06Y][%T][%P][%L]%s\n");
    logger.max_linenum = 2;
    logger.info("helloaaaba");
    logger.info("helloaaabb");
    logger.info("helloaaabc");
 */

class FileLogger : public Logger
{
public:
    FileLogger();

    virtual void log(const char* str);
    void set_file_format(const char* val);
    void set_bak_file_format(const char* val);
private:
    void rotate_log_file(bool force);
public:
    int max_linenum;
    int max_filesize;
private:
    char current_file_path[FILENAME_MAX];
    char file_format[FILENAME_MAX];
    char bak_file_format[FILENAME_MAX];
    int linecounter;
    FILE* current_file;

};

#endif
