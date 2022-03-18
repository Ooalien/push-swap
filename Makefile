# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 12:58:10 by abayar            #+#    #+#              #
#    Updated: 2022/03/18 20:41:10 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error.c ft_lst_utils.c sorting.c sorting_utils2.c ft_atoi.c moves.c sorting_numbers.c sorting_utils3.c ft_lst.c  moves_utils.c   sorting_utils.c  push_swap.c

SRCB = ft_atoi.c ft_lst_utils.c ft_lst.c check_error.c checker/checker.c checker/get_next_line.c checker/get_next_line_utils.c checker/move_checker.c checker/move_checker_utils.c

OBJB = ${SRCB:.c=.o}

OBJ = ${SRC:.c=.o}

NAME = push_swap.a

NAMEB = checker.a

FLAGS = gcc -Wall -Wextra -Werror -g

all		: ${NAME}

bonus	: ${NAMEB}

${NAME}	: ${OBJ}

%.o		: %.c
	${FLAGS} -c $< -o $@
	ar rc ${NAME} $@

${NAMEB} :
	${FLAGS} ${SRCB}

exec	:
	${FLAGS} ${NAME} ${SRC} -o push_swap

clean	:
	rm -f ${OBJ}

fclean	: clean
	rm -f ${NAME}

re		: fclean all