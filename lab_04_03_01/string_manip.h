#ifndef STRING_MANIP
#define STRING_MANIP

#include "defines.h"
#include "my_string.h"

void rm(char *word);

void filter(words words, int words_len, int *new_words_len);
void print_result(words words, int words_len);

#endif
