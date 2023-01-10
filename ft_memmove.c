#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest <= src)
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		i = n;
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
		return (dest);
	}
}
