#!/bin/bash

if [ -f "main.c" ]; then
    for name in *.c; do
        if ! clang -c "$name" -o "${name%%.c}.o" -fsanitize=undefined -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -pedantic -O0 -g3 ; then 
            exit 1
        fi
    done
    if ! clang -fsanitize=undefined -o app.exe ./*.o -lm ; then 
        exit 1
    fi
fi