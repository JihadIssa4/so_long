/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:22:11 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 13:02:46 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "GNL/get_next_line.h"
# include "printf/includes/ft_printf.h"
# include "minilibx-linux/mlx.h"

typedef struct s_flood_data
{
	int	collectibles_found;
	int	exit_reached;
	int	width;
	int	height;
}	t_flood_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_idle_player;
	void	*img_left_player;
	void	*img_right_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	char	**map;
	int		tile_size;
	int		win_width;
	int		win_height;
	int		player_x;
	int		player_y;
	char	player_dir;
	int		collected;
	int		total_collectibles;
	int		steps;
}	t_game;

int		whole_map_check(char **map);
char	**assigning_map_to_array(int line_height, int fd);
int		map_elements_check(char **map, char element);
int		valid_walls(char **map, int line_height);
int		validate_path(char **map);
void	flood_fill(char **map, int x_pos, int y_pos, t_flood_data *data);
void	find_player_pos(char **map, int *x, int *y);
char	**map_copy(char **map);
int		valid_map_characters(char **map);
int		is_rectangular(char **map);
int		getting_collectibles_num(char **map);
int		getting_line_height_copied(char **map);
int		getting_line_height(int fd);
void	free_map_array(char **map);
void	game_main(char **map);
int		custom_strlen(char *str);
char	*ft_strstr(const char *big, const char *little);
void	ft_putstr(char *str);
int		run_flood_fill(char **copied_map, int expected_collec);
void	cleanup_game(t_game *game);
int		close_window(t_game *game);
void	load_images(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile);
void	game_rendering(char **map, t_game *game);
int		is_out_of_bounds(t_game *game, int x, int y);

#endif
