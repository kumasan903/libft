/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:09:43 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/27 18:16:23 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	dst_i;
	size_t	src_i;

	if (len == 0)
		return ((char *)ft_calloc (1, sizeof(char)));
	if (s == NULL)
		return (NULL);
	dest = ft_calloc (len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (ft_strlen (s) < start)
		return ((char *)ft_calloc (1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);	
	dst_i = 0;
	src_i = start;
	ft_strlcpy(dest, &s[src_i], len);
	return (dest);
}
