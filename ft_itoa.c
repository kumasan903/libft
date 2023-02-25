/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:11:28 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/02 00:12:05 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num_len(long n)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		n_len ++;
	}
	while (n > 0)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	long	long_n;
	size_t	n_len;
	char	*str;

	long_n = n;
	n_len = count_num_len(long_n);
	str = ft_calloc(sizeof(char), n_len + 1);
	if (str == NULL)
		return (NULL);
	if (long_n < 0)
	{
		long_n *= -1;
		str[0] = '-';
	}
	if (long_n == 0)
		str[0] = '0';
	while (long_n)
	{
		str[n_len - 1] = long_n % 10 + '0';
		long_n /= 10;
		n_len--;
	}
	return (str);
}
