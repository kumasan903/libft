/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:35:36 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/28 13:20:07 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0)
		return (dst);
	if (dst <= src)
	{
		return (ft_memcpy (dst, src, len));
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i--;
		}
		return (dst);
	}
}
