
#include "so_long.h"

void    close_game(t_game *game)
{
    free_all(game);
    exit(0);
}

void	free_all(t_game *game)
{
	if (game->allocate_img == 1)
	{
		free(game->mlx_ptr);
		free(game->win_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->item.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_close.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->obstacles.xpm_ptr);
	}
	if (game->map.allocate_map == 1)
		free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game);
}

void    ft_error(t_game *game, char *string)
{
	free_all(game);
	ft_printf("%s", string);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
    {
		free(game->map.full_map[i]);
		i++;
	}
	free(game->map.full_map);
	return ;
}
