NAME = libftprintf.a
SRC_FILES = ft_printf.c
OBJ_FILES = $(SRC_FILES:.c=.o)
C_FLAGS = -Wall -Wextra -Werror
CC = clang

.c.o:
	$(CC) -c $(C_FLAGS) $< -o $(<:.c=.o)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

tests: $(NAME)
	$(CC) $(C_FLAGS) tests.c $(NAME) -o tests

all: $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) tests all clean fclean re
