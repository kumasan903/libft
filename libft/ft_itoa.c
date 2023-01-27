#include "libft.h"

char	*ft_itoa(int n)
{
	char			*return_value;
	size_t			n_len;
	int				i;
	unsigned int	tmp;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		n *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	n_len = 0;
	i = n;
	while (i)
	{
		i /= 10;
		n_len++;
	}
	return_value = ft_calloc(sizeof(char), n_len + 1);
	tmp = 1;
	i = n_len;
	while (i)
	{
		tmp *= 10;
		i--;
	}
	tmp /= 100;
	i = n;
	while (n_len)
	{
		if (i % tmp >= 10)
			return_value[n_len - 1] = ((i % tmp) / (tmp / 10)) + '0';
		else
			return_value[n_len - 1] = (i % tmp) + '0';
		tmp *= 10;
		n_len--;
	}
	if (sign == -1)
	{
		ft_memmove(return_value + 1, return_value, ft_strlen(return_value));
		return_value[n_len] = '-';
	}
	return (return_value);
}

#include <stdio.h>
int	main(void)
{
	printf("return = %s\n", ft_itoa(-123));
}
