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

void	move_player(t_player *player)
{
	int		speed;
	float	angle_speed;

	speed = 4;
	angle_speed = 0.06;
	rotate_player(player, angle_speed);
	translate_vertical(player, speed);
	translate_horizontal(player, speed);
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
	/*Esta função será modificada para ser capaz de desenhar mapas não
	 quadrados*/
	t_map	map;
	int		x;
	int		y;

	map = game->map;
	x = -1;
	while (++x < map.lines)
	{
		y = -1;
		while (++y < map.cols)
		{
			if (map.map[x][y] == 1)
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0xDEDEDE, game);
			else
				draw_square(x * BLOCK, y * BLOCK, BLOCK, 0x545454, game);
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
	t_player	*player;
	float		offset;
	float		start_x;
	int			i;

	player = &game->player;
	move_player(player);
	clear_image(&game->img);
	if (DEBUG)
	{
		draw_map(game);
		draw_square(player->x, player->y, 10, 0xDBBD12, game);
	}
	offset = PI / 3 / WIDTH;
	start_x = game->player.angle - PI / 6;
	i = -1;
	while (++i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += offset;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.inst, 0, 0);
	return (0);
}
