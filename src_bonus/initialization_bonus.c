/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:34:25 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/24 10:53:46 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubo3D.h"
#include "../lib/minilibx-linux/mlx.h"
#include "./utils/utils.h"

static void	init_player(t_entity *player)
{
	player->x = (player->x + 1) * BLOCK - BLOCK / 2.0;
	player->y = (player->y + 1) * BLOCK - BLOCK / 2.0;
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

int	close_game(t_defs *game)
{
	if (game->frame.inst)
		mlx_destroy_image(game->mlx, game->frame.inst);
	if (game->nw_tex.img.inst)
		mlx_destroy_image(game->mlx, game->nw_tex.img.inst);
	if (game->sw_tex.img.inst)
		mlx_destroy_image(game->mlx, game->sw_tex.img.inst);
	if (game->ew_tex.img.inst)
		mlx_destroy_image(game->mlx, game->ew_tex.img.inst);
	if (game->ww_tex.img.inst)
		mlx_destroy_image(game->mlx, game->ww_tex.img.inst);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->map.map)
		free_all(game->map.map);
	exit(0);
	return (0);
}

void	init_value_game(t_defs *def)
{
	def->mlx = NULL;
	def->win = NULL;
	def->frame.inst = NULL;
	def->nw_tex.img.inst = NULL;
	def->sw_tex.img.inst = NULL;
	def->ww_tex.img.inst = NULL;
	def->ew_tex.img.inst = NULL;
	def->nw_tex.path[0] = '\0';
	def->sw_tex.path[0] = '\0';
	def->ww_tex.path[0] = '\0';
	def->ew_tex.path[0] = '\0';
	def->floor_color[0] = -1;
	def->floor_color[1] = -1;
	def->floor_color[2] = -1;
	def->ceiling_color[0] = -1;
	def->ceiling_color[1] = -1;
	def->ceiling_color[2] = -1;
	def->map.map = NULL;
}
