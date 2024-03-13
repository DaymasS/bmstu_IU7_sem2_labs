#!/bin/bash

if [ $# == "2" ]; then
    fileStreamIn=$1
    fileArgsIn=$2
else
    exit 2
fi

# Check existance of file
if ! [ -f "$fileStreamIn" ]; then
	exit 2
fi

if ! [ -f "$fileArgsIn" ]; then
	exit 2
fi

fileDir="${0//neg_case.sh/}"
args=$(cat "$fileArgsIn")

"$fileDir../.././app.exe" $args < "$fileStreamIn" > "$fileDir./out_tmp.txt"
exitCode=$?

if [[ "$exitCode" != "0" ]]; then
    exit 0
else
    exit 1
fi