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

void	rotate_player(t_player *player, float speed)
{
	if (player->left_rotate)
		player->angle -= speed;
	if (player->right_rotate)
		player->angle += speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	translate_vertical(t_player *player, int speed)
{
	if (player->key_up)
	{
		player->x += cosf(player->angle) * speed;
		player->y += sinf(player->angle) * speed;
	}
	if (player->key_down)
	{
		player->x -= cosf(player->angle) * speed;
		player->y -= sinf(player->angle) * speed;
	}
}

void	translate_horizontal(t_player *player, int speed)
{
	if (player->key_left)
	{
		player->x += cosf(player->angle - PI / 2) * speed;
		player->y += sinf(player->angle - PI / 2) * speed;
	}
	if (player->key_right)
	{
		player->x += cosf(player->angle + PI / 2) * speed;
		player->y += sinf(player->angle + PI / 2) * speed;
	}
}
