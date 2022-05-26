# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 09:51:12 by vfurmane          #+#    #+#              #
#    Updated: 2022/05/26 16:00:51 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= containers
SRCS			= $(addprefix tests/, $(addprefix integral_constant/, value_type-bool-true-11.cpp))
TESTS			= $(SRCS:.cpp=)
CC				= c++
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

n				= std
cpp				= 98

%:				CFLAGS+=--std=c++$(cpp)
%:				%.cpp
				$(CC) $(CFLAGS) -I. -D NAMESPACE=$(n) $^ -o $@_$(n)

clean:
				$(RM) $(TESTS)

.PHONY:			clean
