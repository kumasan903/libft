/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowerhex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:42 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/27 20:35:59 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(size_t n, int fd, size_t *count)
{
	if (n > 15)
	{
		rec(n / 16, fd, count);
	}
	*count += write(fd, &"0123456789abcdef"[n % 16], 1);
}

ssize_t	ft_putlowerhex_fd(size_t n, int fd)
{
	size_t	count;

	count = 0;
	rec(n, fd, &count);
	return (count);
}
