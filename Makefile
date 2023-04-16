NAME			= push_swap
				
LIBFT			= libft

SRCDIR			= src

SRCS			= ${addprefix ${SRCDIR}/, main.c \
				  backward.c \
				  checks.c \
				  forward.c \
				  input.c \
				  operations.c \
				  utils_forward.c}

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

# Colors
GREEN			= \033[92m
YELLOW			= \033[0;33m
MAGENTA			= \033[0;35m
ESCAPE			= \033[0m

all:			lib ${NAME}

%.o: %.c		
				@${CC} ${CFLAGS} -c $^ -o $@

${NAME}:		start ${OBJS} ${LIBFT}/libft.a
				@${CC} ${CFLAGS} ${OBJS} -L ${LIBFT} -lft -o ${NAME}
				@echo "${GREEN}******************   COMPILED  ******************${ESCAPE}"
				@echo "${MAGENTA}******************     DONE    ******************${ESCAPE}"
				@echo " "

lib:
				@make -C ${LIBFT} > /dev/null 2>&1	

start:			
				@echo " "
				@echo "-------------------------------------------------"
				@echo "${MAGENTA}******************  PUSH_SWAP  ******************${ESCAPE}"
				@echo "-------------------------------------------------"
				@echo " "
				@echo "${YELLOW}******************  COMPILING  ******************${ESCAPE}"

clean:	
				@${RM} ${OBJS}
				@make clean -C ${LIBFT} > /dev/null 2>&1
				@echo "${GREEN}*******************  CLEANED  *******************${ESCAPE}"

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C ${LIBFT}

re:				fclean all

.PHONY:			all start clean fclean re