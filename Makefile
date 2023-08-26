NAME = libft.a

# Names
SRC_NAME = 	$(wildcard src/*.c)
OBJ_NAME = $(SRC_NAME:.c=.o)

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

$(NAME): $(OBJ_NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
	@echo "library created successfully"

%.o: %.c
	@$(CC) -o $@ -c $<
	@echo "compiled" $<

clean:
	@rm -rf $(OBJ_NAME) 2> /dev/null || true
	@echo "deleted object files"

fclean: clean
	@rm -f $(NAME)
	@echo "deleted library"

re: fclean all

.PHONY: all, clean, fclean, re
