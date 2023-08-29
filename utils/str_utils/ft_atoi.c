# include "../../includes/cube3d.h"

static int	whitespaces(char *str, int *ptr_i)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43)
	{
		i++;
		*ptr_i = i;
		return (1);
	}
	else if (str[i] == 45)
	{
		i++;
		*ptr_i = i;
		return (-1);
	}
	else if (!(str[i] >= 48 && str[i] <= 57))
	{
		*ptr_i = i;
		return (0);
	}
	*ptr_i = i;
	return (1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = whitespaces(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
