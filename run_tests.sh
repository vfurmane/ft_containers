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

perform_test_in_folder()
{
	if [ -z "$1" ] || [ -z "$2" ]
	then
		return 1
	fi
	local directory=$1
	local basename_dir=$2
	local level=$(awk -F'/' '{print NF-1}' <<< "$basename_dir")
	printf "%*s>>> %s\n" $level "" ${basename_dir^^}
	mkdir -p logs/$basename_dir
	for file in $directory/*
	do
		if [ -d "$file" ]
		then
			perform_test_in_folder $file $basename_dir/$(basename $file)
			continue
		fi
		if [[ "$file" != *.cpp ]]
		then
			continue
		fi
		basename_file=$(basename -a -s .cpp "$file")
		cpp=98
		if [[ "$file" == *-11.cpp ]]
		then
			cpp=11
		fi
		printf '%*s%-*s:  []' $(($level + 1)) "" $((64 - $level)) "$basename_file"
		already_printed=0
		if ! make "$directory/${basename_file}_std" n=std cpp=$cpp > "logs/$basename_dir/${basename_file}_std_compilation" 2>&1
		then
			printf "\r%*s%-*s: [${RED}INTERNAL${NC}]\n" $(($level + 1)) "" $((64 - $level)) $basename_file
			continue
		fi
		if ! make "$directory/${basename_file}_ft" n=ft cpp=98 > "logs/$basename_dir/${basename_file}_ft_compilation" 2>&1
		then
			printf "\r%*s%-*s: [${RED}COMPILATION${NC}]\n" $(($level + 1)) "" $((64 - $level)) "$basename_file"
			fails=$(($fails + 1))
			continue
		fi
		test_case "./$directory/${basename_file}_std" > "logs/$basename_dir/${basename_file}_std_test" 2>&1
		exit_code=$?
		if [ $exit_code -gt 0 ]
		then
			[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${RED}INTERNAL${NC}]\n" $(($level + 1)) "" $((64 - $level)) $basename_file
			already_printed=1
		fi
		printf "exited with code %d\n" $exit_code > "logs/$basename_dir/${basename_file}_std_exit"
		test_case "./$directory/${basename_file}_ft" > "logs/$basename_dir/${basename_file}_ft_test" 2>&1
		exit_code=$?
		if [ $exit_code -gt 0 ]
		then
			[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${RED}KO${NC}]\n" $(($level + 1)) "" $((64 - $level)) $basename_file
			already_printed=1
			fails=$(($fails + 1))
		fi
		printf "exited with code %d\n" $exit_code > "logs/$basename_dir/${basename_file}_ft_exit"
		if ! diff -y --width=80 "logs/$basename_dir/${basename_file}_ft_test" "logs/$basename_dir/${basename_file}_std_test" > "logs/$basename_dir/${basename_file}_test" 2>&1
		then
			[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${RED}KO${NC}]\n" $(($level + 1)) "" $((64 - $level)) "$basename_file"
			already_printed=1
			fails=$(($fails + 1))
		fi
		[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${GREEN}OK${NC}]\n" $(($level + 1)) "" $((64 - $level)) "$basename_file"
	done
}

for directory in tests/*
do
	if [ -f $directory ]
	then
		continue
	fi
	basename_dir=$(basename $directory)
	perform_test_in_folder $directory $basename_dir
done

if [ $fails -gt 0 ]
then
	exit 1
fi
