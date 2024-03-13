#!/bin/bash

if [ -f "main.c" ]; then
    gcc -c main.c -o main.o -Wfloat-equal -Wfloat-conversion -Wall -Werror -std=c99 -Wextra -O3 -pedantic
    gcc main.o -o app.exe -lm
fi