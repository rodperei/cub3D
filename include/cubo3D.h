/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/04/12 00:38:44 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBO3D_H
# define CUBO3D_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#define WIDTH	1280
#define HEIGHT	720
#define BLOCK	64

#define PI 3.141592654

#define DEBUG 0

#define W		119
#define A		97
#define S		115
#define D		100
#define LEFT	0xff51
#define RIGHT	0xff53
#define ESC		0xff1b

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
	void	*inst; // instância
	char	*data;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct	s_texture
{
	t_img	img;
	int		width;
	int		height;
	char	path[1500];
}	t_texture;

typedef struct s_defs
{
	/*
	t_img img;
	t_texture wall;

	img.inst = mlx_xpm_file_to_image(mlx, "./path", &wall.width, &wall.height)
	*/
	void		*mlx;
	void		*win;
	t_img		frame;
	t_texture	nw_tex;
	t_texture	sw_tex;
	t_texture	ww_tex;
	t_texture	ew_tex;
	int			floor_color[3];
	int			ceiling_color[3];

	t_map		map;
	t_entity	player;

}	t_defs;

//	initialization.c
char	init_game(t_defs *game);
void	init_value_game(t_defs *def);
int		close_game(t_defs *game);

// parsing.c
t_defs parsing(char *path, t_defs *game);

//	rendering/rendering.c
int	draw_loop(t_defs	*game);

#endif
