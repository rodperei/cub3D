/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/31 21:29:44 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBO3D_H
# define CUBO3D_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_PATH_LENGTH 5000

#define WIDTH	1280
#define HEIGHT	720
#define BLOCK	64

#define PI 3.141592654

#define DEBUG 1

typedef struct	s_entity
{
	float	x;
	float	y;
	float	angle;

	char	key_up;
	char	key_down;
	char	key_left;
	char	key_right;

	char	left_rotate;
	char	right_rotate;
}	t_entity;

typedef struct	s_map
{
	char	**map;
	int		lines;
	int		cols;
}	t_map;

typedef struct	s_img
{
	void	*inst;
	char	*data;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_entity	player;
	t_map		map;
} t_game;

typedef struct s_defs
{
	char		north_wall_texture[MAX_PATH_LENGTH];
	char		south_wall_texture[MAX_PATH_LENGTH];
	char		west_wall_texture[MAX_PATH_LENGTH];
	char		east_wall_texture[MAX_PATH_LENGTH];
	int			floor_color[3];
	int			ceiling_color[3];

	t_map		map;
	t_entity	player;

}	t_defs;

// parsing/parsing.c
int		valid_map(char *path, t_map *map);

//	rendering/rendering.c
int	draw_loop(t_game	*game);

#endif
