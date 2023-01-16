/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:21:58 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/10 11:29:58 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_i;
	size_t	src_i;

	dst_i = 0;
	while (dest[dst_i])
	{
		dst_i++;
	}
	src_i = 0;
	while (dst_i < size - 1)
	{
		dest[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	dest[dst_i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
