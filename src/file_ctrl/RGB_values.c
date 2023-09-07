#include "../../includes/cube3d.h"

int		check_RGB_range(t_cubfile *file, char **num_split_comma)
{
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
	return 0;
}


int		check_char_after_id(t_cubfile * file, int i)
{
	while (!ft_isdigit(file->file_matrix[file->F_text_index][i]))
	{
		//se entra qui c'è un char non ammesso, quindi non c'è un numero
		if (ft_isprint(file->file_matrix[file->F_text_index][i]))
		{
			print_err(RGB_VALUE_ERR);
			exit(1);
		}
		i++;
	}
	return 0;
}

int		check_num_commas(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	return c;
}

void	check_RGB_values(t_cubfile *file)
{
	int i;
	char **num_split_comma;
	char * buff_string;
	i = file->F_text_y + 1;
	//controllo eventuali char tra l'identificatore e il numero
	check_char_after_id(file, i);
	//creo una substr che isoli solo i numeri con la virgola per poterci fare la split
	buff_string = ft_substr(file->file_matrix[file->F_text_index], i, ( ft_strlen(file->file_matrix[file->F_text_index]) - i + 1));
	i = 0;	
	//controllo le virgole su buff_str, devono essere per forza 2 per avere 3 valori
	if (check_num_commas(buff_string) != 2)
	{
		if (check_num_commas(buff_string) > 2)
			print_err(RGB_VALUE_ERR);
		else
			print_err(RGB_VALUES_NUM);
		exit(1);
	}
	num_split_comma = ft_split(buff_string, ',');
	free(buff_string);

	//avendo i numeri in una matrix posso fare atoi e controllare se sono nel range
	check_RGB_range(file, num_split_comma);
	free_matrix(num_split_comma);
}
	
