#ifndef CUB3_D
# define CUB3_D

//  Libraries
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

//  Screen and player
# define FPS_LOCK 30
# define PLAYER_FOV 0.90
# define PLAYER_SPEED 3.0
# define PLAYER_ROTATION_SPEED 2.0
#define HEIGHT 720
#define WIDTH 1280
#define TEXTURE_SIZE 64

// MLX keys
# define K_Q 12
# define K_W 13
# define K_E 14
# define K_R 15
# define K_T 17
# define K_Y 16
# define K_U 32
# define K_I 34
# define K_O 31
# define K_P 35
# define K_A 0
# define K_S 1
# define K_D 2
# define K_F 3
# define K_G 5
# define K_H 4
# define K_J 38
# define K_K 40
# define K_L 37
# define K_Z 6
# define K_X 7
# define K_C 8
# define K_V 9
# define K_B 11
# define K_N 45
# define K_M 46
# define K_ESCAPE 53
# define K_ENTER 36
# define K_BACKSPACE 51
# define K_LEFT 123
# define K_RIGHT 124
# define K_DOWN 125
# define K_UP 126

// MLX Linux Keys
# define LK_W 119
# define LK_A 97
# define LK_S 115
# define LK_D 100
# define LK_LEFT 65361
# define LK_RIGHT 65363
# define LK_ESCAPE 65307

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;


typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_map
{
	t_vec2	player_pos;
	char	**map;
	char	*nord;
	char	*sud;
	char	*west;
	char	*east;
	int		floor_color[3];
	int		ceilling_color[3];
	int		width;
	int		height;
	int		floor;
	int		ceilling;
}	t_map;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	mov_dir;
	t_vec2	plane;	
	t_vec2	mov_speed;
	double	rot_speed;
	double	rot_dir;
}	t_player;

typedef struct s_raycaster
{
	t_vec2	ray_dir;
	t_vec2	side_dist;
	t_vec2	delta_dist;
	t_vec2	draw_start;
	t_vec2	draw_end;
	double	camera_x;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		color;
}	t_raycaster;

typedef struct s_game
{
	t_raycaster	ray;
	t_image		screen;
	t_image		walls[3];
	t_player	player;
	t_map		*map;
	u_int64_t	time;
	u_int64_t	old_time;
	void		*mlx;
	void		*win;
	double		frame_time;
	int			wall_widths[3];
	int			wall_heights[3];
	int			fps;

}	t_game;

// Time
u_int64_t	get_time(void);
void	ft_sleep(u_int64_t time);

// Free
void	free_map(t_game *game);
int	clean_exit(t_game *game);

//	Player and textures
void	init_player_and_textures(t_game *game);

//	Loop
int update(t_game *game);
int	handle_key_down(int key, t_game *game);
int	handle_key_up(int key, t_game *game);

//	Rendering
void    casting_ray(t_game *game);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_line_on(t_image *img, t_vec2 begin, t_vec2 end, int color);
int		create_trgb(int t, int r, int g, int b);
void    start_rendering(t_game *game, int x);

# endif