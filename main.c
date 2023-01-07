#include <stddef.h>
size_t ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);

#define STRLEN "string"
#define MEMCPY_SRC "sabakan"

#include <stdio.h>
int	main(void)
{
	char *memcpy_dest;

	puts("== ft_strlen ==");
	printf("%d\n", ft_strlen(STRLEN));
	puts("== ft_memcpy ==");
	printf("%s\n", ft_memcpy(&memcpy_dest, MEMCPY_SRC, ft_strlen(MEMCPY_SRC)));
}
