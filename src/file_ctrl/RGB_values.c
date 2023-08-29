#include "../../includes/cube3d.h"

void	check_RGB_values(t_cubfile *file)
{
	int i;
	// char **num_split_comma;
	i = 0;
	
	//controllo eventuali char tra l'identificatore e il numero
	i++;
	while (!ft_isdigit(file->file_matrix[file->floor_index][i]) || ((file->file_matrix[file->floor_index][i] >= 9 && file->file_matrix[file->floor_index][i] <= 13) || (file->file_matrix[file->floor_index][i] == 32)))
	{
		printf("VALUE %c\n", file->file_matrix[file->floor_index][i]);

		if (ft_isprint(file->file_matrix[file->floor_index][i]))
		{
			printf("entro qui\n");
			print_err(RGB_VALUE_ERR);
			exit(1);
		}
		i++;
	}
	//creo una substr che isoli solo i numeri con la virgola per poterci fare la split
	int z = 0;
	int n = 0;
	int m = 0;

	//ciclo per contare quanti sono gli spazi tra l'inizio e l'identificatore.
	// while (file->file_matrix[file->floor_index][n] != 'F')
	// {
	// 	if (file->file_matrix[file->floor_index][n] == 9)
	// 	{
	// 		m += 4;
	// 		continue;
	// 	}
	// 	// z++;
	// 	m++;
	// 	n++;
	// }
	printf("CHAR TRA L'INIZIO E L'ID %d\n", m);
	
	//ciclo per contare quanti sono gli spazi tra l'identificatore e il primo num.
	// ++z;
	while (!ft_isdigit(file->file_matrix[file->floor_index][++z]))
	{
		if (file->file_matrix[file->floor_index][++z] == 9)
		{
			n += 4;
			continue;
		}
		// z++;
		n++;
	}
	n--;
	printf("CHAR TRA L'ID E IL PRIMO NUM %d\n", n);
	
	printf("qui %s\n", file->file_matrix[file->floor_index]);
	char *test = ft_substr(file->file_matrix[file->floor_index], n, (ft_strlen((file->file_matrix[file->floor_index] ))));
	printf("CHAR* TRIMMATA %s\n", test);

	file->first_RGB_num = ft_atoi(file->file_matrix[file->floor_index] + 1);
	// i++;
	printf("VALUE FUORI %c\n", file->file_matrix[file->floor_index][i + 1]);
	file->file_matrix[file->floor_index][i]++;
	printf("VALUE FUORI %c\n", file->file_matrix[file->floor_index][i]);

	file->second_RGB_num = ft_atoi(file->file_matrix[file->floor_index]);
	printf("NUM1 %d\n", file->first_RGB_num);
	printf("NUM2 %d\n", file->second_RGB_num);

	
		// file->file_matrix[file->floor_index][i] == ',')
	// {
	// 	printf("VALUE DENTRO %c\n", file->file_matrix[file->floor_index][i]);
		
	// 	if (ft_isdigit(file->file_matrix[file->floor_index][i]))
	// 	{
	// 		print_err(RGB_VALUE_ERR);
	// 		exit(1);
	// 	}
	// 	i++;
	// 	// if (((!ft_isdigit(file->file_matrix[file->floor_index][i])) && (file->file_matrix[file->floor_index][i] <= 9 && file->file_matrix[file->floor_index][i] >= 13)) || (file->file_matrix[file->floor_index][i] != 32))
	// 	// {
	// 	// 	print_err(RGB_VALUE_ERR);
	// 	// 	exit(1);
	// 	// }
	// }
	
	

	// file->second_RGB_num = ft_atoi(file->file_matrix[file->floor_index] + 1);
	

	
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