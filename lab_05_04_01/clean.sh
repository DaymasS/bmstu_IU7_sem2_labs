#!/bin/bash

postfixes="*.exe *.o *.c.gcov *.gcda *.gcno *.bin"

for postfix in $postfixes; do
    for name in $postfix; do
        if [ -f "$name" ]; then
            rm "$name"
        fi
    done
done

find . -type f -name "*_tmp.txt" -delete