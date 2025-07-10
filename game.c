/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:08:38 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 14:37:24 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit_tile(t_game *game)
{
	if (game->collected == game->total_collectibles)
	{
		ft_putstr("You WON!!!\n");
		cleanup_game(game);
		exit(0);
	}
}

void	try_move_character(t_game *game, int x, int y)
{
	char	**map;

	map = game->map;
	if (is_out_of_bounds(game, x, y) || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
	{
		map[y][x] = '0';
		game->collected++;
	}
	else if (map[y][x] == 'E')
	{
		handle_exit_tile(game);
		return ;
	}
	map[game->player_y][game->player_x] = '0';
	map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	game_rendering(game->map, game);
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 119 || keycode == 65362)
		try_move_character(game, game->player_x, game->player_y - 1);
	else if (keycode == 115 || keycode == 65364)
		try_move_character(game, game->player_x, game->player_y + 1);
	else if (keycode == 97 || keycode == 65361)
	{
		game->player_dir = 'L';
		try_move_character(game, game->player_x - 1, game->player_y);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		game->player_dir = 'R';
		try_move_character(game, game->player_x + 1, game->player_y);
	}
	else if (keycode == 65307)
		close_window(game);
	return (0);
}

void	init_game_struct(t_game *game, char **map, void *mlx)
{
	int	x;
	int	y;

	find_player_pos(map, &x, &y);
	game->mlx = mlx;
	game->tile_size = 64;
	game->map = map;
	game->player_x = x;
	game->player_y = y;
	game->player_dir = '\0';
	game->collected = 0;
	game->steps = 0;
	game->total_collectibles = getting_collectibles_num(map);
}

void	game_main(char **map)
{
	t_game	*game;
	void	*mlx;
	void	*win;
	int		map_height;

	mlx = mlx_init();
	map_height = getting_line_height_copied(map);
	game = malloc(sizeof(t_game));
	if (!game)
		return ;
	init_game_struct(game, map, mlx);
	game->win_width = custom_strlen(map[0]) * game->tile_size;
	game->win_height = map_height * game->tile_size;
	win = mlx_new_window \
		(mlx, game->win_width, game->win_height, "my first window");
	game->win = win;
	load_images(game);
	game_rendering(map, game);
	mlx_key_hook(win, key_handler, game);
	mlx_hook(win, 17, 0, close_window, game);
	mlx_loop(mlx);
}
