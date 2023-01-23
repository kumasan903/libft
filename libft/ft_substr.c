/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:09:43 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/23 07:29:42 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	dst_i;
	size_t	src_i;

	if (len == 0)
		return (NULL);
	if((dest = malloc(len * sizeof(char))) == NULL)
		return (NULL);
	dst_i = 0;
	src_i = start;
	while(dst_i < len && s[src_i])
	{
		dest[dst_i] = s[src_i];
		dst_i++;
		src_i++;
	}
	dest[dst_i] = 0;
	return (dest);
}
