/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:17:20 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 16:46:54 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

typedef struct s_game	t_game;
typedef struct s_entity	t_player;

// ../line.c
void	draw_3d(t_game *game, float ray_x, float ray_y, int i);
char	touch(float px, float py, char **map);

// ../movement.c
void	translate_vertical(t_game *game, int speed);
void	translate_horizontal(t_game *game, int speed);
void	rotate_player(t_player *player, float speed);

#endif
