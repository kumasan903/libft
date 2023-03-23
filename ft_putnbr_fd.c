/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:32:21 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/23 18:40:41 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = ((unsigned int)(n + 1) *-1) + 1;
	}
	else
	{
		nb = n;
	}
	ft_putuint_fd(nb, fd);
}
