/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color_line(char **lines, t_map *map)
{
	int		y;
	char	**line;

	y = -1;
	while (++y <= len_all(lines))
	{
		line = ft_split(lines[y], ' ');
		if (len_all(line) == 2)
		{
			if (equal(line[0], "F") && !parse_color(line[1], map->floor_color))
			{
				free_all(lines);
				free_all(line);
				death("Error\nInvalid floor color format", 1);
			}
			else if (equal(line[0], "C") \
&& !parse_color(line[1], map->ceiling_color))
			{
				free_all(lines);
				free_all(line);
				death("Error\nInvalid ceiling color format", 1);
			}
		}
		free_all(line);
	}
	return (1);
}

int	parse_path(char **lines, t_map *map)
{
	int		x;
	int		y;
	char	**line;

	x = 0;
	y = 0;
	while (y <= len_all(lines))
	{
		line = ft_split(lines[y], ' ');
		if (len_all(line) == 2)
		{
			if (equal(line[0], "NO"))
				strcpy(map->north_wall_texture, line[1]);
			else if (equal(line[0], "SO"))
				strcpy(map->south_wall_texture, line[1]);
			else if (equal(line[0], "WE"))
				strcpy(map->west_wall_texture, line[1]);
			else if (equal(line[0], "EA"))
				strcpy(map->east_wall_texture, line[1]);
		}
		free_all(line);
		y++;
	}
	return (1);
}

int	valid_map(char *path, t_map	*map)
{
	char	**lines;

	if (!check_ext(path))
		death("Error\nInvalid file extension. Expected .cub", 1);
	if (!exist_file(path))
		death("Error\nFailed to open file", 1);
	lines = read_file(open(path, O_RDONLY), '\n');
	if (!lines)
		death("Error\nFailed to read file", 1);
	parse_path(lines, map);
	parse_color_line(lines, map);
	free_all(lines);
	check_path(map);
	return (1);
}
