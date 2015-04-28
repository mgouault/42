SRC =		src/main.o src/tools.o src/exit.o src/singletons.o \
			src/print.o src/lst.o src/read.o src/signals.o
CFLAGS =	-Wall -Wextra -Werror
NAME =		ft_select
LIB = 		libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	@gcc -g $(CFLAGS) -o $(NAME) $(SRC) $(LIB) -I include/ -ltermcap
	@echo 'make'

$(LIB):
	@make -C libft/

$(SRC): %.o: %.c include/ft_select.h
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
