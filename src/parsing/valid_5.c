/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	player_in_map(t_defs *game)
{
	int	y;
	int	x;

	y = game->player.x;
	x = game->player.y;
	if (up(game->map.map, y, x) == ' ' || down(game->map.map, y, x) == ' ' \
|| left(game->map.map, y, x) == ' ' || right(game->map.map, y, x) == ' ')
		return (0);
	return (1);
}

int	cont_player_in_map(t_defs *game)
{
	char	**map;
	int		a_n;
	int		a_s;
	int		a_e;
	int		a_w;

	map = game->map.map;
	a_n = len_mat(map, 'N');
	a_s = len_mat(map, 'S');
	a_e = len_mat(map, 'E');
	a_w = len_mat(map, 'W');
	return (a_n + a_s + a_e + a_w);
}

int	valid_caracters(t_defs *game)
{
	int		y;
	int		x;
	char	**map;

	map = game->map.map;
	y = -1;
	while (++y != len_all(map))
	{
		x = -1;
		while ((size_t)++x != strlen(map[y]))
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ' \
&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W')
				return (0);
		}
	}
	return (1);
}

int	copy_path(char *dest, char *src)
{
	if (dest[0] != '\0')
		return (0);
	strcpy(dest, src);
	return (1);
}

int	map_is_last(char *line)
{
	int	x;

	x = strlen(line) - 1;
	if (line[x] == '1' || line[x] == '0' || line[x] == ' ' || line[x] == 'N' \
|| line[x] == 'S' || line[x] == 'E' || line[x] == 'W')
		return (1);
	if (x > 1 && line[x - 1] != '\n' && line[x] == '\n')
		return (1);
	return (0);
}
