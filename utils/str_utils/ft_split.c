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
	
	str = NULL;
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
	int consecutive_newlines = 0;  // Contatore per i caratteri '\n' consecutivi

	while (s[j] != 0)
	{
		if (s[j] != c)
		{
			start = j;
			while (s[j] != c && s[j])
			{
				if (s[j] == '\n')
				{
					if (consecutive_newlines > 0)
					{
						// Ignora i caratteri '\n' consecutivi tranne l'ultimo
						start = j - 1;
						consecutive_newlines = 0;  // Azzera il contatore
					}
					else
					{
						consecutive_newlines++;
					}
				}
				j++;
			}
			end = j;
			res[i++] = alloc_word_mem(s, start, end);
		}
		else if (s[j] == c)
		{
			j++;
		}
	}
	res[i] = 0;
	return (res);
}























































// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
// 	int		start;
// 	int		end;
// 	// int		flag = 0;

// 	j = 0;
// 	i = 0;
// 	res = malloc_func(s, c);


// 	// printf("CHAR VALUE--> %d/n", s[j]);
//     while (s[j] != 0)
//     {
//         if ((s[j] == '\n') && (s[j]))
//         {
			
// 			printf("J--> %d\n", j);
//             start = j;
// 			// printf("START--> %d\n", start);
// 			printf("START VALUE--> %d\n", s[j]);

//             while (s[j] == '\n' && s[j])
//             {
// 				printf("CHAR VALUE--> %d\n", s[j]);
//                 j++;
//             }
//             end = j;
// 			// printf("END--> %d\n", end);
// 			printf("END VALUE--> %d\n", s[j]);

//             res[i++] = alloc_word_mem(s, start, end);
// 			i--;
			
// 			// int l = 0;
// 			// int p = 0;
// 			// while (res[l])
// 			// {
// 			// 	p = 0;
// 			// 	while (res[l][p])
// 			// 	{
// 			// 		printf(" RES[l][p]%c\t", res[l][p]);
// 			// 		p++;
// 			// 	}
// 			// 		printf("\n");
// 			// 	l++;
// 			// }
//         }
//         else if (s[j] && s[j] != c)
//         {
// 			// flag = 0;
//             start = j;
//             while (s[j] != c && s[j])
//                 j++;
//             end = j;
//             res[i++] = alloc_word_mem(s, start, end);
//         }
//         else if (s[j] == c)
//         {
// 			// flag = 0;
//             j++;
//         }
//     }
// 	// if (flag == 1)
// 	// 	i--;
// 	printf(" RES[i]%s\n", res[i - 1]);
// 	res[i] = 0;

// 	// int l = 0;
// 	// int p = 0;
// 	// while (res[l])
// 	// {
// 	// 	p = 0;
// 	// 	while (res[l][p])
// 	// 	{
// 	// 		printf(" RES[l][p]%c\t", res[l][p]);
// 	// 		p++;
// 	// 	}
// 	// 		printf("\n");
// 	// 	l++;
// 	// }

// 	// int l = 0;
// 	// 		int p = 0;
// 	// 		while (res[l])
// 	// 		{
// 	// 			p = 0;
// 	// 			while (res[l][p])
// 	// 			{
// 	// 				printf(" RES[l][p]-->%c", res[l][p]);
// 	// 				p++;
// 	// 			}
// 	// 				printf("\n");
// 	// 			l++;
// 	// 		}
// 	return (res);
// }

// // char	**ft_split(char const *s, char c)
// // {
// // 	char	**res;
// // 	int		i;
// // 	int		j;
// // 	int		start;
// // 	int		end;
// // 	// int		flag = 0;

// // 	j = 0;
// // 	i = 0;
// // 	res = malloc_func(s, c);

// // 	while (s[j] != 0)
// // 	{
// // 		if (s[j] != c)
// // 		{
// // 			start = j;
// // 			while (s[j] != c && s[j])
// // 				j++;
// // 			end = j;
// // 			res[i++] = alloc_word_mem(s, start, end);
// // 		}
// // 		else if (s[j] == c)
// // 			j++;
// // 	}
// // 	res[i] = 0;
// // 	return (res);
// // }