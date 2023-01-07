#include <stddef.h>
size_t ft_strlen(const char *s);

#define STRLEN "string"

#include <stdio.h>
int	main(void)
{
	puts("== ft_strlen ==");
	printf("%d\n", ft_strlen(STRLEN));
}
