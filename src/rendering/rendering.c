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

	speed = 4;
	angle_speed = 0.06;
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

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	ray_x;
	float	ray_y;

	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, game->map.map))
	{
		if (DEBUG)
			put_pixel(ray_x, ray_y, 0xFF0000, &game->img);
		ray_x += cosf(start_x);
		ray_y += sinf(start_x);
	}
	if (!DEBUG)
		draw_3d(game, ray_x, ray_y, i);
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
		draw_line(&game->player, game, start_x, i);
		start_x += offset;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.inst, 0, 0);
	return (0);
}
