NAME = libftprintf.a
SRC = ft_printf.c handle_ap_funcs.c handle_ap_utils.c
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
