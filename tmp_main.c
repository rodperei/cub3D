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


int	close_game(t_defs *game)
{
	mlx_destroy_image(game->mlx, game->frame.inst);
	mlx_destroy_image(game->mlx, game->north_wall_texture.img.inst);
	mlx_destroy_image(game->mlx, game->south_wall_texture.img.inst);
	mlx_destroy_image(game->mlx, game->east_wall_texture.img.inst);
	mlx_destroy_image(game->mlx, game->west_wall_texture.img.inst);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game->map.map);
	exit(0);
	return (0);
}

void	init_player(t_entity *player)
{
	/*A posição inicial será decidida consoante a coordenada dada no mapa*/
	player->x = player->x * BLOCK - BLOCK / 2;
	player->y = player->y * BLOCK - BLOCK / 2;
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->left_rotate = 0;
	player->right_rotate = 0;
}

int	key_press(int keycode, t_entity *player)
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

int	key_release(int keycode, t_defs *game)
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
	t_map	ret;
	char	**map = malloc(sizeof(char *) * 9);
	char	tmp[8][9] = {"11111111",
						 "10000001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "10000001",
						 "11111111"};

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

t_defs	temp_defs_init(void)
{
	t_defs	def;

	def.mlx = mlx_init();
	def.north_wall_texture.img.inst = mlx_xpm_file_to_image(def.mlx, "./textures/wall_texture.xpm", &def.north_wall_texture.width, &def.north_wall_texture.height);
	def.north_wall_texture.img.data = mlx_get_data_addr(def.north_wall_texture.img.inst, &def.north_wall_texture.img.bpp, &def.north_wall_texture.img.len, &def.north_wall_texture.img.end);
	def.south_wall_texture.img.inst = mlx_xpm_file_to_image(def.mlx, "./textures/wall_texture.xpm", &def.south_wall_texture.width, &def.south_wall_texture.height);
	def.south_wall_texture.img.data = mlx_get_data_addr(def.south_wall_texture.img.inst, &def.south_wall_texture.img.bpp, &def.south_wall_texture.img.len, &def.south_wall_texture.img.end);
	def.west_wall_texture.img.inst = mlx_xpm_file_to_image(def.mlx, "./textures/wall_texture.xpm", &def.west_wall_texture.width, &def.west_wall_texture.height);
	def.west_wall_texture.img.data = mlx_get_data_addr(def.west_wall_texture.img.inst, &def.west_wall_texture.img.bpp, &def.west_wall_texture.img.len, &def.west_wall_texture.img.end);
	def.east_wall_texture.img.inst = mlx_xpm_file_to_image(def.mlx, "./textures/wall_texture.xpm", &def.east_wall_texture.width, &def.east_wall_texture.height);
	def.east_wall_texture.img.data = mlx_get_data_addr(def.east_wall_texture.img.inst, &def.east_wall_texture.img.bpp, &def.east_wall_texture.img.len, &def.east_wall_texture.img.end);
	def.floor_color[0] = 0;
	def.floor_color[1] = 0;
	def.floor_color[2] = 255;
	def.ceiling_color[0] = 255;
	def.ceiling_color[1] = 0;
	def.ceiling_color[2] = 0;
	def.map = get_map();
	def.player.x = 4;
	def.player.y = 4;
	def.player.angle = (3 * PI) / 2;
	return (def);
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

int	main(void)
{
	t_defs	game;

	game = temp_defs_init();
	if (!init_game(&game))
		return (1);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
/*	|***CONTINUE_HERE!!!***|
		-adicionar texturas em todas as orientações de parede
		-juntar parsing e execussão*/
}
