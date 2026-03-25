/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*z_maloc(int size)
{
	char	*vec;

	vec = malloc(sizeof(char) * (size + 1));
	while (size)
	{
		vec[size] = '\0';
		size--;
	}
	vec[0] = '\0';
	return (vec);
}

int	count_caracter(char *mp, char c)
{
	int	ax;
	int	result;

	ax = 0;
	result = 0;
	while (mp && mp[ax])
	{
		if (mp[ax] == c)
			result++;
		ax++;
	}
	return (result);
}

int	include(char *str_long, char *str_small)
{
	int	aux;
	int	aux1;

	aux = 0;
	while (str_long && str_long[aux])
	{
		aux1 = 0;
		while (str_small[aux1] && str_long[aux + aux1] == str_small[aux1])
			aux1++;
		if ((unsigned int)aux1 == strlen(str_small))
			return (1);
		aux++;
	}
	return (0);
}
