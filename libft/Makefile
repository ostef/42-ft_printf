NAME = libft.a
SRC_FILES = source/alloc.c\
	source/debug.c\
	source/sign.c source/min_max.c source/clamp.c source/ieee754.c source/round.c\
	source/memchr.c source/memcmp.c source/memcpy.c source/memset.c\
	source/letter.c source/char.c\
	source/strchr.c source/strcmp.c source/strcpy.c source/strdup.c source/strstr.c\
	source/str_to_number.c\
	source/putchar.c source/putstr.c source/putnbr.c
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

norme:
	@norminette $(SRC_FILES)
	@norminette libft.h

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all norme clean fclean re
