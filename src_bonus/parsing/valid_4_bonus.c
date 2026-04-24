/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	up(char **map, int y, int x)
{
	if (y == 0)
		return ('\0');
	return (map[y - 1][x]);
}

char	down(char **map, int y, int x)
{
	if (y + 1 >= len_all(map))
		return ('\0');
	return (map[y + 1][x]);
}

char	left(char **map, int y, int x)
{
	if (x == 0)
		return ('\0');
	return (map[y][x - 1]);
}

char	right(char **map, int y, int x)
{
	if ((size_t)(x + 1) >= strlen(map[y]))
		return ('\0');
	return (map[y][x + 1]);
}

int	is_close_map(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (++y != len_all(map))
	{
		x = -1;
		while ((size_t)++x != strlen(map[y]))
		{
			if (map[y][x] == '0' && (!up(map, y, x) \
|| up(map, y, x) == ' '))
				return (0);
			if (map[y][x] == '0' && (!down(map, y, x) \
|| down(map, y, x) == ' '))
				return (0);
			if (map[y][x] == '0' && (!left(map, y, x) \
|| left(map, y, x) == ' '))
				return (0);
			if (map[y][x] == '0' && (!right(map, y, x) \
|| right(map, y, x) == ' '))
				return (0);
		}
	}
	return (1);
}
