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

void	check_path(t_map *map)
{
	if (!exist_file(map->north_wall_texture))
		death("Error\nNorth wall texture file does not exist", 1);
	if (!exist_file(map->south_wall_texture))
		death("Error\nSouth wall texture file does not exist", 1);
	if (!exist_file(map->west_wall_texture))
		death("Error\nWest wall texture file does not exist", 1);
	if (!exist_file(map->east_wall_texture))
		death("Error\nEast wall texture file does not exist", 1);
}
