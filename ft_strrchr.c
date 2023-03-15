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
	size_t	i;
	char	chr;
	char	*return_value;

	chr = (char)c;
	i = 0;
	return_value = NULL;
	while (1)
	{
		if (s[i] == chr)
			return_value = (char *)&s[i];
		i++;
		if (s[i] == '\0')
			break;
	}
	return (return_value);
}
