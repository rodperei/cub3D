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

# include "../src/utils/utils.h"

# define MAX_PATH_LENGTH 5000

typedef struct	s_player
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
}	t_player;

typedef struct	s_map
{
	char	**map;
	int		lines;
	int		cols;
}	t_map;

typedef struct s_defs
{
	char		north_wall_texture[MAX_PATH_LENGTH];
	char		south_wall_texture[MAX_PATH_LENGTH];
	char		west_wall_texture[MAX_PATH_LENGTH];
	char		east_wall_texture[MAX_PATH_LENGTH];
	int			floor_color[3];
	int			ceiling_color[3];

	t_map		map;
	t_player	player;

}	t_defs;

// parsing/parsing.c
int		valid_map(char *path, t_map *map);

#endif
