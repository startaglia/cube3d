# include "../includes/cube3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if ((!s1) || (!s2))
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2)
			* sizeof(char *) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i++];
	}
	res[j] = 0;
	return (res);
}