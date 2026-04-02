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

void	put_pixel(int x, int y, int color, t_img *img);
void	draw_square(int x, int y, int size, int color, t_game *game);

#endif
