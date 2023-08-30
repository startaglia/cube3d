# include "../includes/cube3d.h"

void	init_structs(t_cubfile *file, char *str)
{
	//!per avere la dimensione del contenuto del file prima di aprirlo esiste fseek(che non si può usare). sto usando uno spazio di 100000 che poi libero. Capire se può andare bene.
	file->matrix_start_index = 0;
	file->map_start_index = 0;
	file->matrix_end_index = 0;
	file->map_end_index = 0;
	file->F_text_index = 0;
	file->F_text_y = 0;
	file->C_text_index = 0;
	file->C_text_y = 0;
	file->NO_text_index = 0;
	file->NO_text_y = 0;
	file->SO_text_index = 0;
	file->SO_text_y = 0;
	file->WE_text_index = 0;
	file->WE_text_y = 0;
	file->EA_text_index = 0;
	file->EA_text_y = 0;
	file->NO_flag = false;
	file->SO_flag = false;
	file->WE_flag = false;
	file->EA_flag = false;
	file->F_flag = false;
	file->C_flag = false;

	file->first_RGB_num = 0;
	file->second_RGB_num = 0;
	file->third_RGB_num = 0;



	file->file_path = ft_strjoin("./level/", str);
	file->fd_open = 0;
	file->fd_read = 0;
	file->buff = malloc(100000);
}