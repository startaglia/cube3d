#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_map
{
	char 	**map_matrix;
	int		map_start_index;
	int		map_end_index;
	int		map_widht;
	int		map_height;
	int		or_dir;
	int		ver_dir;
	int		or_coming_dir;
	int		ver_coming_dir;
	int		flying_pipe;
	
} t_map;
typedef struct cubfile
{
	char 	**file_matrix;
	char	*file_path;
	char	*buff_str;
	char	*str;

	int		lines;

	t_map	*map_s;
	int		fd_open;
	int		fd_read;
	int		matrix_start_index;
	int		matrix_end_index;
	int		F_text_index;
	int		F_text_y;
	int		C_text_index;
	int		C_text_y;
	int		NO_text_index;
	int		NO_text_y;
	int		SO_text_index;
	int		SO_text_y;
	int		WE_text_index;
	int		WE_text_y;
	int		EA_text_index;
	int		EA_text_y;
	int		NO_flag;
	int		SO_flag;
	int		EA_flag;
	int		WE_flag;
	int		F_flag;
	int		C_flag;
	int		first_RGB_num;
	int		second_RGB_num;
	int		third_RGB_num;
} t_cubfile;



#endif