/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:52:59 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/02 16:56:11 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_img	t_img;
typedef struct s_defs	t_defs;
typedef struct s_entity	t_entity;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_ray
{
	enum
	{
		NORTH,
		SOUTH,
		WEST,
		EAST
	} e_orientation;
	float	x;
	float	y;
	float	angle;
}	t_ray;

void	put_pixel(int x, int y, int color, t_img *img);
void	draw_square(t_pos pos, int size, int color, t_defs *game);
float	distance(float x, float y);
float	fixed_distance(t_entity player, float x2, float y2);

#endif
