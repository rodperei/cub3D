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

char	**read_file(int fd, char c)
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
	text_split = ft_split(text, c);
	free(text);
	return (text_split);
}
