/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:42:48 by skawanis          #+#    #+#             */
/*   Updated: 2023/07/24 02:11:48 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	printf_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(str, fd));
}

static ssize_t	ft_putptr_fd(size_t ptr, int fd)
{
	ssize_t	tmp;

	tmp = ft_putstr_fd("0x", fd);
	if (tmp < 2)
		return (-1);
	tmp = ft_putlowerhex_fd(ptr, fd);
	if (tmp < 0)
		return (-1);
	return (2 + tmp);
}

static ssize_t	handle_format(char type, va_list list)
{
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(list, int), 1));
	if (type == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	if (type == 's')
		return (printf_putstr_fd(va_arg(list, char *), 1));
	if (type == 'u')
		return (ft_putuint_fd(va_arg(list, unsigned int), 1));
	if (type == 'x')
		return (ft_putlowerhex_fd(va_arg(list, unsigned int), 1));
	if (type == 'X')
		return (ft_putupperhex_fd(va_arg(list, unsigned int), 1));
	if (type == 'p')
		return (ft_putptr_fd(va_arg(list, size_t), 1));
	if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	const size_t	fmt_len = ft_strlen_s(fmt);
	size_t			i;
	va_list			list;
	ssize_t			printed_count;

	printed_count = 0;
	va_start(list, fmt);
	i = 0;
	while (i < fmt_len)
	{
		if (printed_count > INT_MAX)
			return (-1);
		if (fmt[i] == '%')
		{
			printed_count += handle_format(fmt[i + 1], list);
			i += 2;
			continue ;
		}
		printed_count += ft_putchar_fd(fmt[i], 1);
		i++;
	}
	va_end(list);
	return (printed_count);
}
