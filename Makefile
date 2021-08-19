# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2021/08/12 20:49:59 by ccouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

CC = @gcc

CFLAGS = -g -Wall -Wextra -Werror

SRCS_CLIENT =	srcs/client.c srcs/minitalk_utils.c

SRCS_SERVER =	srcs/server.c srcs/minitalk_utils.c

_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m

OBJS_C = $(SRCS_CLIENT:.c=.o)

OBJS_S = $(SRCS_SERVER:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_C)
		@echo "$(_YELLOW)[Compilation on going ...]"
		@echo "$(_GREEN)[Compilation done]"
		$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME1)
		@echo "$(_CYAN)[Executable created]"
		@echo [Name : client]

$(NAME2): $(OBJS_S)
		@echo "$(_YELLOW)[Compilation on going ...]"
		@echo "$(_GREEN)[Compilation done]"
		$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME2)
		@echo "$(_CYAN)[Executable created]"
		@echo [Name : server]

%o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS_S) $(OBJS_C)
	@echo "$(_RED)[All .o removed]"

fclean: clean
	@rm -f $(NAME1) $(NAME2)
	@echo "$(_RED)[Executable(s) removed]"

re: fclean all

.PHONY : all bonus clean fclean re
