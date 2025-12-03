NAME = libftprintf.a
SRC = ft_ap_funcs.c ft_ap_funcs2.c ft_itoa.c ft_printf.c ft_utoa.c
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
