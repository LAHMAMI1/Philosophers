# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 10:18:14 by olahmami          #+#    #+#              #
#    Updated: 2023/09/08 16:45:39 by olahmami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

done = \033[0m
Red	= \033[0;31m
Green = \033[0;32m

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread
# CFLAGS += -g3 -fsanitize=thread

SRCS = philo.c \
	   check_int.c \
	   init.c \
	   utils.c \
	   to_do.c \

OBJS = $(SRCS:.c=.o)

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\r$ $(Green) Created philo! $(done)"

clean:
	@rm -rf $(OBJS)
	@echo "\r$ $(Red) Cleaning! $(done)"
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
