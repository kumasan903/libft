#include "mylib.h"

#define STRLEN "string"
#define MEMCPY_SRC "sabakan"
#define STRLCPY_SRC "sabakan"

#include <stdio.h>
int	main(void)
{
	char *memcpy_dest;
	char strlcpy_dest[100];

	puts("== ft_strlen ==");
	printf("%d\n", ft_strlen(STRLEN));
	puts("== ft_memcpy ==");
	printf("%s\n", ft_memcpy(&memcpy_dest, MEMCPY_SRC, ft_strlen(MEMCPY_SRC)));
	puts("== ft_strlcpy ==");
	printf("return\t= %d\n", ft_strlcpy(strlcpy_dest, STRLCPY_SRC, 3));
	printf("dest\t= %s\n", strlcpy_dest);
}
