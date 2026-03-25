/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_map(char *path)
{
	int		fd;
	char	*line;
	
	if (!check_ext(path))
		death("Error: Invalid file extension. Expected .cub", 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		death("Error: Failed to open file", 1);
	line = read_file(path);
	print_line(line);
	free(line);
	return (1);
}
