#!/bin/bash

NC="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

fails=0

test_case()
{
	"$@"
	return $?
}

for directory in tests/*
do
	if [ -f $directory ]
	then
		continue
	fi
	basename_dir=$(basename $directory)
	printf ">>> %s\n" ${basename_dir^^}
	mkdir -p logs/$basename_dir
	for file in $directory/*.cpp
	do
		basename_file=$(basename -a -s .cpp "$file")
		cpp=98
		if [[ "$file" == *-11.cpp ]]
		then
			cpp=11
		fi
		printf ' %-64s:  []' "$basename_file"
		already_printed=0
		if ! make "$directory/${basename_file}_std" n=std cpp=$cpp > "logs/$basename_dir/${basename_file}_std_compilation" 2>&1
		then
			printf "\r %-64s: [${RED}INTERNAL${NC}]\n" $basename_file
			continue
		fi
		if ! make "$directory/${basename_file}_ft" n=ft cpp=98 > "logs/$basename_dir/${basename_file}_ft_compilation" 2>&1
		then
			printf "\r %-64s: [${RED}COMPILATION${NC}]\n" "$basename_file"
			fails=$(($fails + 1))
			continue
		fi
		test_case "./$directory/${basename_file}_std" > "logs/$basename_dir/${basename_file}_std_test" 2>&1
		exit_code=$?
		if [ $exit_code -gt 0 ]
		then
			[ $already_printed -eq 0 ] && printf "\r %-64s: [${RED}INTERNAL${NC}]\n" $basename_file
			already_printed=1
		fi
		printf "exited with code %d\n" $exit_code > "logs/$basename_dir/${basename_file}_std_exit"
		test_case "./$directory/${basename_file}_ft" > "logs/$basename_dir/${basename_file}_ft_test" 2>&1
		exit_code=$?
		if [ $exit_code -gt 0 ]
		then
			[ $already_printed -eq 0 ] && printf "\r %-64s: [${RED}KO${NC}]\n" $basename_file
			already_printed=1
			fails=$(($fails + 1))
		fi
		printf "exited with code %d\n" $exit_code > "logs/$basename_dir/${basename_file}_ft_exit"
		if ! diff -y --width=80 "logs/$basename_dir/${basename_file}_ft_test" "logs/$basename_dir/${basename_file}_std_test" > "logs/$basename_dir/${basename_file}_test" 2>&1
		then
			[ $already_printed -eq 0 ] && printf "\r %-64s: [${RED}KO${NC}]\n" "$basename_file"
			already_printed=1
			fails=$(($fails + 1))
		fi
		[ $already_printed -eq 0 ] && printf "\r %-64s: [${GREEN}OK${NC}]\n" "$basename_file"
	done
done

if [ $fails -gt 0 ]
then
	exit 1
fi
