#!/bin/bash

if [ -f "main.gcda" ]; then
    rm "main.gcda"
fi


if [ -f "main.c" ]; then
    gcc main.c -c -o main.o -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -g3 -pedantic -ftest-coverage -fprofile-arcs
    gcc main.o -o app.exe -lm -fprofile-arcs 
    ./func_tests/scripts/func_tests.sh -v
    gcov main.c
fi