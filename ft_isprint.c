/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:26:20 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/10 03:11:33 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_isprint(int c)
{
	if (0x20 <= c && c <= 0x7e)
		return (1);
	else
		return (0);
}
