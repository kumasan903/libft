/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:48:12 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/06 09:50:44 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_char(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
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

static void	all_free(char ****result, unsigned int i)
{
	while (i >= 0)
	{
		free ((*result)[i]);
		i--;
	}
	free (*result);
	*result = NULL;
}

static size_t	malloc_str(char const *s, char c, char **dest)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		str_len++;
		i++;
	}
	str = malloc (sizeof(char) * (str_len + 1));
	if (str == NULL)
	{
		*dest = NULL;
		return (0);
	}
	ft_strlcpy (str, s, str_len + 1);
	*dest = str;
	return (str_len);
}

static void
	wrap_malloc_str(char ***result, char **new_s, size_t *count, char *c)
{
	unsigned int	i;
	unsigned int	offset;

	i = 0;
	offset = 0;
	while (i < *count + 1)
	{
		offset += malloc_str (*new_s + offset, *c, &(*result)[i]);
		if ((*result)[i] == NULL)
		{
			all_free (&result, i);
			return ;
		}
		while ((*new_s)[offset] == *c)
			offset++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;
	char	*new_s;
	char	new_c[2];

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ft_calloc(sizeof(char *), 1));
	new_c[0] = c;
	new_c[1] = '\0';
	new_s = ft_strtrim(s, new_c);
	if (new_s == NULL)
		return (NULL);
	count = count_char (new_s, c);
	if (count == ft_strlen (new_s))
	{
		free(new_s);
		return (ft_calloc (sizeof(char *), 1));
	}
	result = ft_calloc (sizeof(char *), count + 2);
	if (result == NULL)
	{
		free(new_s);
		return (NULL);
	}
	wrap_malloc_str (&result, &new_s, &count, &c);
	free(new_s);
	return (result);
}
