/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:52:02 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/12 09:00:55 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

size_t	malloc_words2(char const *s, char c, size_t *offset)
{
	size_t	word_len;

	word_len = 0;
	while (s[*offset] != c && s[*offset] != '\0')
	{
		(*offset)++;
		word_len++;
	}
	return (word_len);
}

int	malloc_words(char **return_vec, size_t word_count, char const *s, char c)
{
	size_t	vec_i;
	size_t	offset;
	size_t	start;
	size_t	word_len;

	vec_i = 0;
	offset = 0;
	start = 0;
	while (vec_i < word_count)
	{
		start = offset;
		while (s[offset] == c)
		{
			offset++;
			start++;
		}
		word_len = malloc_words2(s, c, &offset);
		return_vec[vec_i] = malloc(sizeof(char) * (word_len + 1));
		if (return_vec[vec_i] == NULL)
			return (1);
		ft_strlcpy(return_vec[vec_i], &s[start], word_len + 1);
		vec_i++;
	}
	return (0);
}

void	*free_and_return_null(char **return_vec)
{
	size_t	i;

	i = 0;
	while (return_vec[i] != NULL)
	{
		free(return_vec[i]);
		i++;
	}
	free(return_vec);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	const size_t	word_count = count_word(s, c);
	char			**return_vec;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ft_calloc(sizeof(char *), 1));
	return_vec = ft_calloc(sizeof(char *), word_count + 1);
	if (return_vec == NULL)
		return (NULL);
	if (malloc_words(return_vec, word_count, s, c) == 1)
		return (free_and_return_null(return_vec));
	return (return_vec);
}

/*
#include <stdio.h>
int main(void)
{
	size_t	i;
	char	**result;
	result = ft_split(NULL, '\0');
	printf("%p\n", result);
	puts("---");
	result = ft_split("//aaa//bb///ccccc", '/');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	puts("---");
	result = ft_split("test", '/');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	puts("---");
	result = ft_split("test", '\0');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	puts("---");
	result = ft_split("aaa//bb///ccccc", '/');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	puts("---");
	result = ft_split("//aaa//bb///ccccc///", '/');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	puts("---");
	result = ft_split("//////////////", '/');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
*/
