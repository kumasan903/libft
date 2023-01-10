/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:26:20 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/09 09:39:42 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int	ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	else
		return (0);
}
