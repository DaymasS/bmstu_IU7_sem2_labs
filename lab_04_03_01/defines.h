#ifndef __DEFINES__
#define __DEFINES__

#define OK 0
#define ERROR 1

#define STRING_SIZE_MAX 256
#define WORD_SIZE_MAX 16
#define DELIMS " ,;:-.!?"

#include <stdio.h>
#include <string.h>

typedef char words[STRING_SIZE_MAX / 2][WORD_SIZE_MAX + 1];

#endif
