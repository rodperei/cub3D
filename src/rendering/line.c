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

float	fixed_distance(t_entity player, float x2, float y2)
{
	float	delta_x;
	float	delta_y;
	float	angle;

	delta_x = x2 - player.x;
	delta_y = y2 - player.y;
	angle = atan2f(delta_y, delta_x) - player.angle;
	return (distance(delta_x, delta_y) * cosf(angle));
}



void	draw_3d(t_game *game, t_ray ray, int i)
{
	int		j;
	float	height;
	int		start_y;
	int		end;

	height = (BLOCK / fixed_distance(game->player, ray.x, ray.y)) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	j = -1;
	// Mudar a cor do loop para a cor do teto
	while (++j < start_y)
		put_pixel(i, j, 0xFF, &game->img);
	while (start_y < end)
	{
		put_pixel(i, start_y, 0xFF00, &game->img);
		//copy_texture();
		start_y++;
	}
	start_y--;
	// Mudar a cor do loop para a cor do chão
	while (++start_y < HEIGHT)
		put_pixel(i, start_y, 0xFF0000, &game->img);
}

char	touch(float px, float py, t_map map)
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
