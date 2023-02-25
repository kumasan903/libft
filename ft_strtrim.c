/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:47:14 by skawanis          #+#    #+#             */
/*   Updated: 2023/02/25 08:59:19 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_front(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	front;
	int	tmp;

	front = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		tmp = front;
		while (set[j])
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

static int	check_back(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	back;
	int	tmp;

	back = 0;
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		tmp = back;
		j = 0;
		while (set[j])
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
		i--;
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	int		front;
	int		back;

	front = check_front(s1, set);
	if ((size_t)front == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	back = check_back(s1, set);
	result = ft_calloc(sizeof(char), ft_strlen(s1) - front - back + 1);
	if (result == NULL)
		return (NULL);
	i = front;
	j = 0;
	while (i < ft_strlen(s1) - back)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	return (result);
}