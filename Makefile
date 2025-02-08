# Variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)       # Automatically includes all .c files in the directory
OBJ = $(SRC:.c=.o)          # Object files generated from source files

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

compile: $(NAME)
	@./push_swap
	@$(MAKE) fclean > /dev/null  # Hide the output of fclean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
