/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:57:37 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 13:03:49 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_idle_player = mlx_xpm_file_to_image \
	(game->mlx, "images/player_on_wall.xpm", &width, &height);
	game->img_left_player = mlx_xpm_file_to_image \
	(game->mlx, "images/player_left.xpm", &width, &height);
	game->img_right_player = mlx_xpm_file_to_image \
	(game->mlx, "images/player_right.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image \
	(game->mlx, "images/floor.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image \
	(game->mlx, "images/wall.xpm", &width, &height);
	game->img_collectible = mlx_xpm_file_to_image \
	(game->mlx, "images/collectibles.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image \
	(game->mlx, "images/door.xpm", &width, &height);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x, y);
	else if (tile == 'P')
	{
		if (game->player_dir == 'L')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_left_player, x, y);
		else if (game->player_dir == 'R')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_right_player, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_idle_player, x, y);
	}
	else if (tile == 'C')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img_collectible, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img_exit, x, y);
}

void	game_rendering(char **map, t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	line_len;

	i = 0;
	line_len = custom_strlen(map[0]);
	while (map[i])
	{
		y = i * game->tile_size;
		j = 0;
		while (j < line_len)
		{
			x = j * game->tile_size;
			render_tile(game, x, y, map[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("Steps count: %d\n", game->steps);
}

int	is_out_of_bounds(t_game *game, int x, int y)
{
	int	line_len;
	int	map_height;

	line_len = custom_strlen(game->map[0]);
	map_height = getting_line_height_copied(game->map);
	return (x < 0 || x >= line_len || y < 0 || y >= map_height);
}
