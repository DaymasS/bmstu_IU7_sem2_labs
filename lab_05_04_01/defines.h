#ifndef __DEFINES__
#define __DEFINES__

#define OK 0
#define ERROR_INPUT_OUTPUT -1
#define ERROR_PARAM -2
#define ERROR_FILE_NOT_FOUND -3
#define ERROR_ARGUMENTS 53
#define ERROR_FILE_STRUCTURE -5
#define ERROR_FILE_EMPTY -6
#define ERROR_TRUNCATE -7

#define MAX_S_NAME_LENGTH 25
#define MAX_F_NAME_LENGTH 10
#define MAX_MARK_ARR_LENGTH 4

#include <stdint.h>

typedef struct
{
    char s_name[MAX_S_NAME_LENGTH + 1];
    char f_name[MAX_F_NAME_LENGTH + 1];
    uint32_t marks[MAX_MARK_ARR_LENGTH];
} student;

#endif
