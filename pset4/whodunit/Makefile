SRC             =       copy.c

OBJ             =       $(SRC:.c=.o)

NAME            =       copy

all:    $(NAME)

$(NAME):	$(OBJ)
			clang $(OBJ) -o $(NAME) -lcs50

clean:
		rm -rf $(OBJ) $(OBJLIB)

fclean: clean
		rm -rf $(LIB)

re:		fclean all
		make re -C
