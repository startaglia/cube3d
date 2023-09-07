# include "../includes/cube3d.h"

void	check_mem(size_t size)
{
	printf("MEMORIA ALLOCATA--> %zu\n", size * sizeof(char));
}

char	**init_matrix_null(char **matrix, int	len)
{
	int k = 0;
	while (k < len)
	{
		 matrix[k] = NULL;
		 k++;
	}
	return (matrix);
}

void	print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

void	print_matrix_char(char **matrix)
{
	int i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			printf("%d", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		matrix_lenght(char	**matrix)
{
	int	i;
	
	i = 0;
	while (matrix[i])
		i++;
	return i;
}