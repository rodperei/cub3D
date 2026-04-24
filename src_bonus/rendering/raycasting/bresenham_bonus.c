/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:31:37 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 01:35:05 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubo3D.h>
#include "../include/utils.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	calc_step(int n1, int n2)
{
	if (n1 < n2)
		return (1);
	return (-1);
}

void	draw_line(t_defs *game, t_ray ray, int color)
{
	t_pos	curr;
	t_pos	d;
	int		err;

	curr.x = game->player.x;
	curr.y = game->player.y;
	d.x = ft_abs((int)ray.x - curr.x);
	d.y = -ft_abs((int)ray.y - curr.y);
	err = d.x + d.y;
	while (1)
	{
		put_pixel(curr.x, curr.y, color, &game->frame);
		if (curr.x == (int)ray.x && curr.y == (int)ray.y)
			break ;
		if ((2 * err) >= d.y)
		{
			err += d.y;
			curr.x += calc_step(curr.x, ray.x);
		}
		if ((2 * err) <= d.x)
		{
			err += d.x;
			curr.y += calc_step(curr.y, ray.y);
		}
	}
}
