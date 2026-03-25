/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_ext(char *path)
{
	char	*ext;
	int		aux;

	if (!path || !*path)
		return (0);
	aux = strlen(path) - 4;
	ext = ".cub";
	if (aux == 0 || path[aux - 1] == '/')
		return (0);
	while (*ext)
	{
		if (*ext != path[aux])
			return (0);
		ext++;
		aux++;
	}
	return (1);
}
