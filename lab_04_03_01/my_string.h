#ifndef MY_STRING_H
#define MY_STRING_H

#include "defines.h"
#include "string_manip.h"

int read_string(char *string);

int split_and_filter(char *string, words words, int *words_size);

#endif
