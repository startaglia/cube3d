# include "../includes/cube3d.h"

void	init_structs(t_cubfile *file, char *str)
{
	file->map_s = malloc(sizeof(t_map));
	if (file->map_s == NULL)
	{
    	print_err(MEM_ERROR);
    	exit(1);
	}
	file->buff_str = malloc(100000);
	if (file->buff_str == NULL)
	{
    	print_err(MEM_ERROR);
    	exit(1);
	}
	file->lines = 0;
	file->matrix_start_index = 0;
	file->matrix_end_index = 0;
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
	file->NO_flag = 0;
	file->SO_flag = 0;
	file->WE_flag = 0;
	file->EA_flag = 0;
	file->F_flag = 0;
	file->C_flag = 0;

	file->map_s->map_start_index = 0;
	file->map_s->map_end_index = 0;
	file->map_s->or_dir = 0;
	file->map_s->or_coming_dir = 0;
	file->map_s->ver_dir = 0;
	file->map_s->ver_coming_dir = 0;
	file->map_s->flying_pipe = 0;


	file->first_RGB_num = 0;
	file->second_RGB_num = 0;
	file->third_RGB_num = 0;
	
	file->file_path = ft_strjoin("./level/", str);
	file->fd_open = 0;
	file->fd_read = 0;
}