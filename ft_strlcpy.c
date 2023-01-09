#include "mylib.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
        const unsigned int      srclen = ft_strlen(src);

        if (srclen < size)
        {
                ft_memcpy(dest, src, srclen + 1);
        }
        else if (size != 0)
        {
                ft_memcpy(dest, src, size - 1);
                dest[size - 1] = '\0';
        }
        return (ft_strlen(src));
}
