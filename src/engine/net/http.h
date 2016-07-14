#ifndef _HTTP_H_
#define _HTTP_H_

namespace Http
{
    int urldecode(const char *str, const int str_len, char *result, const int result_len);
    int urlencode(const char *str, const int str_len, char *result, const int result_len);
};

#endif
