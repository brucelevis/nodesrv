#include "net/http.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

namespace Http 
{
#define NON_NUM '0'

    static int hex2num(char c)
    {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
        return NON_NUM;
    }

    int urldecode(const char *str, const int str_len, char *result, const int result_len)
    {
        char ch, ch1, ch2;
        int i;
        int j = 0;
        if ((str == NULL) || (result == NULL) || (str_len <= 0) || (result_len <= 0)) 
        {
            return 0;
        }
        for (i = 0; i < str_len && j < result_len; ++i) 
        {
            ch = str[i];
            switch (ch) 
            {
                case '+':
                    result[j++] = ' ';
                    break;
                case '%':
                    if (i + 2 < str_len) 
                    {
                        ch1 = hex2num(str[i + 1]);
                        ch2 = hex2num(str[i + 2]);
                        if ((ch1 != NON_NUM) && (ch2 != NON_NUM)) 
                        {
                            result[j++] = (char)((ch1 << 4) | ch2);
                        }
                        i += 2;
                        break;
                    } else 
                    {
                        break;
                    }
                default:
                    result[j++] = ch;
                    break;
            }
        }
        result[j] = 0;
        return j;
    }

    int urlencode(const char *str, const int str_len, char *result, const int result_len)
    {
        int i;
        int j = 0;
        char ch;

        if ((str == NULL) || (result == NULL) || (str_len <= 0) || (result_len <= 0)) 
        {
            return 0;
        }
        for (i = 0; i < str_len && j < result_len; ++i) 
        {
            ch = str[i];
            if (((ch >= 'A') && (ch < 'Z')) ||
                    ((ch >= 'a') && (ch < 'z')) ||
                    ((ch >= '0') && (ch < '9'))) 
            {
                result[j++] = ch;
            } else if (ch == ' ')
            {
                result[j++] = '+';
            } else if (ch == '.' || ch == '-' || ch == '_' || ch == '*') 
            {
                result[j++] = ch;
            } else 
            {

                if (j + 3 < result_len) 
                {
                    sprintf(result + j, "%%%02X", (unsigned char)ch);
                    j += 3;
                } else 
                {
                    return 0;
                }
            }
        }
        result[j] = '\0';
        return j;
    }
}
