#!/bin/bash

verbose=1

# Key input
if [ "$1" == "-v" ]; then
	verbose=0
fi

# Check positive cases
numPosCases=1
numSuccessPosCases=0
fileDir="${0//func_tests.sh/}"

fileIn="$fileDir../data/pos_01_in.txt"
fileOut="$fileDir../data/pos_01_out.txt"

while [ -f "$fileIn" ]; do
    if bash "$fileDir/pos_case.sh" "$fileIn" "$fileOut"; then
        numSuccessPosCases=$((numSuccessPosCases + 1))
    fi

    numPosCases=$((numPosCases + 1))
    if [ "$numPosCases" -lt "10" ]; then
        fileIn="$fileDir../data/pos_0$numPosCases""_in.txt"
        fileArgs="$fileDir../data/pos_0$numPosCases""_args.txt"
        fileOut="$fileDir../data/pos_0$numPosCases""_out.txt"
    else
        fileIn="$fileDir../data/pos_$numPosCases""_in.txt"
        fileArgs="$fileDir../data/pos_$numPosCases""_args.txt"
        fileOut="$fileDir../data/pos_$numPosCases""_out.txt"
    fi
done
numPosCases=$((numPosCases - 1))

# Check negative cases
numNegCases=1
numSuccessNegCases=0
fileIn="$fileDir../data/neg_01_in.txt"
fileArgs="$fileDir../data/neg_01_args.txt"

while [ -f "$fileIn" ]; do
    if bash "$fileDir/neg_case.sh" "$fileIn"; then
        numSuccessNegCases=$((numSuccessNegCases + 1))
    fi

    numNegCases=$((numNegCases + 1))
    if [ "$numNegCases" -lt "10" ]; then
        fileIn="$fileDir../data/neg_0$numNegCases""_in.txt"
        fileArgs="$fileDir../data/pos_0$_args.txt"
    else
        fileIn="$fileDir../data/neg_$numNegCases""_in.txt"
    fi
done
numNegCases=$((numNegCases - 1))

# Conclusion of testing
numFailedCases=$((numPosCases + numNegCases - numSuccessPosCases - numSuccessNegCases))

if [ "$verbose" == "0" ]; then
    echo "Positive tests: $numSuccessPosCases / $numPosCases"
    echo "Negative tests: $numSuccessNegCases / $numNegCases"
    if [ "$numFailedCases" == "0" ]; then
        echo "Success!"
    else
        echo "Fail!"
    fi
fi

exit "$numFailedCases"