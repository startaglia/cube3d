# include "../../includes/cube3d.h"

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


void	skp_noprntbl(t_cubfile *file)
{
	int	i;
	int	j;
	int wrong_flag;
	int	empt_flag;

	i = file->map_s->map_start_index;


	// print_matrix_char(file->file_matrix);

	while (file->file_matrix[i] && ft_strempt(file->file_matrix[i]))
	{

		// printf("STREMPT %d\n", ft_strempt(file->file_matrix[i]));
		// printf("VALUE %s\tI-->%d\n", file->file_matrix[i], i);
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
				file->map_s->map_end_index = i;
				wrong_flag = 1;
				break;
			}
		}
		if (wrong_flag)
		{
			print_err("CAZZO");
			// free_matrix(file->map_s->map_matrix);
			// free(file->map_s);
			// free(file->file_path);
			// free_matrix(file->file_matrix);
			// free(file);
			exit(1);
		}
		if (empt_flag && !file->file_matrix[i + 1])
		{
			file->map_s->map_end_index = i;
			break;
		}
		file->map_s->map_end_index = i + 1;
		i++;
	}
}

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
		while (file->file_matrix[i][j] && ft_strempt(file->file_matrix[i]))
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

void	check_indexes(t_cubfile *file)
{
	//trovo quanto è alta la matrice
	file->matrix_end_index = matrix_lenght(file->file_matrix);

	//trovo dove inizia la matrix_map
	file->map_s->map_start_index = map_start_index(file);

	//skippo tutti i non print nelle righe vuote tra l'ultimo identificatore e l'inizio della mappa
	skp_noprntbl(file);
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
	printf("LINES %d\n", file->lines);
	//avendo aperto 100000 di mem buff mi serve contare quanti sono i char ascii
	while (ft_isascii(file->buff_str[j]))
		j++;
	printf("J %d\n", j);
	// printf("MOSTRO \n%s", file->buff_str);

	//creo una substring di tutti i caratteri che sono ascii
	file->str = ft_substr(file->buff_str, 0, j + 1);
	file->str[j] = 0;
	// printf("\t-----STRINGONA----\n%s\n\n", file->str);

	//malloco la matrice
	file->file_matrix = malloc(sizeof(char *) * (file->lines + 1));

	//iteratore stringona
	int k = 0;
	// Inizializza tutt a NULL
	while (k < file->lines)
	{
		 file->file_matrix[k] = NULL;
		 k++;
	}
	k = 0;
	//lunghezza stringa fino a \n
	int l = 0;
	//punto di partenza per ogni stringa della matrice
	int old_l = 0;
	//iteratore delle stringhe di file_matrix
	int b = 0;
	while (file->str[k])
	{
		old_l = k;
		l = 0;

		// mi trovo la lunghezza della stringa di ora (l)
		while (file->str[k] != 10 && file->str[k])
		{
			k++;
			l++;
		}
		if (l == 0)
			file->file_matrix[b] = ft_substr(file->str, old_l, 1);
		else
			file->file_matrix[b] = ft_substr(file->str, old_l, l);

		// printf("str[k]STRINGA %s\n", file->file_matrix[b]);
		// //devo fare la substr k - 1 volte partendo da k
		// printf("*************\n");
		// print_matrix_char(file->file_matrix);
		// printf("\n*************\n");
		// printf("\n++++++++++++++++++++++++++\n");

		// printf("\n++++++++++++++++++++++++++\n\n");
		b++;
		k++;
	}
	file->file_matrix[b] = 0;
	print_matrix_char(file->file_matrix);
	printf("-----------------------------------\n");

	//libero la mem buff che non mi serve più
	free(file->buff_str);
	free(file->str);

	// //controllo index inizio e fine della matrice e della mappa
	// check_indexes(file);

	// //controllo dove si trova la mappa
	// where_is_map(file);

	// //controllo i valori degli identificatori
	// check_id_file(file);

	// //controllo i valori RGB di F e C
	// check_RGB_values(file);
}
