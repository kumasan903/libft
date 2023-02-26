/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:12 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/26 13:30:12 by skawanis         ###   ########.fr       */
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
		{
			count++;
			while (s[i + 1] == c)
				i++;
		}
		i++;
	}
	return (count);
}

size_t	malloc_str(char const *s, char c, char **dest)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = 0;
	while (s[i] && s[i] != c)
	{
		str_len++;
		i++;
	}
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
	{
		*dest = NULL;
		return (0);
	}
	ft_strlcpy(str, s, str_len + 1);
	*dest = str;
	return (str_len);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**result;
	unsigned int	offset;
	unsigned int	i;
	char			*new_s;

	new_s = ft_strtrim(s, &c);
	if (new_s == NULL)
		return (NULL);
	count = count_char(new_s, c);
	if (s[0] == '\0')
		return (ft_calloc(sizeof(char *), 1));
	result = malloc(sizeof(char *) * (count + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < count + 1)
	{
		offset += malloc_str(new_s + offset, c, &result[i]);
		if (result[i] == NULL)
			result[0] = NULL;
		while (new_s[offset] == c)
			offset++;
		i++;
	}
	result[count + 1] = NULL;
	return (result);
}
