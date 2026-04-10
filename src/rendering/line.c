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

typedef struct	s_ival
{
	int	start;
	int	end;
}	t_ival;

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

int	calculate_texture_x(t_texture tex, t_ray ray)
{
	int		wall_x;
	int		tex_x;

	if (ray.orientation == EAST || ray.orientation == WEST)
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
	if (ray.orientation == EAST || ray.orientation == NORTH)
		tex_x = tex.width - tex_x - 1;
	return (tex_x);
}

t_texture	choose_texture(t_defs game, t_ray ray)
{
	if (ray.orientation == NORTH)
		return (game.north_wall_texture);
	else if (ray.orientation == SOUTH)
		return (game.south_wall_texture);
	else if (ray.orientation == WEST)
		return (game.west_wall_texture);
	else
		return (game.east_wall_texture);
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
	while (++i < 4)
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
