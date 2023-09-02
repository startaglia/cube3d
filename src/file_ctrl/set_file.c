# include "../../includes/cube3d.h"

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
		free(file->buff_str);
		exit(1);
	}
	file->fd_read = read(file->fd_open, file->buff_str, 1000000);
	if (file->fd_read == -1)
	{
		print_err(READ_ERROR);
		free(file->file_path);
		free(file->buff_str);
		exit(1);
	}
}
//ritorna 0 se la stringa contiene solo char non printable
int	ft_strempt(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		//ritorna 1 se trova un qualsiasi printable
		if (ft_isprint(s[i]))
			return 1;
		//torna 1 anche solo se la stringa è vuota ma senza spazi
		if (s[i] == 0)
			return 1;
		// vado avanti finche ci sono spazi e altro. se finisco il ciclo torno 0
		if ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
			i++;
	}
	return 0;
}

int	map_start_index(t_cubfile *file)
{
	int i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (file->file_matrix[i])
	{
		j = 0;
		while (file->file_matrix[i][j] && ft_isprint(file->file_matrix[i][j]))
		{
			while (((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32)))
				j++;
			if (ft_isprint(file->file_matrix[i][j]) && ((file->file_matrix[i][j] == 'F') || (file->file_matrix[i][j] == 'C' )|| (file->file_matrix[i][j] == 'N') || (file->file_matrix[i][j] == 'S') || (file->file_matrix[i][j] == 'E') || (file->file_matrix[i][j] == 'W')))
				break;
			else
			{
				res = i;
				break;
			}
			j++;
		}
		if (res != 0)
			break;
		i++;
	}
	return res;
}

void	skp_noprntbl(t_cubfile *file)
{
	int	i;
	int	j;
	int wrong_flag;
	int	empt_flag;

	i = file->map_s->map_start_index;
	while (file->file_matrix[i] && ft_strempt(file->file_matrix[i]))
	{
		j = 0;
		empt_flag = 0;
		wrong_flag = 0;
		while (file->file_matrix[i][j])
		{
			while (file->file_matrix[i][j] && ((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32)))
				j++;
			if (!file->file_matrix[i][j])
			{
				empt_flag = 1;
				break;
			}
			if (file->file_matrix[i][j] == '1' || file->file_matrix[i][j] == '0' || file->file_matrix[i][j] == 'N' || file->file_matrix[i][j] == 'S' || file->file_matrix[i][j] == 'E' || file->file_matrix[i][j] == 'W')
				j++;
			else
			{
				printf("CARATTERE SBAGLIATO\n");
				file->map_s->map_end_index = i;
				wrong_flag = 1;
				break;
			}
		}
		if (wrong_flag)
			break;
		if (empt_flag && !file->file_matrix[i + 1])
		{
			file->map_s->map_end_index = i;
			break;
		}
		file->map_s->map_end_index = i + 1;
		i++;
	}
}

void	check_indexes(t_cubfile *file)
{
	// int i;
	// int	j;
	// int flag;
	int k;

	// i = 0;
	// j = 0;
	// flag = 0;
	//trovo quanto è alta la matrice
	file->matrix_end_index = matrix_lenght(file->file_matrix);
	
	//trovo dove inizia la matrix_map
	file->map_s->map_start_index = map_start_index(file);
	k = file->map_s->map_start_index;

	printf("MAP START INDEX--> %d\n", k);

	//skippo tutti i non printbl nelle righe vuote tra l'ultimo identificatore e l'inizio della mappa
	skp_noprntbl(file);

	// int flagEmpt = 0;
	// while (file->file_matrix[k] && ft_strempt(file->file_matrix[k]))
	// {
	// 	// if (ft_str_isprint(file->file_matrix[i]))
	// 	j = 0;
	// 	flag = 0;
	// 	flagEmpt = 0;
	// 	// printf("\tMAP CHAR VALUE--> %s\n", file->file_matrix[k]);
	// 	while (file->file_matrix[k][j])
	// 	{
	// 		while (file->file_matrix[k][j] && ((file->file_matrix[k][j] >= 9 && file->file_matrix[k][j] <= 13) || (file->file_matrix[k][j] == 32)))
	// 		{
	// 			// printf("\t\t\tCHAR VALUE--> %d\n", file->file_matrix[k][j]);
	// 			j++;
	// 		}
	// 		if (!file->file_matrix[k][j])
	// 		{
	// 			flagEmpt = 1;
	// 			// file->map_s->map_end_index = k - 1;
	// 			// printf("\t\t\tVERIFICA QUI--> %d\n", file->file_matrix[k][j]);
	// 			break;
	// 		}
	// 		if (file->file_matrix[k][j] == '1' || file->file_matrix[k][j] == '0' || file->file_matrix[k][j] == 'N' || file->file_matrix[k][j] == 'S' || file->file_matrix[k][j] == 'E' || file->file_matrix[k][j] == 'W')
	// 		{
	// 			// printf("\tSCORRO--> %c", file->file_matrix[k][j]);
	// 			j++;
	// 		}
	// 		else
	// 		{
	// 			printf("CARATTERE SBAGLIATO\n");
	// 			file->map_s->map_end_index = k;
	// 			flag = 1;
	// 			break;
	// 		}
	// 	}
	// 	if (flag)
	// 		break;
	// 	if (flagEmpt && !file->file_matrix[k + 1])
	// 	{
	// 		file->map_s->map_end_index = k;
	// 		break;
	// 	}
	// 	file->map_s->map_end_index = k + 1;
	// 	k++;
	// }
}

int count_lines(char *str)
{
    int count = 0;

    int i = 0;
    while (str[i] != 0)
	{
        if (str[i] == '\n')
            count++;
		i++;
    }
    if (i > 0 && str[i - 1] != '\n')
        count++;
    return count;
}

void	check_file(t_cubfile *file, char *str)
{
	int j;

	j = 0;
	//controllo il formato del file
	if (check_format_file(str))
		exit (1);
	//apro e leggo il file
	open_read_file(file);
	
	//?CREAZIONE MATRICE DEL CONTENUTO FILE
	//conto da quante linee è composta la stringa
	file->lines = count_lines(file->buff_str);
	//avendo aperto 100000 di mem buff mi serve contare quanti sono i char ascii
	while (ft_isascii(file->buff_str[j]))
		j++;
	//creo una substring di tutti i caratteri che sono ascii
	file->str = ft_substr(file->buff_str, 0, j);
	//metto il contenuto del file in una matrix con split
	file->file_matrix = ft_split(file->str, '\n');
	print_matrix(file->file_matrix);
	//libero la mem buff che non mi serve più
	free(file->buff_str);
	free(file->str);
	//controllo index inizio e fine della matrice e della mappa
	check_indexes(file);
	// printf("MAP END INDEX QUI %d\n",file->map_s->map_end_index);


		
	//controllo dove si trova la mappa
	where_is_map(file);

	//controllo i valori degli identificatori
	check_id_file(file);
	
	// printf("F FLAG %d\n", file->F_flag);
	// printf("C FLAG %d\n", file->C_flag);
	// printf("NO FLAG %d\n", file->NO_flag);
	// printf("SO FLAG %d\n", file->SO_flag);
	// printf("WE FLAG %d\n", file->WE_flag);
	// printf("EA FLAG %d\n", file->EA_flag);

	//controllo i valori RGB di F e C
	check_RGB_values(file);
	// printf("INDICE INIZIO MATRIX %d\n", file->matrix_start_index);
	// printf("INDICE FINE MATRIX %d\n", file->matrix_end_index);
	// printf("INDICE INIZIO MAPPA %d\n", file->map_start_index);
	// printf("INDICE FINE MAPPA %d\n", file->map_end_index);
	
}
