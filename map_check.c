/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:52:58 by jissa             #+#    #+#             */
/*   Updated: 2025/07/10 16:27:06 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	line_len;
	int	i;

	line_len = custom_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (custom_strlen(map[i]) != line_len)
			return (0);
		i++;
	}
	return (1);
}

int	valid_map_characters(char **map)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	line_len = custom_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (j < line_len)
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_first_last(char **map, int line_height, int line_len)
{
	int	j;

	j = 0;
	while (map[0] && j < line_len)
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[line_height - 1] && j < line_len)
	{
		if (map[line_height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	valid_walls(char **map, int line_height)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = custom_strlen(map[i]);
	if (!check_first_last(map, line_height, line_len))
		return (0);
	i = 1;
	while (map[i] && i < line_height - 1)
	{
		if (map[i][0] != '1' || map[i][line_len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_elements_check(char **map, char element)
{
	int	count;
	int	line_len;
	int	i;
	int	j;

	count = 0;
	line_len = custom_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < line_len)
		{
			if (map[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
