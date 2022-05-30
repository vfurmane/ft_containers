#!/bin/bash

NC="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

for directory in tests/*
do
	basename_dir=$(basename $directory)
	printf ">>> %s\n" ${basename_dir^^}
	mkdir -p logs/$basename_dir
	for file in $directory/*.cpp
	do
		basename_file=$(basename -a -s .cpp $file)
		cpp=98
		if [[ "$file" == *-11.cpp ]]
		then
			cpp=11
		fi
		printf " %-64s:  []" $basename_file
		if ! make $directory/${basename_file}_std n=std cpp=$cpp > logs/$basename_dir/${basename_file}_std_compilation 2>&1
		then
			printf "\r %-64s: [${RED}INTERNAL${NC}]\n" $basename_file
			continue
		fi
		if ! make $directory/${basename_file}_ft n=ft cpp=$cpp > logs/$basename_dir/${basename_file}_ft_compilation 2>&1
		then
			printf "\r %-64s: [${RED}COMPILATION${NC}]\n" $basename_file
			continue
		fi
		if ! diff -y --width=80 <(./$directory/${basename_file}_ft) <(./$directory/${basename_file}_std) > logs/$basename_dir/${basename_file}_test 2>&1
		then
			printf "\r %-64s: [${RED}KO${NC}]\n" $basename_file
			continue
		fi
		printf "\r %-64s: [${GREEN}OK${NC}]\n" $basename_file
	done
done
