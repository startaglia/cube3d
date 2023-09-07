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

void	check_map_start_ind(t_cubfile *file)
{
	//iteratore per le stringhe di file.matrix
	int	i;
	//iteratore per i char di file.matrix
	int	j;
	//flag se il char è consentito
	int	f;

	i = 0;
	j = 0;
	f = 0;
	while (file->file_matrix[i])
	{
		j = 0;
		while (file->file_matrix[i][j])
		{
			while ((file->file_matrix[i][j] == 9) || (file->file_matrix[i][j] > 10 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32))
				j++;
			//entra qui solo se è un char consentito dalla mappa
			if (file->file_matrix[i][j] == '1' || file->file_matrix[i][j] == '0' || file->file_matrix[i][j] == 'N' || file->file_matrix[i][j] == 'S' || file->file_matrix[i][j] == 'E' || file->file_matrix[i][j] == 'W')
			{	
				f = 1;
				j++;
			}
			//se entra qua non è inizio mappa, esco dal cilo while interno e posso andare alla prox i
			else
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			file->map_s->map_start_index = i;
			break;
		}
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

int		check_map_end_ind(t_cubfile *file)
{
	int i;
	
	i = file->map_s->map_start_index;

	while (i < file->matrix_end_index)
	{
		if (file->file_matrix[i] && !ft_strempt(file->file_matrix[i]))
		{
			file->map_s->map_end_index = i;
			return 0;
		}
		i++;
	}
	file->map_s->map_end_index = i;
	return 0;
}

int	check_map_last_elem(t_cubfile	*file)
{
	int	i;
	int map_len;
	int	j;

	i = file->map_s->map_end_index;
	j = 0;
	map_len = file->map_s->map_height - 1;
	// entra qui se la mappa e il matrix file finiscono allo stesso indice
	if (i == file->matrix_end_index)
	{
		while ((file->map_s->map_matrix[map_len][j] == 9) || (file->map_s->map_matrix[map_len][j] > 10 && file->map_s->map_matrix[map_len][j] <= 13) || (file->map_s->map_matrix[map_len][j] == 32))
			j++;
		while ((file->map_s->map_matrix[map_len][j] == '1' || file->map_s->map_matrix[map_len][j] == '0' || file->map_s->map_matrix[map_len][j] == 'N' || file->map_s->map_matrix[map_len][j] == 'S' || file->map_s->map_matrix[map_len][j] == 'E' || file->map_s->map_matrix[map_len][j] == 'W'))
			j++;
		//se arrivo all'utlimo char e tutti sono char ammessi allora l'ultima stringa è una stringa buona
		if (j == (int)(ft_strlen(file->map_s->map_matrix[map_len])))
			return 0;
		//qui esco perchè sicuro la stringa dopo ha un char non valido, quindi posso dare errore che la mappa non è l'ultima cosa nel file.
		else
		{
			print_err(MAP_POS_ERR);
			exit(1);
		}	
	}
	//entra qui se gli indici di fine map matrix e file matrix sono diversi, quindi ciclo su tutte le stringhe di file matrix che vengono dopo e vedo se sono vuote
	while (i < file->matrix_end_index)
	{
		if (ft_strempt(file->file_matrix[i]))
		{
			print_err(MAP_POS_ERR);
			exit(1);
		}
		i++;
	}
	return 0;
}

void	check_indexes(t_cubfile *file)
{
	//trovo quanto è alta la matrice
	file->matrix_end_index = matrix_lenght(file->file_matrix);

	//trovo l'indice di dove inizia la mappa
	check_map_start_ind(file);

	//trovo dove finisce la mappa
	check_map_end_ind(file);

	//controllare i valori degli id
	check_id_values(file);
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

void	fill_file_matrix(t_cubfile *file)
{
	//iteratore file.str
	int i;
	//lunghezza stringa fino a \n
	int l;
	//punto di partenza per ogni stringa della matrice
	int old_l;
	//iteratore delle stringhe di file_matrix
	int b;

	b = 0;
	l = 0;
	i = 0;
	old_l = 0;
	while (file->str[i])
	{
		old_l = i;
		l = 0;

		// mi trovo la lunghezza della stringa di ora (l)
		while (file->str[i] != 10 && file->str[i])
		{
			i++;
			l++;
		}
		if (l == 0)
			file->file_matrix[b] = ft_substr(file->str, old_l, 1);
		else
			file->file_matrix[b] = ft_substr(file->str, old_l, l);
		b++;
		i++;
	}
	file->file_matrix[b] = 0;
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

	//conto da quante linee è composta la stringa
	file->lines = count_lines(file->buff_str);
	//avendo aperto 100000 di mem buff mi serve contare quanti sono i char ascii
	while (ft_isascii(file->buff_str[j]))
		j++;
	//creo una substring di tutti i caratteri che sono ascii
	file->str = ft_substr(file->buff_str, 0, j + 1);
	//!FORSE A SANITAZER PIACE
	// file->str[j] = 0;
	if (j < (int)ft_strlen(file->str))
    	file->str[j] = '\0';
	//malloco la matrice
	file->file_matrix = malloc(sizeof(char *) * (file->lines + 1));
	file->file_matrix = init_matrix_null(file->file_matrix, file->lines);
	fill_file_matrix(file);
	//libero la mem buff che non mi serve più
	free(file->buff_str);
	free(file->str);

	// controllo index inizio e fine della matrice e della mappa
	check_indexes(file);

	//faccio la matrice della mappa
	matrix_map(file);

	//verifico che la mappa sia l' ultimo elemento del file
	check_map_last_elem(file);

	//controllo i valori RGB di F e C
	check_RGB_values(file);
}
