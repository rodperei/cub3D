/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
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

typedef struct s_pos{
	int x;
	int y;
} t_pos;

typedef struct s_defs{
	char  north_wall_texture[MAX_PATH_LENGTH];
	char  south_wall_texture[MAX_PATH_LENGTH];
	char  west_wall_texture[MAX_PATH_LENGTH];
	char  east_wall_texture[MAX_PATH_LENGTH];
	int floor_color[3];
	int ceiling_color[3];

	char  **map; 
	t_pos initial_position;
	char  initial_direction;

} t_defs;

// parsing/parsing.c
int	valid_map(char *path);

// utils/death.c
void    death(char *message, int exit_code);

#endif