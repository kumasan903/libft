/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:11:28 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/28 07:11:58 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num_len(int n)
{
	size_t	n_len;

	if (n < 0)
		n *= -1;
	n_len = 1;
	while (n > 9)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	short	sign;
	char	*str;

	sign = 1;
	n_len = count_num_len(n);
	if (n < 0)
	{
		sign *= -1;
		n *= -1;
		n_len ++;
	}
	str = ft_calloc(sizeof(char), n_len + 1);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[n_len - 1] = n % 10 + '0';
		n /= 10;
		n_len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
