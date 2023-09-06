# include "../includes/cube3d.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	arr_size;
	char	*res;


	if (!s)
		return (0);
	arr_size = 0;
	slen = ft_strlen(s);
	if (start < slen)
		arr_size = slen - start;
	if (arr_size > len)
		arr_size = len;
	res = (char *)malloc((arr_size + 1) * (sizeof(char)));
	if (!res)
		return (0);
	ft_strlcpy(res, (char *)s + start, arr_size + 1);
	return (res);
}
