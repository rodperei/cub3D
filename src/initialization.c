/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:34:25 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 00:37:40 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cubo3D.h>
#include "../lib/minilibx-linux/mlx.h"

static void	init_player(t_entity *player)
{
	player->x = player->x * BLOCK - BLOCK / 2.0;
	player->y = player->y * BLOCK - BLOCK / 2.0;
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->left_rotate = 0;
	player->right_rotate = 0;
}

char	init_game(t_defs *game)
{
	t_img	tmp;

	init_player(&game->player);
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	if (!game->win)
		return (0);
	tmp.inst = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!tmp.inst)
		return (0);
	tmp.data = mlx_get_data_addr(tmp.inst, &tmp.bpp, &tmp.len, &tmp.end);
	game->frame.data = tmp.data;
	game->frame.inst = tmp.inst;
	game->frame.bpp = tmp.bpp;
	game->frame.end = tmp.end;
	game->frame.len = tmp.len;
	mlx_put_image_to_window(game->mlx, game->win, game->frame.inst, 0, 0);
	return (1);
}
