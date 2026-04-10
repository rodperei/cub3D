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

#include <math.h>
#include <cubo3D.h>
#include "include/rendering.h"
#include "include/utils.h"
#include "../../lib/minilibx-linux/mlx.h"

void	move_player(t_game *game)
{
	int		speed;
	float	angle_speed;

	speed = 3;
	angle_speed = 0.01;
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

void	draw_map(t_game *game)
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

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calc_step(int n1, int n2)
{
	if (n1 < n2)
		return (1);
	return (-1);
}

void draw_ray(t_game *game, t_ray ray, int color)
{
	t_pos	curr;
	t_pos	d;
    int err;

	curr.x = game->player.x;
	curr.y = game->player.y;
	d.x = ft_abs((int)ray.x - curr.x);
	d.y = -ft_abs((int)ray.y - curr.y);
	err = d.x + d.y;
    while (1)
    {
		put_pixel(curr.x, curr.y, color, &game->img);
        if (curr.x == (int)ray.x && curr.y == (int)ray.y)
            break;
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

void	calc_first_hisect(t_entity player, t_ray *ix)
{
	float arc_tan;

	arc_tan = -1 / tanf(ix->angle);
	if (ix->angle > 0 && ix->angle < PI)
	{
		ix->y = floorf((player.y / BLOCK)) * BLOCK + BLOCK;
		ix->orientation = NORTH;
	}
	else
	{
		ix->y = floorf((player.y / BLOCK)) * BLOCK - 1;
		ix->orientation = SOUTH;
	}
	ix->x = (player.y - ix->y) * arc_tan + player.x;
}

t_ray	calc_horizontal_isect(t_game game, float angle)
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
	while (ix.x >= 0  && ix.x <= WIDTH && ix.y >= 0 && ix.y <= HEIGHT)
	{
		if (touch(ix.x, ix.y, game.map))
			break ;
		ix.y += y_step;
		ix.x += x_step;
	}
	return (ix);
}

void calc_first_visect(t_entity player, t_ray *ix)
{
	if (ix->angle > PI / 2 && ix->angle < (3 * PI) / 2)
	{
		ix->x = floorf((player.x / BLOCK)) * BLOCK - 1;
		ix->orientation = EAST;
	}
	else
	{
		ix->x = floorf((player.x / BLOCK)) * BLOCK + BLOCK;
		ix->orientation = WEST;
	}
	ix->y = player.y + (player.x - ix->x) * -tanf(ix->angle);
}

t_ray	calc_vertical_isect(t_game game, float angle)
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
	while (ix.x >= 0  && ix.x <= WIDTH && ix.y >= 0 && ix.y <= HEIGHT)
	{
		if (touch(ix.x, ix.y, game.map))
			break ;
		ix.x += x_step;
		ix.y += y_step;
	}
	return (ix);
}

void	cast_ray(t_game *game, float angle, int i, int color)
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
		draw_ray(game, v_isect, color);
	else if (DEBUG)
		draw_ray(game, h_isect, color);
	else if (h_dist > v_dist && !DEBUG)
		draw_3d(game, v_isect, i);
	else if (!DEBUG)
		draw_3d(game, h_isect, i);
}

int	draw_loop(t_game	*game)
{
	float		offset;
	float		start_x;
	int			i;
	t_pos		pos;

	move_player(game);
	clear_image(&game->img);
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
	mlx_put_image_to_window(game->mlx, game->win, game->img.inst, 0, 0);
	return (0);
}
