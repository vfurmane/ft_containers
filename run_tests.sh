#!/bin/bash

for directory in tests/*
do
	basename=$(basename $directory)
	printf ">>> %s\n" ${basename^^}
	for file in $directory/*.cpp
	do
		cpp=98
		if [[ "$file" == *-11.cpp ]]
		then
			cpp=11
		fi
		make $directory/$(basename -a -s .cpp $file) cpp=$cpp
		diff -y --width=80 <(./$directory/$(basename -a -s .cpp $file)_ft) <(./$directory/$(basename -a -s .cpp $file)_std)
	done
done
