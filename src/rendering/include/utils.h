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
typedef struct s_game	t_game;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void	put_pixel(int x, int y, int color, t_img *img);
void	draw_square(t_pos pos, int size, int color, t_game *game);

#endif
