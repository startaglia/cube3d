# include "../includes/cube3d.h"

void	init_structs(t_cubfile *file, char *str)
{
	file->buff_str = malloc(100000);
	if (file->buff_str == NULL)
	{
    	print_err(MEM_ERROR);
    	exit(1);
	}
	file->map_s = malloc(sizeof(t_map));
	if (file->map_s == NULL)
	{
    	print_err(MEM_ERROR);
    	exit(1);
	}
	file->map_s->value_s = malloc(sizeof(t_value));
	if (file->map_s->value_s == NULL)
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

	file->first_RGB_num = 0;
	file->second_RGB_num = 0;
	file->third_RGB_num = 0;
	file->file_path = ft_strjoin("./level/", str);
	file->fd_open = 0;
	file->fd_read = 0;

	file->map_s->map_start_index = 0;
	file->map_s->map_end_index = 0;
	file->map_s->map_height = 0;
	file->map_s->check_start_coord = (int *)malloc(sizeof(int) * 2);
	file->map_s->check_start_coord[0] = 0; 
	file->map_s->check_start_coord[1] = 0;

	file->map_s->check_curr_ind_coord = (int *)malloc(sizeof(int) * 2);
	file->map_s->check_curr_ind_coord[0] = 0; 
	file->map_s->check_curr_ind_coord[1] = 0;
	file->map_s->convex_corner = 0;
	file->map_s->concave_corner = 0;
	
	file->map_s->value_s->or_dir = -1;
	file->map_s->value_s->or_coming_dir = -1;
	file->map_s->value_s->ver_dir = -1;
	file->map_s->value_s->ver_coming_dir = -1;
	file->map_s->value_s->left_top_right_ed = 0;
	file->map_s->value_s->left_bott_right_ed = 0;
	file->map_s->value_s->top_right_bott_ed = 0;
	file->map_s->value_s->left_right_ed = 0;
	file->map_s->value_s->top_left_ed = 0;
	file->map_s->value_s->top_right_ed = 0;
	file->map_s->value_s->top_bott_ed = 0;
	file->map_s->value_s->right_bott_ed = 0;
	file->map_s->value_s->left_bott_ed = 0;
	file->map_s->value_s->top_ed = 0;
	file->map_s->value_s->right_ed = 0;
	file->map_s->value_s->bott_ed = 0;
	file->map_s->value_s->left_ed = 0;


}