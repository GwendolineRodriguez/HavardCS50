SRC             =       whodunit.c

OBJ             =       $(SRC:.c=.o)

NAME            =       whodunit

all:    $(NAME)

$(NAME):	$(OBJ)
			clang $(OBJ) -o $(NAME) -lcs50

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:		fclean all
		make re -C
