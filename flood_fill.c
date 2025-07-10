/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:04 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 16:24:33 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

char	**map_copy(char **map)
{
	int		i;
	int		height;
	char	**copy;

	i = 0;
	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	find_player_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	line_length;

	i = 0;
	j = 0;
	line_length = custom_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (j < line_length)
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x_pos, int y_pos, t_flood_data *data)
{
	char	visited;

	visited = 'V';
	if (x_pos < 0 || y_pos < 0 || y_pos >= data->height || x_pos >= data->width)
		return ;
	if (map[y_pos][x_pos] == '1')
		return ;
	else if (map[y_pos][x_pos] == visited)
		return ;
	else if (map[y_pos][x_pos] == 'C')
		data->collectibles_found++;
	else if (map[y_pos][x_pos] == 'E')
		data->exit_reached = 1;
	map[y_pos][x_pos] = visited;
	flood_fill(map, x_pos + 1, y_pos, data);
	flood_fill(map, x_pos - 1, y_pos, data);
	flood_fill(map, x_pos, y_pos + 1, data);
	flood_fill(map, x_pos, y_pos - 1, data);
}

int	run_flood_fill(char **copied_map, int expected_collec)
{
	int				player_x;
	int				player_y;
	t_flood_data	*data;
	int				result;

	data = malloc(sizeof(t_flood_data));
	if (!data)
		return (0);
	data->collectibles_found = 0;
	data->exit_reached = 0;
	data->width = custom_strlen(copied_map[0]);
	data->height = getting_line_height_copied(copied_map);
	find_player_pos(copied_map, &player_x, &player_y);
	flood_fill(copied_map, player_x, player_y, data);
	result = (expected_collec == data->collectibles_found && \
data->exit_reached == 1);
	free(data);
	return (result);
}

int	validate_path(char **map)
{
	int		expected_collec;
	char	**copied_map;
	int		is_valid;

	expected_collec = getting_collectibles_num(map);
	copied_map = map_copy(map);
	if (!copied_map)
		return (0);
	is_valid = run_flood_fill(copied_map, expected_collec);
	free_map_array(copied_map);
	return (is_valid);
}
