# include "../../includes/cube3d.h"

void	where_is_map(t_cubfile *file)
{
	printf("MAP END INDEX--> %d\t MATRIX END INDEX--> %d\n", file->map_s->map_end_index, file->matrix_end_index);
	int i;
	
	i = file->map_s->map_end_index;
	while (file->file_matrix[i])
	{
		if (ft_strempt(file->file_matrix[i]))
		{
			print_err(MAP_POS_ERR);
			free(file->file_path);
			free_matrix(file->file_matrix);
			exit(1);
		}
		i++;
	}
}