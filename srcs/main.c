#include "cub3d.h"

void   set_map(t_game *game)
{
    game->map = malloc (sizeof(t_map));
	game->map->nord = NULL;
	game->map->sud = NULL;
	game->map->west = NULL;
	game->map->east = NULL;
	game->map->floor_color[0] = -1;
	game->map->ceilling_color[0] = -1;
	game->map->player_pos.x = 0;
	game->map->player_pos.y = 0;
	game->map->map = NULL;
	game->map->width = 0;
	game->map->height = 0;
	game->map->floor = 0;
	game->map->ceilling = 0;
    game->map->map = malloc(sizeof(char *) * 15);
    game->map->map[0] = ft_strdup("           1111111111111111111111111");
    game->map->map[1] = ft_strdup("           1000000000110000000000001");
    game->map->map[2] = ft_strdup("           1011000001110000000000001");
    game->map->map[3] = ft_strdup("           1001000000000000000000111");
    game->map->map[4] = ft_strdup("111111111111000001110000000000001");
    game->map->map[5] = ft_strdup("100000000011000001110111101111111");
    game->map->map[6] = ft_strdup("11110111111111011100000010001");
    game->map->map[7] = ft_strdup("11110111111111011101010010001");
    game->map->map[8] = ft_strdup("11000000110101011100000010001");
    game->map->map[9] = ft_strdup("10000000000000001100000000001");
    game->map->map[10] = ft_strdup("10000000000000001101010010001");
    game->map->map[11] = ft_strdup("11000001110101011111011110N01");
    game->map->map[12] = ft_strdup("11110111 1110101 101111010001");
    game->map->map[13] = ft_strdup("11111111 1111111 111111111111");
    game->map->map[14] = '\0';
    game->map->nord = "./xpms/n_wall.xpm";
	game->map->sud = "./xpms/s_wall.xpm";
	game->map->west = "./xpms/w_wall.xpm";
	game->map->east = "./xpms/e_wall.xpm";
    game->map->ceilling_color[0] = 255;
    game->map->ceilling_color[1] = 100;
    game->map->ceilling_color[2] = 0;
    game->map->floor_color[0] = 225;
    game->map->floor_color[1] = 30;
    game->map->floor_color[2] = 0;
}

int main ()
{
    t_game   game;

    set_map(&game);
    init_player_and_textures(&game);
    mlx_hook(game.win, 2, 1L << 0, handle_key_down, (void *)&game);
	mlx_hook(game.win, 3, 1L << 1, handle_key_up, (void *)&game);
    mlx_hook(game.win, 17, 0, clean_exit, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
    mlx_loop(game.mlx);
    return (0);
}