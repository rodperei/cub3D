/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**read_file(int fd)
{
	char	*text;
	int		bit_read;
	char	*buf;
	char	**text_split;

	buf = z_maloc(SIZE_BUF);
	text = append(NULL, 1, buf);
	bit_read = read(fd, buf, SIZE_BUF);
	while (bit_read > 0)
	{
		text = append(text, bit_read, buf);
		bit_read = read(fd, buf, SIZE_BUF);
	}
	close(fd);
	free (buf);
	text_split = &text;
	text_split = ft_split(text, '\n');
	free(text);
	return (text_split);
}

char	*read_file_line(int fd)
{
	char	*text;
	int		bit_read;
	char	*buf;

	buf = z_maloc(SIZE_BUF);
	text = append(NULL, 1, buf);
	bit_read = read(fd, buf, SIZE_BUF);
	while (bit_read > 0)
	{
		text = append(text, bit_read, buf);
		bit_read = read(fd, buf, SIZE_BUF);
	}
	if (text[strlen(text) - 1] != '\n')
		text = append(text, 1, "\n");
	close(fd);
	free (buf);
	return (text);
}

int	exist_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
