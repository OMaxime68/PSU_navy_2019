##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=		navy_root.c			\
			navy_init.c			\
			navy_map.c			\
			create_map.c		\
			navy_connection.c	\
			navy_game.c			\
			navy_send.c			\
			navy_interpretor.c	\
			navy_endwin.c		\
			navy_error.c		\
			main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -L ./lib/my/ -lmy -L ./lib/array/ -larray -I ./include/ -pedantic -Wall

NAME	=	navy

all:	$(NAME)

$(NAME): $(OBJ)
	@make -sC ./lib/my/
	@make -sC ./lib/array/
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[01;38;5;10m================Compiling: Done\033[0;0m"

clean:
	@rm -f $(OBJ)
	@make fclean -sC ./lib/my/
	@make fclean -sC ./lib/array/
	@echo "============Deletion *o: Done"

fclean:	clean
	@rm -f $(NAME)
	@echo "============Deletion: Done"

re: fclean all

debug:
	@make -sC ./lib/my/
	@make -sC ./lib/array/
	@gcc -o $(NAME) $(SRC) $(CFLAGS) $(DEBUG) -g
	@echo "============Valgrind compilation: Done"