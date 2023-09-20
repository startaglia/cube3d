#include "cub3d.h"

static void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_map(t_game *game)
{
	free_matrix(game->map->map);
    free(game->map);
}