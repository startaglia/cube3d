#ifndef CUBE3D_H
# define CUBE3D_H

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
# define MEM_ERROR "Memory allocation failed\n"
# define OPEN_ERROR "File opening failed\n"
# define READ_ERROR "File reading failed\n"
# define ARG_ERR "The arguments must be two\n"
# define EXT_FILE_ERR "The file must be a .cub type\n"
# define IDENTIFIER_SYNT_ERR "Invalid identifier syntax\n"
# define MISSING_IDENTIFIER_ERR "Missing identifier\n"
# define MORE_IDENTIFIER_ERR "Identifier must be one per type\n"
# define RGB_VALUES_NUM "The RGB values must be 3\n"
# define RGB_VALUE_ERR "Invalid RGB value\n"
# define RGB_RANGE_ERR "out or RGB range\n"
# define MAP_POS_ERR "The map must be the last element on file\n"
# define MAP_VAL_ERR "Invalid value inside the map\n"
# define MAP_CLOSURE_ERR "The map must be surronded by walls\n"






//FUNCTIONS
void		print_err(char *err);
void		check_file(t_cubfile *file, char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
void		free_matrix(char **matrix);
void		print_matrix(char **matrix);
void		print_matrix_char(char **matrix);
void		init_structs(t_cubfile *file, char *str);
char		**init_matrix_null(char **matrix, int	len);
void		where_is_map(t_cubfile *file);
void		check_indexes(t_cubfile *file);
void		check_RGB_values(t_cubfile *file);
int			ft_atoi(char *str);
int			ft_isprint(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		matrix_map(t_cubfile *file);
int			ft_isascii(int c);
int			ft_strempt(char *s);
int			matrix_lenght(char	**matrix);
void		check_id_values(t_cubfile *file);
int			ft_strempt(char *s);
void		surrounded_map_check(t_cubfile *file);
int			converter_tab_space(t_cubfile *file, int i, int j, int k);
int			left_top_right_ed(t_cubfile *file, int i, int j);
int			left_bott_right_ed(t_cubfile *file, int i, int j);
int			top_right_bott_ed(t_cubfile *file, int i, int j);
int			left_right_ed(t_cubfile *file, int i, int j);
int			top_left_ed(t_cubfile *file, int i, int j);
int			top_right_ed(t_cubfile *file, int i, int j);
int			top_bott_ed(t_cubfile *file, int i, int j);
int			right_bott_ed(t_cubfile *file, int i, int j);
int			left_bott_ed(t_cubfile *file, int i, int j);
int			top_ed(t_cubfile *file, int i, int j);
int			right_ed(t_cubfile *file, int i, int j);
int			bott_ed(t_cubfile *file, int i, int j);
int			left_ed(t_cubfile *file, int i, int j);
int			bottom_edge(t_cubfile *file, int i, int j);
int			left_edge(t_cubfile *file, int i, int j);
int			print_flags(t_value *value_s);
int			left_top_right_bot_ed(t_cubfile *file, int i, int j);
int			reset_ed_flags(t_cubfile *file);

int			top_ed_cond(t_cubfile *file, int i, int j);
int			right_ed_cond(t_cubfile *file, int i, int j);
#endif