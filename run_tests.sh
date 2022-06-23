#!/bin/bash

NC="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

LEAK_CODE=148
NO_LEAK_CHECK=0

fails=0

print_usage()
{
	printf "Usage:	$0 [-hl]\n"
	printf "\n"
	printf "\t-h\tprint this message and exit\n"
	printf "\t-l\tdisable leak check\n"
}

test_case()
{
	if [ $NO_LEAK_CHECK -eq 0 ]
	then
		valgrind --leak-check=full --track-origins=yes --log-file=$memcheck_log_file --error-exitcode=$LEAK_CODE "$@"
	else
		"$@"
	fi
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
	local memcheck_log_file
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
		memcheck_log_file=logs/$basename_dir/${basename_file}_std_leaks
		test_case "./$directory/${basename_file}_std" > "logs/$basename_dir/${basename_file}_std_test" 2>&1
		exit_code=$?
		if [ $exit_code -gt 0 ]
		then
			[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${RED}INTERNAL${NC}]\n" $(($level + 1)) "" $((64 - $level)) $basename_file
			already_printed=1
		fi
		printf "exited with code %d\n" $exit_code > "logs/$basename_dir/${basename_file}_std_exit"
		memcheck_log_file=logs/$basename_dir/${basename_file}_ft_leaks
		test_case "./$directory/${basename_file}_ft" > "logs/$basename_dir/${basename_file}_ft_test" 2>&1
		exit_code=$?
		if [ $exit_code -eq $LEAK_CODE ]
		then
			[ $already_printed -eq 0 ] && printf "\r%*s%-*s: [${RED}LEAKS${NC}]\n" $(($level + 1)) "" $((64 - $level)) $basename_file
			already_printed=1
			fails=$(($fails + 1))
		elif [ $exit_code -gt 0 ]
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

while getopts "hl" arg
do
	case $arg in
		h)
			print_usage
			exit 0
			;;
		l)
			NO_LEAK_CHECK=1;;
	esac
done

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
