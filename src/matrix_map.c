# include "../includes/cube3d.h"

// void	get_map_sizes(t_cubfile *file)
// {
// 	int	i;
// 	int	j;
	
// 	i = file->map_s->map_start_index;
// 	while (i < file->map_s->map_end_index)
// 	{
// 		j = 0;
// 		while (file->file_matrix[i][j])
// 		{
// 			// printf("%c", file->file_matrix[i][j]);
// 			j++;
// 		}
// 		if (file->map_s->map_widht < j)
// 			file->map_s->map_widht = j;
// 		// printf("\t\t\tJ: %d\n", j);
// 		i++;
// 	}
// 	// printf("MAP WIDHT %d\n", file->map_s->map_widht);
	
// 	// file->map_s->map_widht = 
// }

// void	matrix_map(t_cubfile *file)
// {
// 	//sposto l'indice indietro di uno per poter fare la matrice
// 	file->map_s->map_end_index --;
// 	get_map_sizes(file);
// 	file->map_s->map_matrix = malloc((file->map_s->map_end_index - file->map_s->map_start_index) * sizeof(char));




// 	// print_matrix(file->map_s->map_matrix);




// 	// printf("PRIMA RIGA: %s\n", file->file_matrix[file->map_s->map_start_index]);
// 	// printf("ULTIMA RIGA: %s\n", file->file_matrix[file->map_s->map_end_index]);
// }