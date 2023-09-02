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






//QUESTA FUNZIONE È DI BARD. SOTTO LA MIA. QUESTA COSI ORA DA SOLO UN LEAKS CHE DOVREI RIUSCIRE A TOGLIERE. IL PROBLEMA È PERÒ NON FUNZIONA. PERÒ FORSE UNO DEI PROBLEMI È LA STRINGA CHE È TROPPO LUNGA DELLO SPAZIO IN MEMORIA. RIPARTIRE STUDIANDO QUESTA

void	matrix_map(t_cubfile *file)
{
	int i;
	// char *str;
	size_t buff_len;

	i = 0;
	// Calcola il numero di righe nella matrice
	size_t num_rows = file->map_s->map_end_index - file->map_s->map_start_index;
	printf("INDICE INIZIO MAP %d\tINDICE FINE MAP %d\n", file->map_s->map_start_index, file->map_s->map_end_index);

	printf("NUM ROWS %ld\n", num_rows);








	// Malloca mem
	file->map_s->map_matrix = malloc((num_rows * sizeof(char *)) + 1);

	// Inizializza tutti i puntatori a NULL
	while (i < (int)num_rows)
	{
		 file->map_s->map_matrix[i] = NULL;
		 i++;
	}
	i = 0;
	
	int curr_ind = 0;
	int mp_ind = file->map_s->map_start_index;
	size_t buff_ind = 0;
	buff_len = 0;
	// printf("LEN-->%s\n", file->file_matrix[k]);
	printf("mp_INdex-->%d\n",mp_ind);
	printf("valore a cui punta mp_ind--->%s\n", file->file_matrix[mp_ind]);
	while (1)
	{
		buff_len = ft_strlen(file->file_matrix[mp_ind]);
		buff_ind = 0;

		printf("lunghezza stringa di adesso-->%ld\n", buff_len);
		if (buff_len > 113)
		{
			printf("stringa troppo lunga\n");
			break;
		}
		if (buff_len > sizeof(char *))
		{
			printf("string too long\n");
			return;
		}
		file->map_s->map_matrix[curr_ind] = malloc(buff_len * sizeof(char));
		while (buff_ind < buff_len)
		{
			file->map_s->map_matrix[curr_ind][buff_ind] = file->file_matrix[mp_ind][buff_ind];
			// printf("%c", file->map_s->map_matrix[curr_ind][buff_ind]);
			// printf("BUFF_IND-->%ld\n", buff_ind);
			
			buff_ind++;
		}
		// printf("\n");
		
			if (mp_ind == file->map_s->map_end_index)
				break;
		curr_ind++;
		mp_ind++;
		i++;
	}
	printf("VALORE IN MATRICE--->%s\n", file->map_s->map_matrix[curr_ind]);
	free_matrix(file->map_s->map_matrix);

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