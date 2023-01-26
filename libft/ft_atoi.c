#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
	}
	return ((int)num);
}
