#!/bin/bash

if [ -f "main.c" ]; then
    if ! gcc -c main.c -o main.o -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -pedantic -O0 -g3 ; then 
        exit 1
    fi
    if ! gcc main.o -o app.exe -lm ; then 
        exit 1
    fi
fi