# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 09:51:12 by vfurmane          #+#    #+#              #
#    Updated: 2022/06/02 12:28:12 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(addprefix tests/, \
					$(addprefix integral_constant/, \
					value_type-bool-true-11.cpp value_type-int-42-11.cpp \
					type-bool-true-11.cpp type-int-42-11.cpp \
					value-bool-true-11.cpp value-bool-false-11.cpp \
					value-int-42-11.cpp value_type\(\)-bool-true-11.cpp \
					value_type\(\)-bool-false-11.cpp \
					value_type\(\)-int-42-11.cpp true_type-11.cpp \
					false_type-11.cpp) \
					$(addprefix is_integral/, value_type-int-11.cpp \
					value-double-11.cpp value-bool-11.cpp value-char-11.cpp \
					value-double-11.cpp value-int-11.cpp \
					value-long__int-11.cpp value-long__long__int-11.cpp \
					value-short__int-11.cpp value-signed__char-11.cpp \
					value_type-int-11.cpp value-unsigned__char-11.cpp \
					value-unsigned__int-11.cpp \
					value-unsigned__long__int-11.cpp \
					value-unsigned__long__long__int-11.cpp \
					value-unsigned__short__int-11.cpp value-wchar_t-11.cpp \
					value_type\(\)-double-11.cpp value_type\(\)-bool-11.cpp \
					value_type\(\)-int-11.cpp))
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

clean:
				$(RM) $(addsuffix _ft.dep, $(TESTS)) $(addsuffix _std.dep, $(TESTS))
				$(RM) $(addsuffix _ft.o, $(TESTS)) $(addsuffix _std.o, $(TESTS))

fclean:			clean
				$(RM) $(addsuffix _ft, $(TESTS)) $(addsuffix _std, $(TESTS))

-include		$(addsuffix _ft.dep, $(TESTS)) $(addsuffix _std.dep, $(TESTS))

.PHONY:			clean
.PRECIOUS:		%_$(n).o %.dep
