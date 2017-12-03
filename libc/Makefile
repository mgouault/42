SRC		=

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libc.a

all: $(NAME)

$(NAME): $(SRC)
	@ar rc $(NAME) $(SRC)
	@ranlib $(NAME)

$(SRC): %.o: %.c ./libc.h
	@gcc $(CFLAGS) -I ./ -c $< -o $@

clean:
	@rm -f $(SRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
