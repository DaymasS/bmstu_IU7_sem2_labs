#include "main.h"

int main(void)
{
    int return_code = OK;
    char string[STRING_SIZE_MAX + 1];
    if (!read_string(string))
    {
        char *n_s = trim(string);
        if (re(n_s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
        return_code = ERROR;
    return return_code;
}
