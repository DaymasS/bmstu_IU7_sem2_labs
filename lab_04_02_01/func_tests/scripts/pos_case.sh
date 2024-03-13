#!/bin/bash

if [ $# == "2" ]; then
    fileStreamIn=$1
    expectFileStreamOut=$2
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

fileDir="${0//pos_case.sh/}"

"$fileDir../.././app.exe" < "$fileStreamIn" > "$fileDir./out_tmp.txt"
exitCode=$?

bash "$fileDir./comparator.sh" "$fileDir./out_tmp.txt" "$expectFileStreamOut"
areEquale=$?

if [[ "$exitCode" == "0" ]] && [[ $areEquale == "0" ]]; then
    exit 0
else
    exit 1
fi