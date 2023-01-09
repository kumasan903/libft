NAME	= a.out
SRCS	= main.c ft_strlen.c ft_memcpy.c ft_strlcpy.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAG	= -Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

all		:	$(NAME)

run		:	$(NAME)
	./$(NAME)
