#include "my_string.h"

const char *my_strpbrk(const char *str_1, const char *str_2)
{
    const char *p = 0;
    for (const char *sign_1 = str_1; *sign_1 && !p; ++sign_1)
        for (const char *sign_2 = str_2; *sign_2 && !p; ++sign_2)
            if (*sign_1 == *sign_2)
                p = sign_1;
    return p;
}

size_t my_strspn(const char *str_1, const char *str_2)
{
    size_t len = 0;
    int was_found = 1;
    for (const char *sign_1 = str_1; *sign_1 && was_found; ++sign_1)
    {
        was_found = 0;
        for (const char *sign_2 = str_2; *sign_2; ++sign_2)
            if (*sign_1 == *sign_2)
                was_found = 1;
        if (was_found)
            len++;
    }
    return len;
}

size_t my_strcspn(const char *str_1, const char *str_2)
{
    size_t len = 0;
    int was_found = 0;
    for (const char *sign_1 = str_1; *sign_1 && !was_found; ++sign_1)
    {
        for (const char *sign_2 = str_2; *sign_2; ++sign_2)
            if (*sign_1 == *sign_2)
                was_found = 1;
        if (!was_found)
            len++;
    }
    return len;
}

const char *my_strchr(const char *str_1, int ch)
{
    const char *p = NULL;
    if (ch == 0)
    {
        for (; *str_1; ++str_1);
        p = str_1;
    }
    else
    {
        for (const char *sign_1 = str_1; *sign_1 && !p; ++sign_1)
            if (*sign_1 == ch)
                p = sign_1;
    }
    return p;
}

const char *my_strrchr(const char *str_1, int ch)
{
    const char *p = NULL;
    if (ch == 0)
    {
        for (; *str_1; ++str_1);
        p = str_1;
    }
    else
    {
        for (const char *sign_1 = str_1; *sign_1; ++sign_1)
            if (*sign_1 == ch)
                p = sign_1;
    }
    return p;
}
