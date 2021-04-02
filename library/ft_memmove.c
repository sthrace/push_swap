#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int			i;

	i = 0;
	if (((unsigned char *)src) < ((unsigned char *)dst))
		while (n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	else
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i += 1;
		}
	return (((unsigned char *)dst));
}
