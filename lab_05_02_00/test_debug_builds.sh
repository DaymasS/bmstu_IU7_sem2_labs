#!/bin/bash

is_success=0
verbose=1

# Key input
if [ "$1" == "-v" ]; then
	verbose=0
fi

for file in ./build_*; do
    bash "$file"
    if [ "$?" == 1 ]; then
        echo "Exception in  $file"
        is_success=1
    fi
    if [ -f "app.exe" ]; then
        if [ "$verbose" == 0 ]; then
            ./func_tests/scripts/func_tests.sh -v
        else
            ./func_tests/scripts/func_tests.sh
        fi
        if [ "$?" == 1 ]; then
            echo "Exception in $file"
            is_success=1
        fi
    else
        echo "Exception in $file comp."
        is_success=1
    fi
done

if [[ "$is_success" == 0 ]]; then
    echo "All builds finished success!"
else
    echo "Some builds failed!"
fi