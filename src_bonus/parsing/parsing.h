/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../include/cubo3D.h"
# include "../utils/utils.h"

# define WALL '1'
# define FLOOR '0'
# define SPACE ' '

# define NORT_RAD 1.570
# define SOUTH_RAD 4.710
# define EAST_RAD 3.140
# define WEST_RAD 0.0

// valid_1.c
int		check_ext(char *path);
int		parse_color(char *str, int *color);
int		parse_path(char **lines, t_defs *def);
int		parse_color_line(char **lines, t_defs *def);
void	check_path(t_defs *def);

// valid_2.c
void	load_images(t_defs *def);
char	**clean_file_only_map(char **lines);
int		parsing_map_eliminate_new_line(char **l);
int		check_caracter_map(char **lines);
int		parse_path_key(char *key, char *value, t_defs *def);

// valid_3.c
int		shear_player(t_defs *game);
void	load_map(t_defs *game, char **lines);
void	orientation_player(t_entity *player, char c);

// valid_4.c
int		is_close_map(char **map);
char	right(char **map, int y, int x);
char	left(char **map, int y, int x);
char	down(char **map, int y, int x);
char	up(char **map, int y, int x);

// valid_5.c
int		player_in_map(t_defs *game);
int		cont_player_in_map(t_defs *game);
int		valid_caracters(t_defs *game);
int		copy_path(char *dest, char *src);
int		map_is_last(char *line);

// valid_6.c
void	exit_color(char **lines, char **line);

#endif
