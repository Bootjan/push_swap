SRCS_UTILS = init_stack.c stack_utils.c error_checking.c error_checking_utils.c
SRCS_OPERATORS = push_swap.c rotate.c
SRCS_SORT = sort_for_three.c sort_for_four.c sort_for_five.c push_to_b.c\
push_to_a.c chunk_info.c first_second_max.c
MAIN = main.c

SRCS = ${SRCS_OPERATORS}\
${SRCS_UTILS}\
${SRCS_SORT}\
${MAIN}
OBJS = ${SRCS:%.c=${OBJS_DIR}/%.o}

NAME = push_swap
VPATH = ./utils ./operators ./sort
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
	${RM} ${OBJS_DIR}/*

fclean: clean
	${RM} ${NAME}
	make -C ${MAKE_DIR} fclean

re: fclean all

.PHONY: all re fclean clean