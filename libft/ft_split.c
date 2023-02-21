/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:12 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/21 20:49:33 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_char(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	malloc_str(char const *s, char c, char **dest)
{
	char *str;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = 0;
	while (s[i] && s[i] != c)
	{
		str_len++;
		i++;
	}
	// 次の区切り文字までの文字数分のメモリを確保する
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
	{
		*dest = NULL;
		return (0);
	}
	// 次の区切り文字まで確保した文字列に収めていく
	ft_strlcpy(str, s, str_len + 1);
	*dest = str;
	return (str_len);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char 			**result;
	unsigned int	offset;
	unsigned int	i;

	// 区切り文字の数を数える
	count = count_char(s, c);
	// 配列用のメモリを確保する
	result = malloc(sizeof(char *) * (count + 3));
	if (result == NULL)
		return (NULL);
	result[count + 2] = NULL;
	// それぞれの文字列用のメモリを確保する
	i = 0;
	offset = 0;
	while (i < count + 1)
	{
		offset += malloc_str(s + offset, c, &result[i]);
		offset += 1;
		i++;
	}
	malloc_str(s, c, &result[0]);
	return (result);
}
/*
void	main(void)
{
	ft_split("abc,def,ghi", ',');
}
*/
