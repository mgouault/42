SRC =		ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
			ft_isdigit.o ft_isprint.o ft_itoa.o	ft_memalloc.o ft_memdel.o \
			ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
			ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strchr.o \
			ft_strcmp.o ft_strdup.o ft_strequ.o ft_strjoin.o ft_strlen.o \
			ft_strncmp.o ft_strnequ.o ft_strnstr.o ft_strrchr.o ft_strsplit.o \
			ft_strstr.o ft_strsub.o ft_strtrim.o ft_strcnt.o ft_strmatch.o \
			ft_strreplace.o ft_gnl.o ft_printf.o ft_strlen_uc.o ft_strsub_uc.o \
			ft_strjoin_uc.o ft_free_bistr.o ft_strsplit_uc.o ft_strcnt_uc.o \
			ft_isspace.o ft_isspace_str.o
CFLAGS =	-Wall -Wextra -Werror
NAME =		libc.a

all: $(NAME)

$(NAME): $(SRC)
	@ar rc $(NAME) $(SRC)
	@ranlib $(NAME)

$(SRC): %.o: %.c ../includes/libc.h
	@gcc $(CFLAGS) -I ../includes/ -c $< -o $@

clean:
	@rm -f $(SRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
