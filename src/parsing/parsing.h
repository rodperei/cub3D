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

# include "../../include/Cubo3D.h"

// read.c
char	*read_file(char *path);
void	print_lines(char **lines);
void	print_line(char *line);

// valid_1.c
int		check_ext(char *path);

#endif
