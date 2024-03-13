#include "test.h"
#define SIZE 5

int test_strpbrk(void)
{
    int diff = 0;
    const char *str[] = { "0987654321", "qwertyasdfgh", "dgdhshshshjd", "d f g e r 2 3 4 5 2", "35494" };
    const char *sym[] = { "693", "tysd", "h", "8 8", "nbd" };
    for (int i = 0; i < SIZE; ++i)
    {
        if (my_strpbrk(*(str + i), *(sym + i)) != strpbrk(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strspn(void)
{
    int diff = 0;
    const char *str[] = { "0987654321", "qwertyasdfgh", "dgdhshshshjd", "d f g e r 2 3 4 5 2", "35494" };
    const char *sym[] = { "693", "tysd", "h", "8 8", "nbd" };
    for (int i = 0; i < SIZE; ++i)
    {
        if (my_strspn(*(str + i), *(sym + i)) != strspn(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strcspn(void)
{
    int diff = 0;
    const char *str[] = { "0987654321", "qwertyasdfgh", "dgdhsheehshjd", "d f g e r 2 3 4 5 2", "35494" };
    const char *sym[] = { "9", "", "e", "a", "1234" };
    for (int i = 0; i < SIZE; ++i)
    {
        if (my_strcspn(*(str + i), *(sym + i)) != strcspn(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strchr(void)
{
    int diff = 0;
    const char *str[] = { "0987654321", "qwertyasdfgh", "dgdhshseeshjd", "d f g e r 0 3 4 5 2", "35494" };
    int sym[] = { (int)'5', (int)'a', (int)'e', (int)'\0', (int)'a' };
    for (int i = 0; i < SIZE; ++i)
    {
        if (my_strchr(*(str + i), *(sym + i)) != strchr(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}

int test_strrchr(void)
{
    int diff = 0;
    const char *str[] = { "0987654321", "qwertyasdfgh", "dgdhshshseejd", "d f g e r 2 3 4 5 2", "35494" };
    int sym[] = { (int)'5', (int)'f', (int)'e', (int)' ', (int)'f' };
    for (int i = 0; i < SIZE; ++i)
    {
        if (my_strrchr(*(str + i), *(sym + i)) != strrchr(*(str + i), *(sym + i)))
            diff++;
    }
    return diff;
}
