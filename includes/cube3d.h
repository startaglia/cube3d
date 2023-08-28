
// INCLUDE
# include "structs.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>

//MACROS
//ERRORS
# define ERROR "Error\n"
# define ARG_ERR "The arguments must be two\n"
# define EXT_FILE_ERR "The file must be a .cub type\n"
# define ELEMENT_SYNT_ERR "Invalid element syntax\n"
# define RGB_RANGE_ERR "out or RGB range\n"
# define MAP_POS_ERR "The map must be the last element on file\n"
# define MAP_VAL_ERR "Invalid value inside the map\n"
# define MAP_CLOSURE_ERR "The map must be surronded by walls\n"

//FUNCTIONS
void	print_err(char *err);
void	check_map(char **av);