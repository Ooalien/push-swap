# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:58:10 by abayar            #+#    #+#              #
#    Updated: 2022/03/19 20:59:33 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c ft_lst_utils.c sorting.c sorting_utils2.c ft_atoi.c moves.c sorting_numbers.c sorting_utils3.c ft_lst.c  moves_utils.c   sorting_utils.c  push_swap.c

SRCB = checkerfile/checker.c checkerfile/get_next_line.c checkerfile/get_next_line_utils.c checkerfile/move_checker.c checkerfile/move_checker_utils.c

OBJB = ${SRCB:.c=.o}

OBJ = ${SRC:.c=.o}

NAME = push_swap.a

NAMEB = checker.a

FLAGS = gcc -Wall -Wextra -Werror -g

all		: ${NAME}

bonus	: ${NAMEB}

${NAME}	: ${OBJ}

${NAMEB} : ${OBJB}

%.o		: %.c
	${FLAGS} -c $< -o $@
	ar rc ${NAME} $@

exec	:
	${FLAGS} ${NAME} ${SRC} -o push_swap

execb	:
	${FLAGS} ${NAME} ${SRCB} -o checker

clean	:
	rm -f ${OBJ}
	rm -f ${OBJB}

fclean	: clean
	rm -f ${NAME}
	rm -f ${NAMEB}

re		: fclean all