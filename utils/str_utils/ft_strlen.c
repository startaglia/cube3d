# include "../includes/cube3d.h"

size_t
	ft_strlen(const char *s)
{
	if (s == NULL)
		return (0);

	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}