NAME		=	push_swap
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS		=	$(wildcard src/*.c)
OBJS		=	$(SRCS:.c=.o)

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
INCLUDES	=	-I include -I $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

%.o: %.c include/stack.h
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
		@make -C $(LIBFT_DIR) clean
		$(RM) $(OBJS)

fclean:		clean
		@make -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

re:		fclean all

bonus:		all

.PHONY:		all clean fclean re bonus
