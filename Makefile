NAME = libftprintf.a
SRC_FILES = source/ft_print.c\
	source/ft_fprint.c\
	source/ft_sprint.c\
	source/ft_buff.c\
	source/ft_read_fmt.c\
	source/ft_arg.c\
	source/specifiers/ft_sprint_c.c\
	source/specifiers/ft_sprint_s.c\
	source/specifiers/ft_sprint_p.c\
	source/specifiers/ft_sprint_i.c\
	source/specifiers/ft_sprint_u.c\
	source/specifiers/ft_sprint_x.c\
	source/specifiers/ft_sprint_b.c\
	source/specifiers/ft_sprint_n.c
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

%.o: %.c ft_print.h
	$(CC) -c $(C_FLAGS) $< -o $@

$(NAME): $(OBJ_FILES)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_FILES)

norme:
	make -C libft norme
	@norminette $(SRC_FILES)
	@norminette ft_print.h

tests: $(NAME) tests.c
	$(CC) $(C_FLAGS) tests.c $(NAME) -o tests
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
