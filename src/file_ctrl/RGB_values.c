#include "../../includes/cube3d.h"

void	check_RGB_values(t_cubfile *file)
{
	int i;
	char **num_split_comma;
	char * buff_string;
	i = file->F_text_y + 1;
	
	//controllo eventuali char tra l'identificatore e il numero
	while (!ft_isdigit(file->file_matrix[file->F_text_index][i]))
	{
		if (ft_isprint(file->file_matrix[file->F_text_index][i]))
		{
			print_err(RGB_VALUE_ERR);
			exit(1);
		}
		i++;
	}

	//creo una substr che isoli solo i numeri con la virgola per poterci fare la split
	buff_string = ft_substr(file->file_matrix[file->F_text_index], i, ( ft_strlen(file->file_matrix[file->F_text_index]) - i + 1));
	num_split_comma = ft_split(buff_string, ',');
	free(buff_string);

	//avendo i numeri in una matrix posso fare atoi e controllare se sono nel range
	file->first_RGB_num = ft_atoi(num_split_comma[0]);
	if(!(file->first_RGB_num <= 255 && file->first_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	file->second_RGB_num = ft_atoi(num_split_comma[1]);
	if(!(file->second_RGB_num <= 255 && file->second_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	file->third_RGB_num = ft_atoi(num_split_comma[2]);
	if(!(file->third_RGB_num <= 255 && file->third_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	free_matrix(num_split_comma);

	//faccio la stessa cosa per C
	i = file->C_text_y + 1;
	
	//controllo eventuali char tra l'identificatore e il numero
	while (!ft_isdigit(file->file_matrix[file->C_text_index][i]))
	{
		if (ft_isprint(file->file_matrix[file->C_text_index][i]))
		{
			print_err(RGB_VALUE_ERR);
			exit(1);
		}
		i++;
	}

	//creo una substr che isoli solo i numeri con la virgola per poterci fare la split
	buff_string = ft_substr(file->file_matrix[file->C_text_index], i, ( ft_strlen(file->file_matrix[file->C_text_index]) - i + 1));
	num_split_comma = ft_split(buff_string, ',');
	free(buff_string);

	//avendo i numeri in una matrix posso fare atoi e controllare se sono nel range
	file->first_RGB_num = ft_atoi(num_split_comma[0]);
	if(!(file->first_RGB_num <= 255 && file->first_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	file->second_RGB_num = ft_atoi(num_split_comma[1]);
	if(!(file->second_RGB_num <= 255 && file->second_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	file->third_RGB_num = ft_atoi(num_split_comma[2]);
	if(!(file->third_RGB_num <= 255 && file->third_RGB_num >= 0))
	{
		print_err(RGB_RANGE_ERR);
		free_matrix(num_split_comma);
		exit(1);
	}
	free_matrix(num_split_comma);
}
	
