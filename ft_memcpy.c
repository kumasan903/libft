#include <unistd.h>

// TODO　多分destとかsrcがNULLだったときにセグフォするからそのエラー処理。
void *ft_memcpy(void *dest, const void *src, size_t n)
{
	int i;

	i = 0;
	while(i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
