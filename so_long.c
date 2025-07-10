/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:18:51 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 13:03:14 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_check(char **av, int ac)
{
	if (ac == 2)
	{
		if (ft_strstr(av[1], ".ber") == NULL)
			exit(1);
	}
	else
		exit(1);
}

int	whole_map_check(char **map)
{
	int	line_height;

	line_height = getting_line_height_copied(map);
	if (!valid_map_characters(map) \
		|| !is_rectangular(map) \
		|| !valid_walls(map, line_height) \
		|| map_elements_check(map, 'P') != 1 \
		|| map_elements_check(map, 'E') < 1 \
		|| map_elements_check(map, 'C') < 1 \
		|| !validate_path(map))
	{
		ft_putstr("Error\nInvalid Map");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		line_height;
	char	**map;

	args_check(av, ac);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line_height = getting_line_height(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	map = assigning_map_to_array(line_height, fd);
	close(fd);
	if (!map)
		return (1);
	if (!whole_map_check(map))
	{
		free_map_array(map);
		return (0);
	}
	game_main(map);
}
