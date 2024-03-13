#include "my_string.h"

int read_string(char *string)
{
    int return_code = OK;
    if (fgets(string, STRING_SIZE_MAX + 2, stdin) == NULL)
        return_code = ERROR;
    else
    {
        size_t len = strlen(string);
        if (string[len - 1] != '\n')
            return_code = ERROR;
        string[len - 1] = '\0';
    }
    return return_code;
}

char *trim(char *s)
{
    char *start = s;
    while (isspace(*start))
        start++;
    size_t len = strlen(s);
    char *end = s + len - 1;
    while (end > start && isspace(*end))
        end--;
    end[1] = '\0';
    return start;
}
