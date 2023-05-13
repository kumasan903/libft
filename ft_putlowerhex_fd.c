/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowerhex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:42 by skawanis          #+#    #+#             */
/*   Updated: 2023/05/13 23:21:14 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(size_t n, int fd, ssize_t *count)
{
	ssize_t	write_return;

	if (*count < 0)
		return ;
	if (n > 15)
	{
		rec(n / 16, fd, count);
	}
	write_return = write(fd, &"0123456789abcdef"[n % 16], 1);
	if (write_return < 0)
		*count = -1;
	*count += write_return;
}

ssize_t	ft_putlowerhex_fd(size_t n, int fd)
{
	ssize_t	count;

	count = 0;
	rec(n, fd, &count);
	return (count);
}
