#include "../../includes/cube3d.h"

void	check_RGB_values(t_cubfile *file)
{
	int i;
	i = 0;

	//ciclo finche non trovo un numero
	while (!ft_isdigit(file->file_matrix[file->floor_index][i]))
	{
		// if (file->file_matrix[file->floor_index][i -1])
		// {
		// 	printf("SONO QUI");

		// 	if (!(file->file_matrix[file->floor_index][i] >= 9 && file->file_matrix[file->floor_index][i] <= 13) || file->file_matrix[file->floor_index][i] == 32)
		// 	{
		// 		print_err(RGB_VALUE_ERR);
		// 		exit(1);
		// 	}
		// }
		i++;
	}
	printf("VALUE %c\n", file->file_matrix[file->floor_index][i]);
	file->first_RGB_num = ft_atoi(file->file_matrix[file->floor_index] + 1);
	printf("NUM %d\n", file->first_RGB_num);

	
	// while ((!ft_isdigit(file->file_matrix[file->floor_index][i]) && file->file_matrix[file->floor_index][j] >= 9 && file->file_matrix[file->floor_index][j] <= 13) || file->file_matrix[file->floor_index][j] == 32)
	// {
	// 	// printf("VALUE %c\n", file->file_matrix[file->floor_index][i]);
	// 	i++;
	// }

	// while (file->file_matrix[file->floor_index][i]))
	// {
	// 	printf("VALUE %c\n", file->file_matrix[file->floor_index][i]);
	// 	i++;
	// }
	
	// if (file->file_matrix[file->floor_index][i] <= '2' && file->file_matrix[file->floor_index][i] >= '0')
	// 	i++;
	// j = i;
	// while (file->file_matrix[file->floor_index][j])
	// {
	// 	if ((file->file_matrix[file->floor_index][j] >= 9 && file->file_matrix[file->floor_index][j] <= 13) || file->file_matrix[file->floor_index][j] == 32)
	// 		j++;
	// 	else
	// 	{
	// 		print_err(RGB_VALUE_ERR);
	// 		exit(1);
	// 	}
}