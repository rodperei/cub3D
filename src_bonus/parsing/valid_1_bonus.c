/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_1_bonus.c                                          :+:      :+:    :+:   */
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
	if (len_all(rgb) != 3 || color[0] != -1 || color[1] != -1 || color[2] != -1)
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
			if (contains(lines[y], ',') != 2 && (equal(line[0], "F") \
|| equal(line[0], "C")))
				exit_color(lines, line);
			if (equal(line[0], "F") && !parse_color(line[1], def->floor_color))
				exit_color(lines, line);
			if (equal(line[0], "C") \
&& !parse_color(line[1], def->ceiling_color))
				exit_color(lines, line);
		}
		free_all(line);
	}
	return (1);
}

int	parse_path(char **lines, t_defs *def)
{
	int		y;
	int		ok;
	char	**line;

	ok = 1;
	line = NULL;
	y = -1;
	while (++y < len_all(lines) && ok)
	{
		line = ft_split_is_space(lines[y]);
		if (len_all(line) == 2)
			ok = parse_path_key(line[0], line[1], def);
		free_all(line);
		line = NULL;
	}
	return (ok);
}
