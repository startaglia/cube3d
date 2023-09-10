# include "../includes/cube3d.h"

void	matrix_map(t_cubfile *file)
{
	//iteratore ciclo fuori
	int curr_ind;
	//iteratore per la stringa di file.matrix
	int	map_ind;
	//altezza matrice
	size_t	num_rows;
	
	curr_ind = 0;
	map_ind = file->map_s->map_start_index;
	//calcolo l'altezza della matrice map e malloco mem
	num_rows = (((file->map_s->map_end_index) - (file->map_s->map_start_index)) - 1);
	file->map_s->map_matrix = malloc(((num_rows + 2) * sizeof(char *)));
	// Inizializza tutt a NULL
	file->map_s->map_matrix = init_matrix_null(file->map_s->map_matrix, num_rows);
	//riempio la matrix map
	while (curr_ind <= (int)num_rows)
	{
		file->map_s->map_matrix[curr_ind] = ft_substr(file->file_matrix[map_ind], 0, (ft_strlen(file->file_matrix[map_ind]) + 1));
		// printf("STRINGA DA COPIARE %s\n", file->file_matrix[map_ind]);
		// printf("STRINGA COPIATA %s\n", file->map_s->map_matrix[curr_ind]);
		file->map_s->map_matrix[curr_ind][ft_strlen(file->file_matrix[map_ind])] = 0;
		curr_ind++;
		map_ind++;
	}
	file->map_s->map_matrix[curr_ind] = 0;
	//mi salvo l'altezza della map matrix
	file->map_s->map_height = matrix_lenght(file->map_s->map_matrix);
}
