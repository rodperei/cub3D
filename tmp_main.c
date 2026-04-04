/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:53:14 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 17:11:38 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <cubo3D.h>
#include "lib/minilibx-linux/mlx.h"
#include "src/utils/utils.h"

#define W		119
#define A		97
#define S		115
#define D		100
#define LEFT	0xff51
#define RIGHT	0xff53
#define ESC		0xff1b

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.inst);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game->map.map);
	exit(0);
	return (0);
}

void	init_player(t_player *player)
{
	/*A posição inicial será decidida consoante a coordenada dada no mapa*/
	player->x = 90;
	player->y = 90;
	player->angle = (3 * PI) / 2;
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->left_rotate = 0;
	player->right_rotate = 0;
}

int	key_press(int keycode, t_player *player)
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

int	key_release(int keycode, t_game *game)
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

t_map	get_map()
{
	/*No futuro, esta função será trocada pelo recebimento do mapa analizado
	 na fase de parsing. Será apagado no final*/
	t_map	ret;
	char	**map = malloc(sizeof(char *) * 9);
	char	tmp[8][9] = {"11111111",
						 "10010001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "01111111"};

	for(int i = 0; i < 8; i++)
	{
		map[i] = malloc(sizeof(char) * 9);
		for(int j = 0; j < 9; j++)
			map[i][j] = tmp[j][i];
	}
	map[8] = 0;
	ret.map = map;
	ret.cols = 8;
	ret.lines = 8;
	return (ret);
}

char	init_game(t_game *game)
{
	t_img	tmp;

	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	if (!game->win)
		return (0);
	tmp.inst = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!tmp.inst)
		return (0);
	tmp.data = mlx_get_data_addr(tmp.inst, &tmp.bpp, &tmp.len, &tmp.end);
	game->img.data = tmp.data;
	game->img.inst = tmp.inst;
	game->img.bpp = tmp.bpp;
	game->img.end = tmp.end;
	game->img.len = tmp.len;
	mlx_put_image_to_window(game->mlx, game->win, game->img.inst, 0, 0);
	return (1);
}

int	main(void)
{
	t_game	game;

	if (!init_game(&game))
		return (1);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
/*	|***CONTINUE_HERE!!!***|
		-adicionar texturas em todas as orientações de parede
		-criar função que define a posição inicial do jogador consoante defs
		-juntar parsing e execussão*/
}
