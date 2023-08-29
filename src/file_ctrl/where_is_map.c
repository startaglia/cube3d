# include "../../includes/cube3d.h"

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