/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:32:21 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/11 11:32:45 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_num_len(unsigned int nb)
{
	size_t	count;

	if (nb == 0)
	{
		return (1);
	}
	count = 0;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static unsigned int	calc_divisor(size_t num_len)
{
	unsigned int	divisor;
	size_t			i;

	divisor = 1;
	i = 1;
	while (i < num_len)
	{
		divisor *= 10;
		i++;
	}
	return (divisor);
}

static void	ft_putuint_fd(unsigned int nb, int fd)
{
	size_t			nb_len;
	unsigned int	divisor;
	size_t			i;
	char			c;

	nb_len = count_num_len (nb);
	divisor = calc_divisor (nb_len);
	i = 0;
	while (i < nb_len)
	{
		c = (nb / divisor) % 10 + '0';
		write (fd, &c, 1);
		divisor /= 10;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write (fd, "-", 1);
		nb = n * -1;
		nb = ((unsigned int)(n + 1) *-1) + 1;
	}
	else
	{
		nb = n;
	}
	ft_putuint_fd (nb, fd);
}
