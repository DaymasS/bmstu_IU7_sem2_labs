#ifndef __FILE_MANIP_H__
#define __FILE_MANIP_H__

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "defines.h"

int read_file(FILE *, FILE *, char[MAX_S_NAME_LENGTH], student *);
int sort_file(FILE *, student *, student *);
int create_file(FILE *, student *);
int print_st_data(FILE *, student *);
int cut_file(FILE *, student *);

#endif
