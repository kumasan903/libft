/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:51:31 by skawanis          #+#    #+#             */
/*   Updated: 2023/05/02 12:35:33 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sum;
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	sum = count * size;
	if (sum / size != count)
	{
		return (NULL);
		errno = 12;
	}
	ptr = malloc(sum);
	if (ptr == NULL)
		return (NULL);
	while (sum)
		*((char *)ptr + --sum) = '\0';
	return (ptr);
}
