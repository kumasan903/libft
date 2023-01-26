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
	long	tmp;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	tmp = str[i] - '0';
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		if (num < tmp)
		{
//			if (sign == -1 && num - 1 == LONG_MAX)
//			{
//				return ((int)LONG_MIN);
//			}
			if (sign == -1)
				return ((int)LONG_MIN);
			num = LONG_MAX;
			break ;
		}
		tmp = num;
		i++;
	}
	return ((int)(num * sign));
}
