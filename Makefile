# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:03:20 by ccouliba          #+#    #+#              #
#    Updated: 2021/09/30 03:32:47 by ccouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

CC = @gcc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

# Ansi colors
_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_U_BLUE=$'\033[4;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m
_END=	$'\033[0;m

SRCS_CLIENT =	srcs/client.c srcs/minitalk_utils.c \
				srcs/minitalk_color_utils.c srcs/minitalk_utils2.c

SRCS_SERVER =	srcs/server.c srcs/minitalk_utils.c \
				srcs/minitalk_color_utils.c srcs/minitalk_utils2.c

OBJS_C = $(SRCS_CLIENT:.c=.o)

OBJS_S = $(SRCS_SERVER:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_C)
		$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME1)
		@echo "$(_GREEN)[Compilation done]$(_END)"
		@echo "$(_CYAN)[Name of the a.out file: $(_U_BLUE)$(NAME1)$(_END)]"

$(NAME2): $(OBJS_S)
		$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME2)
		@echo "$(_GREEN)[Compilation done]$(_END)"
		@echo "$(_CYAN)[Name of the a.out file : $(_U_BLUE)$(NAME2)$(_END)]"

%o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS_S) $(OBJS_C)
	@echo "$(_RED)[All .o removed]$(_END)"

fclean: clean
	@rm -f $(NAME1) $(NAME2)
	@echo "$(_RED)[Executable(s) removed]$(_END)"

re: fclean all

.PHONY : all bonus clean fclean re
