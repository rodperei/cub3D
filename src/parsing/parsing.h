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

#ifndef PARSING_H
# define PARSING_H

# include "../../include/cubo3D.h"
# include "../utils/utils.h"

# define WALL '1'
# define FLOOR '0'
# define SPACE ' '

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
int		space_map(char **lines);

#endif
