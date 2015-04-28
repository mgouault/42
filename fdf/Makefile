SRC =		fdf.o ft_split.o ft_print.o ft_aux.o get_next_line.o
CFLAGS =	-Wall -Werror -Wextra
NAME =		fdf

all: $(NAME)

$(NAME): $(SRC) libft/libft.a
	@gcc $(CFLAGS) -o $(NAME) $(SRC) -L libft/ -lft -L /usr/X11/lib -lmlx -lXext -lX11
	@echo 'make'

libft/libft.a:
	@make -C libft/

$(SRC): %.o: %.c fdf.h
	@gcc $(CFLAGS) -I libft/ -c $< -o $@

clean:
	@rm -f $(SRC)
	@make -C libft/ clean
	@echo 'clean'

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo 'fclean'

re: fclean all

.PHONY: all clean fclean re
