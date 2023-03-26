/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:38:52 by skawanis          #+#    #+#             */
/*   Updated: 2023/03/26 00:25:37 by skawanis         ###   ########.fr       */
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

ssize_t	ft_putuint_fd(unsigned int nb, int fd)
{
	size_t			nb_len;
	unsigned int	divisor;
	size_t			i;
	char			c;

	nb_len = count_num_len(nb);
	divisor = calc_divisor(nb_len);
	i = 0;
	while (i < nb_len)
	{
		c = (nb / divisor) % 10 + '0';
		write (fd, &c, 1);
		divisor /= 10;
		i++;
	}
	return (i);
}
