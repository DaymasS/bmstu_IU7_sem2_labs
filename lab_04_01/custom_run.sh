#!/bin/bash

cd "$(dirname "$0")" || exit
bash build_debug.sh
./app.exe
bash clean.sh