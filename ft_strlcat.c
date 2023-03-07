/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:21:58 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/26 11:43:18 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	len_dst;
	size_t	len_src;

	if (dstsize == 0)
		return (ft_strlen (src));
	len_dst = ft_strlen (dst);
	len_src = ft_strlen (src);
	if (ft_strlen (dst) >= dstsize)
		return (dstsize + ft_strlen (src));
	dst_i = 0;
	while (dst[dst_i] != '\0')
	{
		dst_i++;
	}
	src_i = 0;
	while (dst_i + 1 < dstsize && src[src_i] != '\0')
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	dst[dst_i] = '\0';
	return (len_dst + len_src);
}
