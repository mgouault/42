AUX =		aux/ft_printf.o aux/ft_bigjoin.o
SRC =		src/ft_minishell1.o src/get.o src/path.o src/env.o src/builtins.o \
			src/builtins_.o src/aux.o src/aux_.o src/aux__.o src/free.o \
			src/cmd.o src/cmd_.o src/cd.o src/cd_.o src/cd__.o src/cd_opt.o \
			src/error.o src/singletons.o src/singletons_.o src/signal.o \
			src/ft_termcaps.o src/parser_1.o src/parser_2.o src/parser_3.o \
			src/parser_4.o src/parser_5.o $(AUX)
LIB_F =		libc
LIB =		$(LIB_F)/$(LIB_F).a
CFLAGS =	-Wall -Wextra -Werror
NAME =		ft_minishell1

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIB) -I include/ -ltermcap
	@echo 'make'

$(LIB):
	@make -C $(LIB_F)/

$(SRC): %.o: %.c include/ft_minishell1.h
	@gcc $(CFLAGS) -I include/ -c $< -o $@

clean:
	@rm -f $(SRC)
	@make -C $(LIB_F)/ clean
	@echo 'clean'

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_F)/ fclean
	@echo 'fclean'

re: fclean all

.PHONY: all clean fclean re
