#include "string_manip.h"

void rm(char *str)
{
    int char_set[256] = { 0 };
    char *src = str, *dst = str;
    while (*src != '\0')
    {
        if (!char_set[(unsigned char)*src])
        {
            char_set[(unsigned char)*src] = 1;
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

void filter(words words, int words_len, int *new_words_len)
{
    char last[WORD_SIZE_MAX + 1];
    strcpy(last, words[words_len - 1]);
    for (int i = 0; i < words_len - 1; i++)
    {
        if (strcmp(words[i], last) != 0)
        {
            rm(words[i]);
            if ((int)i != *new_words_len)
            {
                strcpy(words[*new_words_len], words[i]);
            }
            (*new_words_len)++;
        }
    }
}
