/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:53:14 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 02:10:23 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./include/cubo3D.h"
#include "lib/minilibx-linux/mlx.h"
#include "src/parsing/parsing.h"

static int	key_press(int keycode, t_entity *player)
{
	if (keycode == W)
		player->key_up = 1;
	if (keycode == S)
		player->key_down = 1;
	if (keycode == A)
		player->key_left = 1;
	if (keycode == D)
		player->key_right = 1;
	if (keycode == LEFT)
		player->left_rotate = 1;
	if (keycode == RIGHT)
		player->right_rotate = 1;
	return (0);
}

static int	key_release(int keycode, t_defs *game)
{
	if (keycode == W)
		game->player.key_up = 0;
	if (keycode == S)
		game->player.key_down = 0;
	if (keycode == A)
		game->player.key_left = 0;
	if (keycode == D)
		game->player.key_right = 0;
	if (keycode == LEFT)
		game->player.left_rotate = 0;
	if (keycode == RIGHT)
		game->player.right_rotate = 0;
	if (keycode == ESC)
		close_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_defs	game;

	if (argc != 2)
		death("Error:\nUsage: ./cubo3D <map.cub>", 2);
	init_value_game(&game);
	parsing(argv[1], &game);
	printf("Player position: x = %f, y = %f, angle = %f\n", \
game.player.x, game.player.y, game.player.angle);
	printf("Map size: lines = %d, cols = %d\n", game.map.lines, game.map.cols);
	printf("North texture: %s\n", game.nw_tex.path);
	printf("South texture: %s\n", game.sw_tex.path);
	printf("West texture: %s\n", game.ww_tex.path);
	printf("East texture: %s\n", game.ew_tex.path);
	if (!init_game(&game))
		return (1);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
}
