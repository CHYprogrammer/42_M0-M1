NAME = libftprintf.a
SRC = 
OBJ = $(SRC:.c=.o)
CCW = cc -Wall -Werror -Wextra
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ):
	$(CCW) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
