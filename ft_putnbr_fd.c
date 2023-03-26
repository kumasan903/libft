/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:32:21 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/26 00:21:22 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	ssize_t			len;

	len = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = ((unsigned int)(n + 1) *-1) + 1;
		len += 1;
	}
	else
	{
		nb = n;
	}
	len += ft_putuint_fd(nb, fd);
	return (len);
}
