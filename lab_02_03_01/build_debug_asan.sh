#!/bin/bash

if [ -f "main.c" ]; then
    if ! clang main.c -c -o main.o -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -O0 -g3 -pedantic ; then 
        exit 1
    fi
    if ! clang main.o -fsanitize=address -fno-omit-frame-pointer -g -o app.exe -lm ; then 
        exit 1
    fi
fi