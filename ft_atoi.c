/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:08:19 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/01 07:06:12 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static void	check_head(int *sign, size_t *i, const char *str)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-')
		*sign *= -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long		num;
	const long	long_max_divided = LONG_MAX / 10;
	const long	long_max_remainder = LONG_MAX % 10;

	i = 0;
	sign = 1;
	num = 0;
	check_head(&sign, &i, str);
	while (ft_isdigit(str[i]))
	{
		if (num > (long_max_divided) \
		|| (num == long_max_divided && (str[i] - '0') > (long_max_remainder)))
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			return ((int)LONG_MAX);
		}
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return ((int)(num * sign));
}
