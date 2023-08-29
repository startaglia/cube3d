# include "../includes/cube3d.h"

void	init_structs(t_cubfile *file, char *str)
{
	//!per avere la dimensione del contenuto del file prima di aprirlo esiste fseek(che non si può usare). sto usando uno spazio di 100000 che poi libero. Capire se può andare bene.
	file->matrix_start_index = 0;
	file->matrix_end_index = 0;
	file->file_path = ft_strjoin("./level/", str);
	file->fd_open = 0;
	file->fd_read = 0;
	file->buff = malloc(100000);
}