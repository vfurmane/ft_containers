# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 09:51:12 by vfurmane          #+#    #+#              #
#    Updated: 2022/06/07 14:50:40 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard tests/**/*.cpp)
DEPS			= $(SRCS:.cpp=.dep)
OBJS			= $(SRCS:.cpp=.o)
TESTS			= $(OBJS:.o=)
CC				= c++
CFLAGS			+= -Wall -Wextra -Werror
RM				= rm -f

n				= std
cpp				= 98

ifeq ($(n),std)
	CFLAGS+=-D USE_STD
endif

%_$(n).dep:		%.cpp
				$(CC) $(CFLAGS) -I. -D NAMESPACE=$(n) -MM -MQ '$(patsubst %.cpp,%_$(n).o,$<)' -MF '$@' '$<'

%_$(n).o:		CFLAGS+=--std=c++$(cpp)
%_$(n).o:		%.cpp %_$(n).dep
				$(CC) $(CFLAGS) -I. -D NAMESPACE=$(n) -c '$<' -o '$@'

%_$(n):			%_$(n).o
				$(CC) -I. -D NAMESPACE=$(n) '$<' -o '$@'

%.o:			%.cpp
				@echo "No namespace given in rule name"
				@exit 1

%:				%.cpp
				@echo "No namespace given in rule name"
				@exit 1

sources_$(n).dep:	$(addsuffix _$(n).dep, $(TESTS))
				cat $(patsubst %,'%',$(addsuffix _$(n).dep, $(TESTS))) > $@

clean:
				$(RM) $(patsubst %,'%',$(addsuffix _ft.dep, $(TESTS))) $(patsubst %,'%',$(addsuffix _std.dep, $(TESTS)))
				$(RM) sources.dep
				$(RM) $(patsubst %,'%',$(addsuffix _ft.o, $(TESTS))) $(patsubst %,'%',$(addsuffix _std.o, $(TESTS)))

fclean:			clean
				$(RM) $(patsubst %,'%',$(addsuffix _ft, $(TESTS))) $(patsubst %,'%',$(addsuffix _std, $(TESTS)))

#-include		$(patsubst %,'%',$(addsuffix _ft.dep, $(TESTS))) $(patsubst %,'%',$(addsuffix _std.dep, $(TESTS)))
-include		sources_$(n).dep

.PHONY:			clean fclean
.PRECIOUS:		%_$(n).o %_$(n).dep
