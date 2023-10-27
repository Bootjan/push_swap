SRCS_UTILS = init_stack.c linked_list.c
UTILS_DIR = ./utils
UTILS = ${SRCS_UTILS:%=${UTILS_DIR}/%}

SRCS_OPERATORS = push_swap.c
OPERATORS_DIR = ./operators
OPERATORS = ${SRCS_OPERATORS:%=${OPERATORS_DIR}/%}

MAIN = main.c
NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MAKE_DIR = ./libft
MAKE_LIB = ${MAKE_DIR}/libftprintf.a

all: ${NAME}

${NAME}: ${MAKE_LIB}
	${CC} ${CFLAGS} ${UTILS} ${OPERATORS} ${MAIN} -o ${NAME} ${MAKE_LIB} -g

${MAKE_LIB}:
	make -C ${MAKE_DIR} all

clean:	
	make -C ${MAKE_DIR} clean

fclean: clean
	${RM} ${NAME}
	make -C ${MAKE_DIR} fclean

re: fclean all

.PHONY: all re fclean clean