#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include "defines.h"
#include "string_manip.h"
#include <stdio.h>

int read_string(char *string);

int sort_split_words(char *string, words words, int *words_size);

int in(char *string, words words, int words_size);

void swap(words words, int i, int j, char tmp[WORD_SIZE_MAX + 1]);

void print_words(words words, int str_size);

#endif
