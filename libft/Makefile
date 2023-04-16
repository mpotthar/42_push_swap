# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 18:42:35 by mpotthar          #+#    #+#              #
#    Updated: 2023/04/16 13:25:09 by mpotthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcat.c ft_strlcpy.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_split.c ft_printf.c ft_print_nodes.c ft_lstsndlast.c \
		ft_free_dbl_ptr.c ft_atol.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c ft_lstlast.c \
		ft_lstnew.c ft_lstsize.c

OBJS = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}:	${OBJS}
	@ar rcs ${NAME} ${OBJS}

${OBJS}: ${SRC}
	@${CC} ${CFLAGS} -c ${SRC}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY:			all clean fclean re 