CFLAGS          +=      -Wextra -Wall -Werror
CFLAGS          +=      -pedantic -ansi

SRC             =       hello.c

OBJ             =       $(SRC:.c=.o)

NAME            =       hello

all:    $(NAME)

$(NAME):	$(OBJ)
			cc $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ) $(OBJLIB)

fclean: clean
		rm -rf $(LIB)

re:		fclean all
		make re -C
