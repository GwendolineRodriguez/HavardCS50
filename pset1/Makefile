CFLAGS          +=      -Wextra -Wall -Werror
CFLAGS          +=      -pedantic -ansi

SRC             =       hello.c

OBJ             =       $(SRC:.c=.o)

NAME            =       hello

all:    $(NAME)

$(NAME):	$(OBJ)
			clang $(OBJ) -o $(NAME) -lcs50

clean:
		rm -rf $(OBJ) $(OBJLIB)

fclean: clean
		rm -rf $(LIB)

re:		fclean all
		make re -C
