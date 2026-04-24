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

typedef struct s_defs	t_defs;
typedef struct s_map	t_map;
typedef struct s_entity	t_player;
typedef struct s_ray	t_ray;

//	../bresenham.c
void	draw_line(t_defs *game, t_ray ray, int color);

//	../raycasting/projection.c
void	draw_3d(t_defs *game, t_ray ray, int i);

//	../movement.c
int		calc_elapsed_time(void);
void	translate_vertical(t_defs *game, int speed);
void	translate_horizontal(t_defs *game, int speed);
void	rotate_player(t_player *player, float speed);

//	../intersections.c
t_ray	calc_vertical_isect(t_defs game, float angle);
t_ray	calc_horizontal_isect(t_defs game, float angle);

#endif
