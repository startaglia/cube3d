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

void		init_player_and_textures(t_game *game);
void		free_map(t_game *game);
u_int64_t	get_time(void);
void		ft_sleep(u_int64_t time);
int			handle_key_up(int key, t_game *game);
int			handle_key_down(int key, t_game *game);
int			clean_exit(t_game *game);
int			update(t_game *game);
void		casting_ray(t_game *game);
void    	render_line(t_game *game, int x);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		draw_line_on(t_image *img, t_vec2 begin, t_vec2 end, int color);
// void		update_player(t_game *game);

# endif