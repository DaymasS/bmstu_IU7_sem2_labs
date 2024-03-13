#!/bin/bash

if [ $# == "3" ]; then
    fileStreamIn=$1
    expectFileStreamOut=$2
    fileArgsIn=$3
else
    exit 2
fi

# Check existance of files
if ! [ -f "$fileStreamIn" ]; then
	exit 2
fi

if ! [ -f "$expectFileStreamOut" ]; then
	exit 2
fi

if ! [ -f "$fileArgsIn" ]; then
	exit 2
fi

fileDir="${0//pos_case.sh/}"
args=$(cat "$fileArgsIn")


"$fileDir../.././app.exe" $args < "$fileStreamIn" > "$fileDir./out_tmp.txt"
exitCode=$?

bash "$fileDir./comparator.sh" "$fileDir./out_tmp.txt" "$expectFileStreamOut"
areEquale=$?

if [[ "$exitCode" == "0" ]] && [[ $areEquale == "0" ]]; then
    exit 0
else
    exit 1
fi