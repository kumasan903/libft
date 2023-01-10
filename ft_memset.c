#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*new_s;

	new_s = (char *)s;
	i = 0;
	while (i < n)
	{
		new_s[i] = (char)c;
		i++;
	}
	return (s);
}
