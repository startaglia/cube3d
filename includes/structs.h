#ifndef STRUCTS_H
# define STRUCTS_H

/*directions:
or--> orizontal
ver--> vertical
or_dir == 0 --> from left to right
or_dir == 1 --> from right to left
ver_dir == 0 --> from top to bottom
ver_dir == 1 --> from bottom to top

coming dir
or_coming_dir == 0 ---> left
or_coming_dir == 1 ---> right
ver_coming_dir == 0 ---> top
ver_coming_dir == 1 ---> bottom

-1 value -->none
*/


typedef	struct s_value
{
	int	left_top_right_bott_ed;
	int	left_top_right_ed;
	int	left_bott_right_ed;
	int	top_right_bott_ed;
	int	left_right_ed;
	int	top_left_ed;
	int	top_right_ed;
	int	top_bott_ed;
	int	right_bott_ed;
	int	left_bott_ed;
	int	top_ed;
	int	right_ed;
	int	bott_ed;
	int	left_ed;
	int	or_dir;
	int	ver_dir;
	int	or_coming_dir;
	int	ver_coming_dir;
}	t_value;

typedef struct s_map
{
	char 	**map_matrix;
	int		map_start_index;
	int		map_end_index;
	int		map_widht;
	int		map_height;
	int		*check_start_coord;
	int		*check_curr_ind_coord;
	int		convex_corner;
	int		concave_corner;
	int		flat_corner;
	// int		*check_end_coord;
	t_value	*value_s;
	
} t_map;
typedef struct cubfile
{
	char 	**file_matrix;
	char	*file_path;
	char	*buff_str;
	char	*str;
	int		lines;
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
	t_map	*map_s;
} t_cubfile;



#endif