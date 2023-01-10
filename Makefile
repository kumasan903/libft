NAME	= a.out
SRCS	= main.c ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
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
rerun	:	re run
