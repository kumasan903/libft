NAME	= libft.a
SRCS	= ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memmove.c ft_strlcat.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean	:
	$(RM) $(OBJS)
	$(RM) main.o

fclean	:	clean
	$(RM) $(NAME)
	$(RM) a.out

re		:	fclean all

all		:	$(NAME)

test	:	$(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.o -o a.out

run		:	test
	./a.out
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(RM) main.o a.out
