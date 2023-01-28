#include "libft.h"

static int	check_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		n *= -1;
	}
	return (sign);
}

static int	count_num_len(int n)
{
	int	n_len;

	n_len = 0;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

static int	calc_div(int n_len)
{
	int	div;

	div = 1;
	while (n_len)
	{
		div *= 10;
		n_len--;
	}
	div /= 100;
	return (div);
}

static char *make_return_value(char *return_value, int sign, int n_len)
{
	if (sign == -1)
	{
		ft_memmove(return_value + 1, return_value, ft_strlen(return_value));
		return_value[n_len] = '-';
	}
	return (return_value);
}

char	*ft_itoa(int n)
{
	char			*return_value;
	size_t			n_len;
	int				i;
	unsigned int	div;
	int				sign;

	if (n == 0)
		return (ft_strdup("0"));
	sign = check_sign(n);
	n_len = count_num_len(n);
	return_value = ft_calloc(sizeof(char), n_len + 1);
	if (return_value == NULL)
		return (NULL);
	div = calc_div(n_len);
	i = n;
	while (n_len)
	{
		if (i % div >= 10)
			return_value[n_len - 1] = ((i % div) / (div / 10)) + '0';
		else
			return_value[n_len - 1] = (i % div) + '0';
		div *= 10;
		n_len--;
	}
	return (make_return_value(return_value, sign, n_len));
}

#include <stdio.h>
int	main(void)
{
	printf("return = %s\n", ft_itoa(1234));
	printf("return = %s\n", ft_itoa(-1234));
	printf("return = %s\n", ft_itoa(0));
}
