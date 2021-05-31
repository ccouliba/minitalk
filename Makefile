
NAME = client

NAME2 = server

#FLAGS = -Wall -Wextra -Werror

SRCS_SERVER  =	server.c \
		utils.c

SRCS_CLIENT = client.c

OBJS_S = ${SRCS_SERVER:.c=.o}

OBJS_C = ${SRCS_CLIENT:.c=.o}

all: ${NAME} ${NAME2}

${NAME}: ${OBJS_C}
	make -C libft
	gcc ${SRCS_CLIENT} -o ${NAME} libft/libft.a
	#gcc $(FLAGS) $(SRCS_CLIENT) -o $(NAME) libft/libft.a

${NAME2}: ${OBJS_S}
	gcc ${SRCS_SERVER} -o ${NAME2} libft/libft.a
	#gcc $(FLAGS) $(SRCS_SERVER) -o $(NAME2) libft/libft.a

%.o: %.c
	gcc -c $< -o $@
	#gcc $(FLAGS) -c $< -o $@

clean:
	rm -f ${OBJS_S}
	rm -f ${OBJS_C}

fclean: clean
	make fclean -C libft/
	rm -f ${NAME}
	rm -f ${NAME2}

re: fclean all

.PHONY: all clean fclean re
