# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 09:51:12 by vfurmane          #+#    #+#              #
#    Updated: 2022/03/11 12:39:50 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= containers
SRCS			= test.cpp
CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98

all:			std_$(NAME) ft_$(NAME)

ft_$(NAME):		$(SRCS)
				$(CC) $(CFLAGS) -D USE_STD=0 $^ -o ft_$(NAME)

std_$(NAME):	$(SRCS)
				$(CC) $(CFLAGS) -D USE_STD=1 $^ -o std_$(NAME)

test: 			SHELL:=/bin/bash
test:			all
				diff -y --width=80 <(./ft_$(NAME)) <(./std_$(NAME))

leak_test:		SHELL:=/bin/bash
leak_test:		all
				diff -y --width=80 <(valgrind ./ft_$(NAME)) <(./std_$(NAME))

fclean:
				$(RM) ft_$(NAME) std_$(NAME)

re: 			fclean all

.PHONY:			all test fclean re
