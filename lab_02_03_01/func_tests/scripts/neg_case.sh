#!/bin/bash

if [ $# == "1" ]; then
    fileStreamIn=$1
else
    exit 2
fi

# Check existance of file
if ! [ -f "$fileStreamIn" ]; then
	exit 2
fi

fileDir="${0//neg_case.sh/}"

"$fileDir../.././app.exe" < "$fileStreamIn" > "$fileDir./out_tmp.txt"
exitCode=$?


if [[ "$exitCode" != "0" ]]; then
    exit 0
else
    exit 1
fi