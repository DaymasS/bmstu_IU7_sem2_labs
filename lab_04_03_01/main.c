#include "main.h"

int main(void)
{
    int return_code = OK, words_size;
    words words;
    char string[STRING_SIZE_MAX + 1];
    if (!read_string(string))
    {
        return_code = split_and_filter(string, words, &words_size);
        if (return_code == OK)
        {
            print_result(words, words_size);
        }
    }
    else
        return_code = ERROR;
    return return_code;
}
