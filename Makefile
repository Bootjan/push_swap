SRCS_UTILS = init_stack.c linked_list.c error_checking.c index_rank_arr.c
SRCS_OPERATORS = push_swap.c rotate.c
MAIN = main.c

SRCS = ${SRCS_OPERATORS}\
${SRCS_UTILS}\
${MAIN}\
helpers.c
OBJS = ${SRCS:%.c=${OBJS_DIR}/%.o}

NAME = push_swap
VPATH = ./utils ./operators
OBJS_DIR = ./objs

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
INCLUDES = -I./includes
RM = rm -f

MAKE_DIR = ./libft
MAKE_LIB = ${MAKE_DIR}/libftprintf.a
LIB = -L./libft -lftprintf

all: ${NAME}

${NAME}: ${MAKE_LIB} ${OBJS_DIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

${MAKE_LIB}:
	make -C ${MAKE_DIR} all

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}/%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:	
	make -C ${MAKE_DIR} clean

fclean: clean
	${RM} ${NAME}
	make -C ${MAKE_DIR} fclean

re: fclean all

.PHONY: all re fclean clean