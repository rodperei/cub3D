/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:47:53 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 01:51:36 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubo3D.h>
#include "../include/utils.h"
#include "include/projection.h"

int	convert_color(int *rgb)
{
	int	color;

	color = 0;
	color = (rgb[0] << 16) & 0xff0000;
	color += rgb[1] << 8 & 0x00ff00;
	color += rgb[2] & 0xff;
	return (color);
}

void	paint_surface(t_img *frame, t_ival s, int color, int i)
{
	while (s.start < s.end)
	{
		put_pixel(i, s.start, color, frame);
		s.start++;
	}
}

void	draw_3d(t_defs *game, t_ray ray, int i)
{
	float	height;
	t_ival	wall;
	t_ival	tmp;

	height = (BLOCK / fixed_distance(game->player, ray.x, ray.y)) * (WIDTH / 2);
	wall.start = (HEIGHT - height) / 2;
	wall.end = wall.start + height;
	tmp.start = 0;
	tmp.end = wall.start;
	paint_surface(&game->frame, tmp, convert_color(game->ceiling_color), i);
	paint_wall(game, ray, wall, i);
	tmp.start = wall.end - 1;
	tmp.end = HEIGHT;
	paint_surface(&game->frame, tmp, convert_color(game->floor_color), i);
}
