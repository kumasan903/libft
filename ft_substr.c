/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:09:43 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/12 05:16:15 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	src_i;

	if (len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	src_i = start;
	ft_strlcpy(dest, &s[src_i], len + 1);
	return (dest);
}
