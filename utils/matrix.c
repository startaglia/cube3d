# include "../includes/cube3d.h"

void print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

int	matrix_lenght(char	**matrix)
{
	int	i;
	
	i = 0;
	while (matrix[i])
		i++;
	return i;
}