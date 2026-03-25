/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*read_file(char *path)
{
	char	buffer[1024];
	int		fd;
	int		bytes_read;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = NULL;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		line = append(line, bytes_read, buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	return (line);
}

void	print_line(char *line)
{
	printf("%s\n", line);
}

void	print_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		print_line(lines[i]);
		i++;
	}
}
