SRC =			srcs/aux.o srcs/tools.o
SRC_SERVER =	srcs/server.o srcs/server_func_1.o srcs/server_func_2.o \
				srcs/server_func_3.o
SRC_CLIENT =	srcs/client.o srcs/client_func_1.o srcs/client_func_2.o
LIB_F =			libc
LIB =			$(LIB_F)/$(LIB_F).a
CFLAGS =		-Wall -Wextra -Werror
SERVER =		serveur
CLIENT =		client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERVER) $(SRC) $(LIB) includes/ft_p.h
	@gcc $(CFLAGS) -o $(SERVER) $(SRC_SERVER) $(SRC) $(LIB) -I includes/
	@echo 'make serveur'

$(CLIENT): $(SRC_CLIENT) $(SRC) $(LIB) includes/ft_p.h
	@gcc $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT) $(SRC) $(LIB) -I includes/
	@echo 'make client'

$(LIB):
	@make -C $(LIB_F)/

$(SRC_SERVER): %.o: %.c includes/ft_p.h
	@gcc $(CFLAGS) -I includes/ -c $< -o $@

$(SRC_CLIENT): %.o: %.c includes/ft_p.h
	@gcc $(CFLAGS) -I includes/ -c $< -o $@

$(SRC): %.o: %.c includes/ft_p.h
	@gcc $(CFLAGS) -I includes/ -c $< -o $@

clean:
	@rm -f $(SRC_SERVER)
	@rm -f $(SRC_CLIENT)
	@rm -f $(SRC)
	@make -C $(LIB_F)/ clean
	@echo 'clean'

fclean: clean
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@make -C $(LIB_F)/ fclean
	@echo 'fclean'

re: fclean all

.PHONY: all clean fclean re
