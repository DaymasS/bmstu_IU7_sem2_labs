#include <stdbool.h>
#include <ctype.h>

bool re(char *str)
{
    bool d = false;
    bool p = false;
    bool e = false;
    bool s = false;
    int rc = true;

    if (*str == '+' || *str == '-')
    {
        s = true;
        ++str;
    }

    while (*str != '\0' && rc)
    {
        if (isdigit(*str))
        {
            d = true;
        }
        else if (*str == '.')
        {
            if (p || e)
            {
                rc = false;
            }
            else
            {
                p = true;
            }
        }
        else if ((*str == 'e' || *str == 'E') && d && !e)
        {
            e = true;
            d = false;
            s = false;
        }
        else if ((*str == '+' || *str == '-') && e && !s && (*(str - 1) == 'e' || *(str - 1) == 'E'))
        {
            s = true;
        }
        else
        {
            rc = false;
        }
        ++str;
    }
    if (rc)
    {
        rc = d;
    }
    return rc;
}
