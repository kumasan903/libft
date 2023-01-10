/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:28:05 by skawanis          #+#    #+#             */
/*   Updated: 2023/01/10 07:07:15 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define STRLEN "string"
#define MEMCPY_SRC "sabakan"
#define STRLCPY_SRC "sabakan"
#define ISALPHA_SRC 'G'
#define ISDIGIT_SRC '7'
#define ISALNUM_SRC 'b'
#define ISASCII_SRC 0x10
#define ISPRINT_SRC 'F'

#include <stdio.h>
int	main(void)
{
	char	*memcpy_dest;
	char	strlcpy_dest[100];
	char	memset_dest[10] = "1234567890";
	char	bzero_dest[10] = "1234567890";

	puts("== ft_strlen ==");
	printf("%d\n", (int)ft_strlen(STRLEN));
	puts("== ft_memcpy ==");
	printf("%s\n", (char *)ft_memcpy(&memcpy_dest, MEMCPY_SRC, ft_strlen(MEMCPY_SRC)));
	puts("== ft_strlcpy ==");
	printf("return\t= %d\n", (int)ft_strlcpy(strlcpy_dest, STRLCPY_SRC, 3));
	printf("dest\t= %s\n", strlcpy_dest);
	puts("== ft_isalpha ==");
	printf("%d\n", ft_isalpha(ISALPHA_SRC));
	puts("== ft_isdigit ==");
	printf("%d\n", ft_isdigit(ISDIGIT_SRC));
	puts("== ft_isalnum ==");
	printf("%d\n", ft_isalnum(ISALNUM_SRC));
	puts("== ft_isascii ==");
	printf("%d\n", ft_isascii(ISASCII_SRC));
	puts("== ft_isprint ==");
	printf("%d\n", ft_isprint(ISPRINT_SRC));
	puts("== ft_memset ==");
	printf("%s\n", (char *)ft_memset(memset_dest, '5', 3));
	puts("== ft_bzero ==");
	ft_bzero(bzero_dest + 3, 3);
	printf("%s\n", bzero_dest);
}
