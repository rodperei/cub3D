/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:45:23 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 17:13:41 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubo3D.h"
#include "include/rendering.h"
#include "include/utils.h"
#include "../../lib/minilibx-linux/mlx.h"

static void	move_player(t_defs *game)
{
	int						speed;
	float					angle_speed;
	int						modifier;

	modifier = calc_elapsed_time();
	speed = 0.2 * modifier + 3;
	angle_speed = 0.03 * modifier;
	rotate_player(&game->player, angle_speed);
	translate_vertical(game, speed);
	translate_horizontal(game, speed);
}

void	clear_image(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			put_pixel(j, i, 0x000000, img);
	}
}

void	draw_map(t_defs *game)
{
	t_map	map;
	t_pos	pos;
	t_pos	tmp;

	map = game->map;
	pos.x = -1;
	while (++(pos.x) < map.lines)
	{
		pos.y = -1;
		while (++(pos.y) < map.cols)
		{
			tmp.x = pos.x * BLOCK;
			tmp.y = pos.y * BLOCK;
			if (map.map[pos.x][pos.y] == '1')
				draw_square(tmp, BLOCK, 0xDEDEDE, game);
			else if (map.map[pos.x][pos.y] == '0')
				draw_square(tmp, BLOCK, 0x545454, game);
		}
	}
}

void	cast_ray(t_defs *game, float angle, int i, int color)
{
	t_ray	h_isect;
	t_ray	v_isect;
	float	h_dist;
	float	v_dist;

	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	h_isect = calc_horizontal_isect(*game, angle);
	v_isect = calc_vertical_isect(*game, angle);
	h_dist = distance(h_isect.x - game->player.x, h_isect.y - game->player.y);
	v_dist = distance(v_isect.x - game->player.x, v_isect.y - game->player.y);
	if (h_dist > v_dist && DEBUG)
		draw_line(game, v_isect, color);
	else if (DEBUG)
		draw_line(game, h_isect, color);
	else if (h_dist > v_dist && !DEBUG)
		draw_3d(game, v_isect, i);
	else if (!DEBUG)
		draw_3d(game, h_isect, i);
}

int	draw_loop(t_defs	*game)
{
	float		offset;
	float		start_x;
	int			i;
	t_pos		pos;

	move_player(game);
	clear_image(&game->frame);
	pos.x = game->player.x;
	pos.y = game->player.y;
	if (DEBUG)
	{
		draw_map(game);
		draw_square(pos, 10, 0xDBBD12, game);
	}
	offset = PI / 3 / WIDTH;
	start_x = game->player.angle - PI / 6;
	i = -1;
	while (++i < WIDTH)
	{
		cast_ray(game, start_x, i, 0xFF0000);
		start_x += offset;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame.inst, 0, 0);
	return (0);
}
