NAME = fillit

CGLAGS = -Wall -Wextra -Werror

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

$(NAME): $(OBJ)
	@gcc $(OBJ) libft.a -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean 
	@rm $(NAME)

re: fclean all