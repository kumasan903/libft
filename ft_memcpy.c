/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:25:19 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/09 05:25:55 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

// TODO　多分destとかsrcがNULLだったときにセグフォするからそのエラー処理。
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
