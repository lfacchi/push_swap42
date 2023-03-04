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
SRCS	= main.c push_swap.c \
		push.c  rev-rotate.c  rotate.c swap.c \
		three_args.c five_args.c radix.c\
		helper.c validation.c utils.c
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}
	@clear
	
t:all
	./teste.sh
	
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
	rm -f valgrind_check/*
	rm -rf ${OBJSDIR}

fclean: clean
	rm -f ${NAME}

re: fclean all
