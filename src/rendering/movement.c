/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:36:08 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 17:12:55 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <cubo3D.h>
#include "include/movement.h"

#define COS 0
#define SIN 1

void	rotate_player(t_entity *player, float speed)
{
	if (player->left_rotate)
		player->angle -= speed;
	if (player->right_rotate)
		player->angle += speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

t_grid	calc_offset(float pos, float angle, char opt)
{
	int		offset;
	t_grid	grid;

	if ((opt == COS && cosf(angle) < 0) || (opt == SIN && sinf(angle) < 0))
		offset = -20;
	else
		offset = 20;
	grid.pos = pos / BLOCK;
	grid.add_pos = (pos + offset) / BLOCK;
	grid.sub_pos = (pos - offset) / BLOCK;
	return (grid);
}

void	translate_vertical(t_defs *game, int speed)
{
	t_grid		x;
	t_grid		y;
	t_entity	*player;

	player = &game->player;
	x = calc_offset(player->x, player->angle, COS);
	y = calc_offset(player->y, player->angle, SIN);
	if (player->key_up)
	{
		if (game->map.map[x.add_pos][y.pos] == '0')
			player->x += cosf(player->angle) * speed;
		if (game->map.map[x.pos][y.add_pos] == '0')
			player->y += sinf(player->angle) * speed;
	}
	if (player->key_down)
	{
		if (game->map.map[x.sub_pos][y.pos] == '0')
			player->x -= cosf(player->angle) * speed;
		if (game->map.map[x.pos][y.sub_pos] == '0')
			player->y -= sinf(player->angle) * speed;
	}
}

void	translate_horizontal(t_defs *game, int speed)
{
	t_grid		x;
	t_grid		y;
	t_entity	*player;

	player = &game->player;
	x = calc_offset(player->x, player->angle - PI / 2, COS);
	y = calc_offset(player->y, player->angle - PI / 2, SIN);
	if (player->key_left)
	{
		if (game->map.map[x.add_pos][y.pos] == '0')
			player->x += cosf(player->angle - PI / 2) * speed;
		if (game->map.map[x.pos][y.add_pos] == '0')
			player->y += sinf(player->angle - PI / 2) * speed;
	}
	x = calc_offset(player->x, player->angle + PI / 2, COS);
	y = calc_offset(player->y, player->angle + PI / 2, SIN);
	if (player->key_right)
	{
		if (game->map.map[x.add_pos][y.pos] == '0')
			player->x += cosf(player->angle + PI / 2) * speed;
		if (game->map.map[x.pos][y.add_pos] == '0')
			player->y += sinf(player->angle + PI / 2) * speed;
	}
}
