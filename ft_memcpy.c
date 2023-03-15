/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:25:19 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/14 15:32:53 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*uchar_src = (unsigned char *)src;
	unsigned char			*uchar_dst;
	size_t					i;

	uchar_dst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		uchar_dst[i] = uchar_src[i];
		i++;
	}
	return (dst);
}
