/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:58:03 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 00:43:54 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

int	getting_line_height(int fd)
{
	char	*line;
	int		line_height;

	line_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		line_height++;
	}
	return (line_height);
}

int	getting_line_height_copied(char **map)
{
	int	line_height;

	line_height = 0;
	while (map[line_height])
	{
		line_height++;
	}
	return (line_height);
}

int	getting_collectibles_num(char **map)
{
	int	i;
	int	line_len;
	int	j;
	int	count;

	i = 0;
	line_len = custom_strlen(map[0]);
	count = 0;
	while (map[i])
	{
		j = 0;
		while (j < line_len)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**assigning_map_to_array(int line_height, int fd)
{
	char	**map;
	char	*line;
	int		i;
	int		len;

	map = malloc(sizeof(char *) * (line_height + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (i < line_height && line != NULL)
	{
		len = custom_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (i != line_height)
	{
		free_map_array(map);
		return (NULL);
	}
	return (map);
}
