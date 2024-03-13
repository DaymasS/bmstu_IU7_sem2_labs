#!/bin/bash

verbose=1
fileCounter=0
exceptionLetter1="Only two files can be compared"

# Key input
for arg in "$@"; do
	if [[ $arg =~ ^- ]]; then
		if [ "$arg" == "-v" ]; then
			verbose=0
		else
			echo There is no such key \("$arg"\)
			exit 2
		fi
	fi
done


for arg in "$@"; do
	if ! [[ $arg =~ ^- ]]; then
		if [ $fileCounter -eq 2 ]; then
			if [ $verbose -eq 0 ]; then
				echo "$exceptionLetter1"
			fi
			exit 2
		else
			if [ $fileCounter -eq 0 ]; then
				file1=$arg
			else
				file2=$arg
			fi
			fileCounter=$((fileCounter + 1))
		fi
	fi
done

if [ $fileCounter -lt 2 ]; then 
	if [ $verbose -eq 0 ]; then
		echo "$exceptionLetter1"
	fi
	exit 2
fi

if ! [ -f "$file1" ]; then
	if [ $verbose -eq 0 ]; then
		echo First file doesn\'t exist
	fi
	exit 2
fi

if ! [ -f "$file2" ]; then
	if [ $verbose -eq 0 ]; then
		echo Second file doesn\'t exist
	fi
	exit 2
fi

tempDir=$(mktemp -d "${TMDIR:-/tmp/}$(basename "$0").XXXXXXXX")
tempFile1=$tempDir"/compFile1"
tempFile2=$tempDir"/compFile2"
echo "" >"$tempFile1"
echo "" >"$tempFile2"

exec 4<"$file1"
word=""
while IFS= read -rn1 a <&4; do
	letter="${a:-$'\n'}";
	if [[ $letter =~ [[:space:]] ]]; then
		if [[ $word =~ ^[-+]*[0-9]+$ ]]; then
			echo "$word" >>"$tempFile1"
		elif [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)$ ]]; then
			echo  "$word" >>"$tempFile1"
		elif [[ $word =~ ^[-+]?([.]{1}[0-9]+)$ ]]; then
			echo  "$word" >>"$tempFile1"
		fi
		word=""
	else
		word=$word$letter
	fi
done

if [[ $word =~ ^[-+]*[0-9]+$ ]]; then
	echo "$word" >>"$tempFile1"
elif [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)$ ]]; then
	echo  "$word" >>"$tempFile1"
elif [[ $word =~ ^[-+]?([.]{1}[0-9]+)$ ]]; then
	echo  "$word" >>"$tempFile1"
fi


exec 4<"$file2"
word=""
while IFS= read -rn1 a <&4; do
	letter="${a:-$'\n'}";
	if [[ $letter =~ [[:space:]] ]]; then
		if [[ $word =~ ^[-+]*[0-9]+$ ]]; then
			echo "$word" >>"$tempFile2"
		elif [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)$ ]]; then
			echo  "$word" >>"$tempFile2"
		elif [[ $word =~ ^[-+]?([.]{1}[0-9]+)$ ]]; then
			echo  "$word" >>"$tempFile2"
		fi
		word=""
	else
		word=$word$letter
	fi
done

if [[ $word =~ ^[-+]*[0-9]+$ ]]; then
	echo "$word" >>"$tempFile2"
elif [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)$ ]]; then
	echo  "$word" >>"$tempFile2"
elif [[ $word =~ ^[-+]?([.]{1}[0-9]+)$ ]]; then
	echo  "$word" >>"$tempFile2"
fi

if cmp -s "$tempFile1" "$tempFile2"; then
	if [ $verbose -eq 0 ]; then
		echo Files are equal
	fi
	rm -r "$tempDir"
	exit 0
else
	if [ $verbose -eq 0 ]; then
		echo Files are different
	fi
	rm -r "$tempDir"
	exit 1
fi