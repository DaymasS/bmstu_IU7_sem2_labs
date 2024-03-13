#include "my_string.h"

int split(char *string, words words, int *words_size);

int read_string(char *string)
{
    int return_code = OK;
    if (fgets(string, STRING_SIZE_MAX + 2, stdin) == NULL)
        return_code = ERROR;
    else
    {
        int len = strlen(string);
        if (string[len - 1] != '\n')
            return_code = ERROR;
        string[len - 1] = '\0';
    }
    return return_code;
}

int split(char *string, words words, int *words_size)
{
    char word[WORD_SIZE_MAX + 1];
    int len_word = 0;
    int len_str = strlen(string);

    for (int i = 0; i <= len_str; i++)
    {
        if (strchr(DELIMS, string[i]))
        {
            if (len_word > 0)
            {
                word[len_word] = '\0';
                strcpy(words[(*words_size)++], word);
                len_word = 0;
            }
        }
        else if (len_word < WORD_SIZE_MAX)
        {
            word[len_word++] = string[i];
        }
        else
            return ERROR;
    }
    if (*words_size == 0)
        return ERROR;

    return OK;
}

void print_result(words words, int words_len)
{
    printf("Result: ");
    int i;
    for (i = words_len - 1; i >= 1; i--)
    {
        printf("%s ", words[i]);
    }
    printf("%s", words[0]);
}

int split_and_filter(char *string, words words, int *words_size)
{
    int return_code = OK;
    *words_size = 0;
    if (!split(string, words, words_size))
    {
        int words_new_size = 0;
        filter(words, *words_size, &words_new_size);
        if (words_new_size == 0)
            return_code = ERROR;
        *words_size = words_new_size;
    }
    else
        return_code = ERROR;
    return return_code;
}
