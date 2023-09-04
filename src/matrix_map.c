# include "../includes/cube3d.h"

void	get_map_sizes(t_cubfile *file)
{
	int	i;
	int	j;
	
	i = file->map_s->map_start_index;
	while (i < file->map_s->map_end_index)
	{
		j = 0;
		while (file->file_matrix[i][j])
		{
			// printf("%c", file->file_matrix[i][j]);
			j++;
		}
		if (file->map_s->map_widht < j)
			file->map_s->map_widht = j;
		// printf("\t\t\tJ: %d\n", j);
		i++;
	}
	// printf("MAP WIDHT %d\n", file->map_s->map_widht);
	
	// file->map_s->map_widht = 
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}


void	check_mem(size_t size)
{
	printf("MEMORIA ALLOCATA--> %zu\n", size * sizeof(char));
}

void	matrix_map(t_cubfile *file)
{
	//iteratore ciclo fuori
	int curr_ind;
	//iteratore per la stringa di file.matrix
	int	map_ind;
	//lunghezza della stringa a cui sta puntando file.matrix
	size_t buff_len;
	//iteratore per la stringa di matrix.map
	size_t buff_ind;
	size_t	num_rows;
	
	curr_ind= 0;
	map_ind = file->map_s->map_start_index;
	//calcolo l'altezza della matrice map e malloco mem
	num_rows = (file->map_s->map_end_index - file->map_s->map_start_index) + 2;
	file->map_s->map_matrix = malloc((num_rows * sizeof(char *)) + 1);

	// Inizializza tutt a NULL
	while (curr_ind < (int)num_rows)
	{
		 file->map_s->map_matrix[curr_ind] = NULL;
		 curr_ind++;
	}
	curr_ind = 0;
	//ciclo per riempire la matrix map
	while (file->file_matrix[map_ind] && (curr_ind < (int)num_rows) && (ft_strempt(file->file_matrix[map_ind])))
	{
		buff_len =ft_strlen(file->file_matrix[map_ind]) + 1;
		buff_ind = 0;
		//malloco mem per la stringa su cui sto ciclando
		file->map_s->map_matrix[curr_ind] = malloc(buff_len * sizeof(char) + 1);
		//riempio char per char la stringa
		while (buff_ind < buff_len)
		{
			file->map_s->map_matrix[curr_ind][buff_ind] = file->file_matrix[map_ind][buff_ind];
			buff_ind++;
		}
		buff_ind--;
		file->map_s->map_matrix[curr_ind][buff_ind] = '\0';
		curr_ind++;
		map_ind++;
	}
	curr_ind--;
	// file->map_s->map_matrix[curr_ind] = 0;
	printf("-----------------MATRICE-----------------\n");
}
























// void	matrix_map(t_cubfile *file)
// {
// 	int i;

// 	i = 0;
// 	// Calcola il numero di righe nella matrice
// 	size_t num_rows = file->map_s->map_end_index - file->map_s->map_start_index;
// 	printf("INDICE INIZIO MAP %d\tINDICE FINE MAP %d\n", file->map_s->map_start_index, file->map_s->map_end_index);

// 	printf("NUM ROWS %ld\n", num_rows);









// 	// Malloca mem
// 	file->map_s->map_matrix = malloc((num_rows * sizeof(char *)) + 1);

// 	// Inizializza tutti i puntatori a NULL
// 	while (i < (int)num_rows)
// 	{
// 		 file->map_s->map_matrix[i] = 0;
// 		 i++;
// 	}
// 	i = 0;
	
// 	int curr_ind = 0;
// 	int mp_ind = file->map_s->map_start_index;
// 	size_t buff_ind = 0;
// 	size_t buff_len = 0;
// 	// printf("LEN-->%s\n", file->file_matrix[k]);
// 	printf("mp_INdex-->%d\n",mp_ind);
// 	printf("valore a cui punta mp_ind--->%s\n", file->file_matrix[mp_ind]);
// 	while (i < (int)num_rows)
// 	{
// 		buff_len = ft_strlen(file->file_matrix[mp_ind]);
// 		buff_ind = 0;

// 		printf("lunghezza stringa di adesso-->%ld\n", buff_len);
// 		file->map_s->map_matrix[curr_ind] = malloc(buff_len * sizeof(char));
// 		while (buff_ind < buff_len)
// 		{
// 			file->map_s->map_matrix[curr_ind][buff_ind] = file->file_matrix[mp_ind][buff_ind];
// 			// printf("%c", file->map_s->map_matrix[curr_ind][buff_ind]);
// 			// printf("BUFF_IND-->%ld\n", buff_ind);
			
// 			buff_ind++;
// 		}
// 		// printf("\n");
// 			printf("VALORE IN MATRICE--->%s\n", file->map_s->map_matrix[curr_ind]);

// 		// file->map_s->map_matrix[curr_ind][buff_ind] = 0;
// 		printf("I--->%d\n",i);
// 		// printf("VALORE IN MATRICE--->%s\n", file->map_s->map_matrix[i]);
// 		// file->map_s->map_matrix[curr_ind][j] = 0;
// 		// file->map_s->map_matrix[j] = ft_strcpy(file->map_s->map_matrix[j], file->file_matrix[k]);
// 		// printf("valore in matrice--->%s\n", file->file_matrix[j]);
// 		//  printf("VALORE STRINGA COPIATA contrario--->%s\n", file->map_s->map_matrix[i]);
// 		 curr_ind++;
// 		 mp_ind++;
// 		 i++;
// 	}
// 	// free_matrix(file->map_s->map_matrix);
// 	// file->map_s->map_matrix[i] = 0;


// 	// //riempio la matrix con i valori della mappa
// 	// i = file->map_s->map_start_index;

	




// 	// print_matrix(file->map_s->map_matrix);



// 	// printf("PRIMA RIGA: %s\n", file->file_matrix[file->map_s->map_start_index]);
// 	// printf("ULTIMA RIGA: %s\n", file->file_matrix[file->map_s->map_end_index]);
// }