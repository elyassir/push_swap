NAME = push_swap
SRCS = push_swap_utils.c actions.c actions2.c actions3.c ft_lst.c long_sort.c short_sort.c push_swap.c libft.c libft_2.c long_sort2.c
OBJS		= $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
