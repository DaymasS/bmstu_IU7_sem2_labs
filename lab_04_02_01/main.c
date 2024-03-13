#include "main.h"

int main()
{
    int return_code = OK;
    char string[STRING_SIZE_MAX + 1];
    int words_size;
    words words;
    if (!read_string(string))
    {
        return_code = sort_split_words(string, words, &words_size);
        if (return_code == OK)
        {
            print_words(words, words_size);
        }
    }
    else
        return_code = ERROR;
    return return_code;
}
