/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:25:38 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 15:36:02 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cubo3D.h>
#include "include/utils.h"

void	put_pixel(int x, int y, int color, t_img *img)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * img->len + x * img->bpp / 8;
	img->data[index] = color & 0xFF;
	img->data[index + 1] = (color >> 8) & 0xFF;
	img->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(t_pos pos, int size, int color, t_defs *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (i != 0 && j != 0 && i != (size - 1) && j != (size - 1))
				put_pixel(pos.x + j, pos.y + i, color, &game->frame);
			else
				put_pixel(pos.x + j, pos.y + i, 0x474747, &game->frame);
		}
	}
}

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
