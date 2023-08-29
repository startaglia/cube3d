#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct cubfile
{
	char 	**file_matrix;
	char	*file_path;
	char	*buff;

	int		fd_open;
	int		fd_read;
	int		matrix_start_index;
	int		matrix_end_index;
	int		map_start_index;
	int		map_end_index;

	
	char *mapeltype[5];
	

} t_cubfile;

#endif