# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 18:53:32 by mgouault          #+#    #+#              #
#    Updated: 2014/12/27 15:43:33 by mgouault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		ft_create_lst.c ft_print_lst.c ft_print_lst_l.c ft_sort_lst.c ft_ls.c \
		ft_free_lst.c ft_error.c ft_init.c ft_acl.c ft_tools.c ft_queue.c \
		ft_pre_calc.c ft_print_lst_l_.c
OBJ =		$(SRC:.c=.o)
CFLAGS =	-Wall -Wextra -Werror
NAME =		ft_ls

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC) -I libft/
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo 'make'

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo 'clean'

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo 'fclean'

re: fclean all

.PHONY: all clean fclean re $(NAME)
