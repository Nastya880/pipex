# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:25:11 by tandroma          #+#    #+#              #
#    Updated: 2022/03/05 14:02:03 by tandroma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=  main.c utils.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c ft_split.c work_path_cmd.c processes.c

OBJS		= ${SRCS:c=o}

NAME		= pipex

FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

HEAD		= pipex.h

.PHONY:		all clean fclean re

all:		${NAME}

${NAME}:	${OBJS} ${HEAD} Makefile
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o:		%.c ${HEAD}
			${CC} ${FLAGS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all