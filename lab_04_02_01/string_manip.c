#include "string_manip.h"

void sort(words words, int n)
{
    char tmp[WORD_SIZE_MAX + 1];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
                swap(words, j, j + 1, tmp);
        }
    }
}
