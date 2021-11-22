NAME = libftprintf.a
SRC_FILES = source/ft_printf.c\
	source/ft_buff.c\
	source/ft_read_fmt.c\
	source/ft_arg.c\
	source/specifiers/ft_sprintf_c.c\
	source/specifiers/ft_sprintf_s.c\
	source/specifiers/ft_sprintf_p.c\
	source/specifiers/ft_sprintf_i.c\
	source/specifiers/ft_sprintf_u.c\
	source/specifiers/ft_sprintf_x.c
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $(C_FLAGS) $< -o $@

$(NAME): $(OBJ_FILES)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_FILES)

norme:
	make -C libft norme
	@norminette $(SRC_FILES)
	@norminette ft_printf.h

tests: $(NAME)
	@$(CC) $(C_FLAGS) tests.c $(NAME) -o tests
	@./tests
	@rm -f tests

clean:
	make -C libft clean
	rm -f $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
	make -C libft re

.PHONY: all norme clean fclean re
