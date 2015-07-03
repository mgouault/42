SRC =		src/game_2048.o src/print.o src/calc.o src/moves.o src/random.o \
			src/merge.o src/exit.o src/free.o src/aux.o
CFLAGS =	-Wall -Wextra -Werror
NAME =		game_2048
LIB = 		libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIB) -I include/ -lcurses
	@echo 'make'

$(LIB):
	@make -C libft/

$(SRC): %.o: %.c include/game_2048.h
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
