/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:38:41 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 17:12:38 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cubo3D.h>
#include "include/utils.h"

float	distance(float x, float y)
{
	return (sqrtf(x * x + y * y));
}

float	fixed_distance(t_player player, float x2, float y2)
{
	float	delta_x;
	float	delta_y;
	float	angle;

	delta_x = x2 - player.x;
	delta_y = y2 - player.y;
	angle = atan2f(delta_y, delta_x) - player.angle;
	return (distance(delta_x, delta_y) * cosf(angle));
}

void	draw_3d(t_game *game, float ray_x, float ray_y, int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;

	dist = fixed_distance(game->player, ray_x, ray_y);
	height = (BLOCK / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		put_pixel(i, start_y, 255, &game->img);
		start_y++;
	}
}

char	touch(float px, float py, char **map)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (map[x][y] == '1')
		return (1);
	return (0);
}
