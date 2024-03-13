#!/bin/bash

verbose=1

# Key input
if [ "$1" == "-v" ]; then
	verbose=0
fi

for name in ./lab_*; do
	cd "$name" || exit 1
    if [ -f "test_debug_builds.sh" ]; then
        echo "$name :"
        if [ "$verbose" == 0 ]; then
            ./test_debug_builds.sh -v
        else
            ./test_debug_builds.sh
        fi
        echo 
    fi
	cd ..
done