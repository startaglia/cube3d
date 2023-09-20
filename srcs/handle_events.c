#include "cub3d.h"

int	clean_exit(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(0);
	return (0);
}

int	handle_key_down(int key, t_game *game)
{
	if (!ft_strncmp("", "inputs", 6))
		ft_printf("key down: %d\n", key);
	if (key == 13 || key == 119)
		game->player.mov_dir.x = -1;
	else if (key == 1 || key == 115)
		game->player.mov_dir.x = 1;
	else if (key == 0 || key == 97)
		game->player.mov_dir.y = -1;
	else if (key == 2 || key == 100)
		game->player.mov_dir.y = 1;
	else if (key == 123 || key == 65361)
		game->player.rot_dir = -1;
	else if (key == 124 || key == 65363)
		game->player.rot_dir = 1;
	else if (key == 53 || key == 65307)
		clean_exit(game);
	return (0);
}

int handle_key_up(int key, t_game *game)
{
	if (!ft_strncmp("", "inputs", 6))
		ft_printf("key up: %d\n", key);
	if (key == 13 || key == 1 || key == 119 || key == 115)
		game->player.mov_dir.x = 0;
	else if (key == 0 || key == 2 || key == 97 || key == 100)
		game->player.mov_dir.y = 0;
	else if (key == 123 || key == 124
		|| key == 65361 || key == 65363)
		game->player.rot_dir = 0;
	return (0);
}