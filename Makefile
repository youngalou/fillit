# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 11:49:51 by lyoung            #+#    #+#              #
#    Updated: 2017/04/14 12:32:54 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I libft/

SRC = fix_map.c \
	validate.c \
	create_map.c \
	main.c \
	solve.c \
	square.c \

OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "\033[32m- fillit object file created\033[0m"

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m- fillit executable compiled\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m- fillit object files removed\033[0m"

fclean: clean 
	@rm -rf $(NAME)
	@echo "\033[31m- fillit executable removed\033[0m"
	@make -C libft fclean

re: fclean all
