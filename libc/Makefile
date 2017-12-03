SRC =
			ft_memcpy.o ft_striteri.o
			ft_atoi.o ft_memdel.o ft_strjoin.o
			ft_bzero.o ft_memmove.o ft_strlcat.o
			ft_char_in_str.o ft_memset.o ft_strlen.o
								ft_char_to_digit.o ft_putchar.o ft_strmap.o
			ft_i_strchr.o ft_putchar_fd.o ft_strmapi.o
			ft_i_strrchr.o ft_putendl.o ft_strmatch.o
			ft_isalnum.o ft_putendl_fd.o ft_strncat.o
			ft_isalpha.o ft_putnbr.o ft_strncmp.o
			ft_isascii.o ft_putnbr_fd.o ft_strncpy.o
			ft_isdigit.o ft_putstr.o ft_strnequ.o
			ft_isprint.o ft_putstr_fd.o ft_strnew.o
			ft_itoa.o ft_str_in_array.o ft_strnstr.o
			ft_lstadd.o ft_strcat.o ft_strrchr.o
			ft_lstdel.o ft_strchr.o ft_strreplace.o
			ft_lstdelone.o ft_strclr.o ft_strsplit.o
			ft_lstiter.o ft_strcmp.o ft_strstr.o
			ft_lstmap.o ft_strcnt.o ft_strsub.o
			ft_lstnew.o ft_strcpy.o ft_strtrim.o
			ft_memalloc.o ft_strdel.o ft_tolower.o
			ft_memccpy.o ft_strdup.o ft_toupper.o
			ft_memchr.o ft_strequ.o libc.h
			ft_memcmp.o ft_striter.o
CFLAGS =	-Wall -Wextra -Werror
NAME =		libc.a

all: $(NAME)

$(NAME): $(SRC)
	@ar rc $(NAME) $(SRC)
	@ranlib $(NAME)

$(SRC): %.o: %.c ../include/libc.h
	@gcc $(CFLAGS) -I ../include/ -c $< -o $@

clean:
	@rm -f $(SRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
