/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:05:52 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 01:13:40 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cubo3D.h>
#include "../include/utils.h"

static char	touch(float px, float py, t_map map)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (x >= map.lines || y >= map.cols)
		return (1);
	if (map.map[x][y] == '1')
		return (1);
	return (0);
}

static void	calc_first_hisect(t_entity player, t_ray *ix)
{
	float	arc_tan;

	arc_tan = -1 / tanf(ix->angle);
	if (ix->angle > 0 && ix->angle < PI)
	{
		ix->y = floorf((player.y / BLOCK)) * BLOCK + BLOCK;
		ix->e_orientation = NORTH;
	}
	else
	{
		ix->y = floorf((player.y / BLOCK)) * BLOCK - 1;
		ix->e_orientation = SOUTH;
	}
	ix->x = (player.y - ix->y) * arc_tan + player.x;
}

t_ray	calc_horizontal_isect(t_defs game, float angle)
{
	t_ray	ix;
	float	y_step;
	float	x_step;

	ix.angle = angle;
	calc_first_hisect(game.player, &ix);
	if (angle > 0 && angle < PI)
		y_step = BLOCK;
	else
		y_step = -BLOCK;
	x_step = -y_step * (-1 / tanf(angle));
	while (ix.x >= 0 && ix.x <= WIDTH && ix.y >= 0 && ix.y <= HEIGHT)
	{
		if (touch(ix.x, ix.y, game.map))
			break ;
		ix.y += y_step;
		ix.x += x_step;
	}
	return (ix);
}

static void	calc_first_visect(t_entity player, t_ray *ix)
{
	if (ix->angle > PI / 2 && ix->angle < (3 * PI) / 2)
	{
		ix->x = floorf((player.x / BLOCK)) * BLOCK - 1;
		ix->e_orientation = EAST;
	}
	else
	{
		ix->x = floorf((player.x / BLOCK)) * BLOCK + BLOCK;
		ix->e_orientation = WEST;
	}
	ix->y = player.y + (player.x - ix->x) * -tanf(ix->angle);
}

t_ray	calc_vertical_isect(t_defs game, float angle)
{
	t_ray	ix;
	float	x_step;
	float	y_step;

	ix.angle = angle;
	calc_first_visect(game.player, &ix);
	if (angle > PI / 2 && angle < (3 * PI) / 2)
		x_step = -BLOCK;
	else
		x_step = BLOCK;
	y_step = -x_step * -tanf(angle);
	while (ix.x >= 0 && ix.x <= WIDTH && ix.y >= 0 && ix.y <= HEIGHT)
	{
		if (touch(ix.x, ix.y, game.map))
			break ;
		ix.x += x_step;
		ix.y += y_step;
	}
	return (ix);
}
