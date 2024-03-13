#!/bin/bash

if [ -f "main.c" ]; then
    for name in *.c; do
        if ! clang -c "$name" -fsanitize=memory -fPIE -o "${name%%.c}.o" -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -pedantic -O0 -g3 ; then 
            exit 1
        fi
    done
    if ! clang -fsanitize=memory -fPIE -pie -o app.exe ./*.o -lm ; then 
        exit 1
    fi
fi