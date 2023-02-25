/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:26:40 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/23 19:05:48 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1[0] && !s2[0])
		return (ft_calloc(1, sizeof(char)));
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	if (!s1[0])
		ft_memcpy(dest, s2, ft_strlen(s2));
	else if (!s2[0])
		ft_memcpy(dest, s1, ft_strlen(s1));
	else
	{
		ft_memcpy(dest, s1, ft_strlen(s1));
		ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	}
	return (dest);
}
