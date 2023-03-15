/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:31:38 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/17 17:47:01 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uchar_s1 = (unsigned char *)s1;
	const unsigned char	*uchar_s2 = (unsigned char *)s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (uchar_s1[i] != uchar_s2[i])
			return (uchar_s1[i] - uchar_s2[i]);
		i++;
	}
	return (0);
}
