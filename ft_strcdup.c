/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:45:52 by skawanis          #+#    #+#             */
/*   Updated: 2023/05/02 10:47:51 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c)
{
	size_t	len;
	char	*dest;

	if (ft_strchr(s1, c))
	{
		len = ft_strclen_s(s1, c);
		dest = malloc(sizeof(char) * (len + 2));
		if (dest == NULL)
			return (NULL);
		dest[len + 1] = '\0';
		ft_memcpy(dest, s1, len + 1);
	}
	else
	{
		len = ft_strclen_s(s1, '\0');
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		dest[len] = '\0';
		ft_memcpy(dest, s1, len);
	}
	return (dest);
}
