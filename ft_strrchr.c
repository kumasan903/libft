/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:56:08 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/24 16:51:47 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;
	unsigned char	*return_value;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	return_value = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return_value = (unsigned char *)&s[i];
		i++;
	}
	if (str[i] == chr)
		return ((char *)&s[i]);
	return ((char *)return_value);
}
