/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	max_line_len(char **lines)
{
	int	y;
	int	max_len;

	y = 0;
	max_len = 0;
	while (lines && lines[y])
	{
		if ((int)strlen(lines[y]) > max_len)
			max_len = strlen(lines[y]);
		y++;
	}
	return (max_len);
}

static char	**transpose_map(char **lines)
{
	char	**result;
	int		old_rows;
	int		new_rows;
	int		x;
	int		y;

	old_rows = len_all(lines);
	new_rows = max_line_len(lines);
	result = z_maloc_matriz(new_rows);
	x = -1;
	while (++x < new_rows)
	{
		result[x] = z_maloc(old_rows + 1);
		y = -1;
		while (++y < old_rows)
		{
			if ((size_t)x < strlen(lines[y]) && lines[y][x] != '\n')
				result[x][y] = lines[y][x];
			else
				result[x][y] = ' ';
		}
		result[x][y] = '\0';
	}
	return (result);
}

void	load_map(t_defs *game, char **lines)
{
	char	**transposed;

	transposed = transpose_map(lines);
	free_all(lines);
	lines = transposed;
	game->map.map = lines;
	game->map.lines = len_all(lines);
	game->map.cols = max_line_len(lines);
}

void	orientation_player(t_entity *player, char c)
{
	if (c == 'N')
		player->angle = NORT_RAD;
	else if (c == 'S')
		player->angle = SOUTH_RAD;
	else if (c == 'E')
		player->angle = EAST_RAD;
	else if (c == 'O')
		player->angle = WEST_RAD;
}

int	shear_player(t_defs *game)
{
	int		y;
	int		x;
	char	c;
	char	**map;

	y = -1;
	map = game->map.map;
	while (++y != len_all(map))
	{
		x = -1;
		while (map[y] && (size_t)++x != strlen(map[y]))
		{
			c = map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
			{
				map[y][x] = FLOOR;
				game->player.x = y;
				game->player.y = x;
				orientation_player(&game->player, c);
				return (1);
			}
		}
	}
	return (0);
}
