/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:47:14 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/12 05:17:12 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	front;
	size_t	tmp;

	front = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		tmp = front;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				front++;
				break ;
			}
			j++;
		}
		if (front == tmp)
			break ;
		i++;
	}
	return (front);
}

static size_t	check_back(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	back;
	size_t	tmp;

	back = 0;
	i = ft_strlen (s1);
	while (i > 0)
	{
		i--;
		tmp = back;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				back++;
				break ;
			}
			j++;
		}
		if (back == tmp)
			break ;
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	front;
	size_t	back;
	size_t	s1_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = check_front(s1, set);
	s1_len = ft_strlen(s1);
	if (front == s1_len)
		return (ft_calloc(1, sizeof(char)));
	back = check_back(s1, set);
	result = ft_calloc(sizeof(char), s1_len - front - back + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, &s1[front], (s1_len - back) - front);
	return (result);
}
