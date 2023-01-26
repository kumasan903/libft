/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:08:19 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/26 22:29:15 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

void	check_head(int *sign, size_t *i, const char *str)
{
	while (ft_isspace(str[*i]))
		*i += 1;
	if (str[*i] == '-')
		*sign *= -1;
	if (str[*i] == '-' || str[*i] == '+')
		*i += 1;
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
	check_head(&sign, &i, str);
	tmp = str[i] - '0';
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - '0';
		if (num < tmp)
		{
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

#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n%d\n", ft_atoi(" \t"), atoi(" \t"));
}
