#!/bin/bash

for name in ./lab_*; do
	cd "$name" || exit 1
	if [ -f "clean.sh" ]; then
		bash "./clean.sh"
	fi
	cd ..
done