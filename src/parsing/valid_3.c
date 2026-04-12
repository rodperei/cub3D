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
				game->player.x = x;
				game->player.y = y;
				orientation_player(&game->player, c);
				return (1);
			}
		}
	}
	return (0);
}
