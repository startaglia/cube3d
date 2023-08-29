# include "../includes/cube3d.h"

int	check_format_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while (1)
	{
		if (str[i] == 'b')
			i--;
		if (str[i] == 'u')
			i--;
		if (str[i] == 'c')
			i--;
		if (str[i] == '.')
			return 0;
		print_err(EXT_FILE_ERR);
		return 1;
	}
}

void	open_read_file(t_cubfile *file)
{
	file->fd_open = open(file->file_path, O_RDONLY);
	if (file->fd_open == -1)
	{
		print_err(OPEN_ERROR);
		free(file->file_path);
		free(file->buff);
		exit(1);
	}
	file->fd_read = read(file->fd_open, file->buff, 1000000);
	if (file->fd_read == -1)
	{
		print_err(READ_ERROR);
		free(file->file_path);
		free(file->buff);
		exit(1);
	}
}

void	where_is_map(t_cubfile *file)
{
	if (file->matrix_end_index != file->map_end_index)
	{
		print_err(MAP_POS_ERR);
		free(file->file_path);
		free_matrix(file->file_matrix);
		free(file->buff);
		exit(1);
	}
}

void	check_indexes(t_cubfile *file)
{
	int i;
	int k;

	i = 0;
	while (file->file_matrix[i])
		i++;
	file->matrix_end_index = i - 1;
	i = 0;
	while (file->file_matrix[i][0] != '1')
		i++;
	k = i;
	file->map_start_index = i;
	while (file->file_matrix[k][0] == '1')
		k++;
	file->map_end_index = k;
}

void	check_file(t_cubfile *file, char *str)
{
	//controllo il formato del file
	if (check_format_file(str))
		exit (1);

	//apro e leggo il file
	open_read_file(file);
	
	//metto il contenuto del file in una matrix con split
	file->file_matrix = ft_split(file->buff, '\n');
	print_matrix(file->file_matrix);
		
	//controllo index inizio e fine della matrice
	check_indexes(file);
		
	//controllo dove si trova la mappa
	where_is_map(file);

	//se index fine mappa è uguale all'index di fine matrice, posizione mappa ok.
	printf("INDICE INIZIO MATRIX %d\n", file->matrix_start_index);
	printf("INDICE FINE MATRIX %d\n", file->matrix_end_index);
	printf("INDICE INIZIO MAPPA %d\n", file->map_start_index);
	printf("INDICE FINE MAPPA %d\n", file->map_end_index);
	free(file->file_path);
	free_matrix(file->file_matrix);
	free(file->buff);
}


