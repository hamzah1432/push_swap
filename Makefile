NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INC_DIR = include
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
HEADER = $(INC_DIR)/stack.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_PATH) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
