#!/bin/bash

if [ -f "main.c" ]; then
    for name in *.c; do
        if [[ "$name" != "comp_bin.c" ]] ; then
            if ! gcc -c "$name" -o "${name%%.c}.o" -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -pedantic -O3 ; then 
                exit 1
            fi
        fi
    done
    if ! gcc -o app.exe ./*.o -lm ; then 
        exit 1
    fi
fi