#include "my_string.h"

int split(char *string, words words, int *words_size);

int sort_split_words(char *string, words words, int *words_size)
{
    int return_code = OK;
    *words_size = 0;
    if (split(string, words, words_size) == OK)
    {
        sort(words, *words_size);
    }
    else
        return_code = ERROR;
    return return_code;
}

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

int in(char *string, words words, int words_size)
{
    int result = 0;
    for (int i = 0; i < words_size && !result; i++)
    {
        if (!strcmp(words[i], string))
            result = 1;
    }
    return result;
}

void swap(words words, int i, int j, char tmp[WORD_SIZE_MAX + 1])
{
    strcpy(tmp, words[i]);
    strcpy(words[i], words[j]);
    strcpy(words[j], tmp);
}

int split(char *string, words words, int *words_size)
{
    int return_code = OK;
    char word[WORD_SIZE_MAX + 1];
    int len_word = 0;
    int len_str = strlen(string);

    for (int i = 0; i <= len_str && return_code == OK; i++)
    {
        if (strchr(DELIMS, string[i]))
        {
            if (len_word > 0)
            {
                word[len_word] = '\0';
                if (!in(word, words, *words_size))
                {
                    strcpy(words[(*words_size)++], word);
                }
                len_word = 0;
            }
        }
        else if (len_word < WORD_SIZE_MAX)
        {
            word[len_word++] = string[i];
        }
        else
            return_code = ERROR;
    }

    if (*words_size == 0)
        return_code = ERROR;

    return return_code;
}

void print_words(words words, int words_size)
{
    int i;
    printf("Result: ");
    for (i = 0; i < words_size - 1; i++)
        printf("%s ", words[i]);
    printf("%s", words[i]);
}
