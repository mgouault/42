SRC =		src/fractol.o src/draw.o src/fractals.o src/hook_1.o src/hook_2.o
CFLAGS =	-Wall -Wextra -Werror
NAME =		fractol
LIB = 		libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIB) -I include/ \
	-L /usr/X11/lib -lmlx -lXext -lX11
	@echo 'make'

$(LIB):
	@make -C libft/

$(SRC): %.o: %.c include/fractol.h
	@gcc $(CFLAGS) -I include/ -c $< -o $@

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
