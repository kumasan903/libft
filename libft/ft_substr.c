/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:09:43 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/23 07:56:28 by skawanis         ###   ########.fr       */
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
	if((dest = ft_calloc(len, sizeof(char))) == NULL)
		return (NULL);
	if(ft_strlen(s) < start)
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

#include <stdio.h>
int	main(void)
{
	char *s = "libft-test-tokyo";
	/* 1 */ printf("%s\n", ft_substr(s, 0, 100));
	/* 3 */ printf("%s\n", ft_substr(s, 5, 100));
	/* 3 */ printf("%s\n", ft_substr(s, 10, 100));
	/* 4 */ printf("%s\n", ft_substr(s, 15, 100));
	/* 5 */ printf("%s\n", ft_substr(s, 20, 100));
	/* 6 */ printf("%s\n", ft_substr(s, 0, 5));
	/* 7 */ printf("%s\n", ft_substr(s, 5, 5));
	/* 8 */ printf("%s\n", ft_substr(s, 10, 5));
	/* 9 */ printf("%s\n", ft_substr(s, 15, 5));
	/* 10 */ printf("%s\n", ft_substr(s, 20, 5));
	/* 11 */ printf("%p\n", ft_substr(s, 0, 0));
	/* 12 */ printf("%p\n", ft_substr(s, 5, 0));
	/* 13 */ printf("%p\n", ft_substr(s, 10, 0));
	/* 14 */ printf("%p\n", ft_substr(s, 15, 0));
	/* 15 */ printf("%p\n", ft_substr(s, 20, 0));
}
