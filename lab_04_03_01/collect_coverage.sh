#!/bin/bash

if [ -f "main.c" ]; then
    for name in *.c; do
        if [ -f "${name%%.c}.gcda" ]; then
            rm "${name%%.c}.gcda"
        fi
        if ! gcc -c "$name" -o "${name%%.c}.o" -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -g3 -pedantic -ftest-coverage -fprofile-arcs ; then
            exit 1
        fi
    done
    if ! gcc -o app.exe ./*.o -lm -fprofile-arcs ; then 
        exit 1
    fi
    ./func_tests/scripts/func_tests.sh -v
    for name in *.c; do
        gcov "$name"
    done
fi