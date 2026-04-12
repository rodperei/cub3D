/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_ext(char *path)
{
	char	*ext;
	int		aux;

	if (!path || !*path)
		return (0);
	aux = strlen(path) - 4;
	ext = ".cub";
	if (aux == 0 || path[aux - 1] == '/')
		return (0);
	while (*ext)
	{
		if (*ext != path[aux])
			return (0);
		ext++;
		aux++;
	}
	return (1);
}

int	parse_color(char *str, int *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (len_all(rgb) != 3)
	{
		free_all(rgb);
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		color[i] = atoi(rgb[i]);
		if (color[i] < 0 || color[i] > 255 || !is_digit(rgb[i]))
		{
			free_all(rgb);
			return (0);
		}
		i++;
	}
	free_all(rgb);
	return (1);
}

void	check_path(t_defs *def)
{
	if (!exist_file(def->nw_tex.path))
		death("Error\nNorth wall texture file does not exist", 1);
	if (!exist_file(def->sw_tex.path))
		death("Error\nSouth wall texture file does not exist", 1);
	if (!exist_file(def->ww_tex.path))
		death("Error\nWest wall texture file does not exist", 1);
	if (!exist_file(def->ew_tex.path))
		death("Error\nEast wall texture file does not exist", 1);
}

int	parse_color_line(char **lines, t_defs *def)
{
	int		y;
	char	**line;

	y = -1;
	while (++y <= len_all(lines))
	{
		line = ft_split_is_space(lines[y]);
		if (len_all(line) == 2)
		{
			if (equal(line[0], "F") && !parse_color(line[1], def->floor_color))
			{
				free_all(lines);
				free_all(line);
				death("Error\nInvalid floor color format", 1);
			}
			if (equal(line[0], "C") \
&& !parse_color(line[1], def->ceiling_color))
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

int	parse_path(char **lines, t_defs *def)
{
	int		y;
	char	**line;

	y = 0;
	while (y <= len_all(lines))
	{
		line = ft_split_is_space(lines[y]);
		if (len_all(line) == 2)
		{
			if (equal(line[0], "NO"))
				strcpy(def->nw_tex.path, line[1]);
			else if (equal(line[0], "SO"))
				strcpy(def->sw_tex.path, line[1]);
			else if (equal(line[0], "WE"))
				strcpy(def->ww_tex.path, line[1]);
			else if (equal(line[0], "EA"))
				strcpy(def->ew_tex.path, line[1]);
		}
		free_all(line);
		y++;
	}
	return (1);
}
