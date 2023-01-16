/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:51:31 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:10 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	sum;
	void	*ptr;

	sum = number * size;
	ptr = malloc(sum);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, sum);
	return (ptr);
}
