NAME	= libft.a
SRCS	= ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memmove.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_putnbr_fd.c ft_split.c ft_strmapi.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
	ar rc $(NAME) $(OBJS)

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
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@$(RM) main.o a.out
