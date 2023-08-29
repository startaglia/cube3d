#include "../includes/cube3d.h"

static int	get_n_word(const char *s, char c)
{
	int	i;
	int	count;
	int	trig;

	trig = 0;
	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && trig == 0)
		{
			count += 1;
			trig = 1;
		}
		else if (s[i] == c)
			trig = 0;
		i++;
	}
	return (count);
}

static char	**malloc_func(char const *s, char c)
{
	char	**res;

	res = NULL;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (get_n_word(s, c) + 1));
	if (!res)
		return (0);
	return (res);
}

static char	*alloc_word_mem(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	int		end;

	j = 0;
	i = 0;
	res = malloc_func(s, c);
	while (s[j] != 0)
	{
		if (s[j] != c)
		{
			start = j;
			while (s[j] != c && s[j])
				j++;
			end = j;
			res[i++] = alloc_word_mem(s, start, end);
		}
		else if (s[j] == c)
			j++;
	}
	res[i] = 0;
	return (res);
}