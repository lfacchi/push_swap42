# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:18:26 by lucdos-s          #+#    #+#              #
#    Updated: 2022/11/29 16:18:26 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FT		= ./42_libft/libft.a
NUM		= 5
SRCS	= main.c push_swap.c moves.c moves2.c utils.c tree_args.c five_args.c
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}
	@clear
	@shuf -i 1-$(NUM) -n $(NUM) | xargs ./push_swap
	

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${FT} -o $@
	

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${FT}

${OBJSDIR}/%.o: src/%.c src/push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

${FT}: 
	@${MAKE} -C 42_libft

clean:
	${MAKE} clean -C 42_libft
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf 42_libft
	rm -f ${NAME}

re: fclean all