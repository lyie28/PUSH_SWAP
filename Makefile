# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 17:26:49 by lyie              #+#    #+#              #
#    Updated: 2021/05/18 12:07:26 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SRCS			=	src/push_main.c \
					src/ft_atoi.c \
					src/list_tools.c \
					src/list_tools_extra.c \
					src/list_tools_more.c \
					src/big_sort.c \
					src/new_functions.c \
					src/big_sort_tools.c \
					src/big_sort_tools_extra.c \
					src/tools_in_common.c \
					src/get_next_line.c \
					src/get_next_line_utils.c \
					src/checker_commands.c \
					src/frees.c \
					src/sort_functions.c

CHECK_SRCS			= 	src/checker_main.c \
					src/checker_tools.c \
					src/checker_commands.c \
					src/ft_atoi.c \
					src/ft_strncmp.c \
					src/get_next_line.c \
					src/list_tools.c \
					src/list_tools_extra.c \
					src/list_tools_more.c \
					src/tools_in_common.c \
					src/get_next_line_utils.c

PUSH_OBJS			= $(PUSH_SRCS:.c=.o)
CHECK_OBJS			= $(CHECK_SRCS:.c=.o)

CC				= gcc -D BUFFER_SIZE=1 -g -fsanitize=address
RM				= rm -f
INCLUDE			= -I./includes/
CFLAGS			= -Wall -Werror -Wextra

PUSH_NAME			= push_swap
CHECK_NAME			= checker

all:			$(PUSH_NAME) $(CHECK_NAME)

%.o: %.c
				${CC} -c ${CFLAGS} ${INCLUDE} $< -o $@

$(PUSH_NAME):		$(PUSH_OBJS)
				${CC} $(PUSH_OBJS) ${INCLUDE} ${CFLAGS} ${LIBS} -o $(PUSH_NAME)

$(CHECK_NAME):		$(CHECK_OBJS)
				${CC} $(CHECK_OBJS) ${INCLUDE} ${CFLAGS} ${LIBS} -o $(CHECK_NAME)

clean:
				$(RM) ${PUSH_OBJS}
				$(RM) ${CHECK_OBJS}

fclean:			clean
				$(RM) $(PUSH_NAME)
				$(RM) $(CHECK_NAME)

%:
		@:

re:				fclean all

.PHONY:			all clean fclean re bonus
