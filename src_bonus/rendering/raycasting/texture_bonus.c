/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:38:41 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 01:58:49 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubo3D.h>
#include "../include/utils.h"
#include "include/projection.h"

int	calculate_texture_x(t_texture tex, t_ray ray)
{
	int		wall_x;
	int		tex_x;

	if (ray.e_orientation == EAST || ray.e_orientation == WEST)
	{
		wall_x = ray.y / BLOCK;
		wall_x = ray.y - (wall_x) * BLOCK;
	}
	else
	{
		wall_x = ray.x / BLOCK;
		wall_x = ray.x - (wall_x) * BLOCK;
	}
	tex_x = wall_x * (tex.width / BLOCK);
	if (ray.e_orientation == EAST || ray.e_orientation == NORTH)
		tex_x = tex.width - tex_x - 1;
	return (tex_x);
}

t_texture	choose_texture(t_defs game, t_ray ray)
{
	if (ray.e_orientation == NORTH)
		return (game.nw_tex);
	else if (ray.e_orientation == SOUTH)
		return (game.sw_tex);
	else if (ray.e_orientation == WEST)
		return (game.ww_tex);
	else
		return (game.ew_tex);
}

float	calc_texture_y(t_entity player, t_texture tex, t_ray ray, float *step)
{
	float	height;
	float	draw_start;

	height = (BLOCK / fixed_distance(player, ray.x, ray.y)) * (WIDTH / 2);
	*step = 1.0 * tex.height / height;
	draw_start = (HEIGHT - height) / 2;
	return ((draw_start - HEIGHT / 2.0 + height / 2.0) * *step);
}

void	copy_pixel(t_pos f_pos, t_pos t_pos, t_img *frame, t_texture tex)
{
	int	f_index;
	int	t_index;
	int	i;

	if (f_pos.x >= WIDTH || f_pos.y >= HEIGHT || f_pos.x < 0 || f_pos.y < 0)
		return ;
	if (t_pos.x >= tex.width || t_pos.y >= tex.height)
		return ;
	if (t_pos.x < 0 || t_pos.y < 0)
		return ;
	f_index = (f_pos.y * frame->len + f_pos.x * (frame->bpp / 8));
	t_index = (t_pos.y * tex.img.len + t_pos.x * (tex.img.bpp / 8));
	i = -1;
	while (++i < frame->bpp / 8)
		frame->data[f_index + i] = tex.img.data[t_index + i];
}

void	paint_wall(t_defs *game, t_ray ray, t_ival wall, int i)
{
	t_pos		tex_pos;
	t_texture	tex;
	float		step;
	float		tex_pixel;
	t_pos		frame_pos;

	tex = choose_texture(*game, ray);
	tex_pos.x = calculate_texture_x(tex, ray);
	tex_pixel = calc_texture_y(game->player, tex, ray, &step);
	frame_pos.x = i;
	while (wall.start < wall.end)
	{
		tex_pos.y = (int)tex_pixel & (tex.height - 1);
		tex_pixel += step;
		frame_pos.y = wall.start;
		copy_pixel(frame_pos, tex_pos, &game->frame, tex);
		wall.start++;
	}
}
