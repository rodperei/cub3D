/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens_bonus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	len_all(char **str)
{
	int	aux;

	aux = 0;
	while (str && str[aux])
		aux++;
	return (aux);
}

int	equal(char *str, char *str1)
{
	int	aux;

	if (!str || !str1 || !*str || !*str1)
		return (str == str1);
	aux = 0;
	while (str[aux] && str1[aux])
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (str[aux] == str1[aux]);
}

int	equaln(char *str, char *str1, int size)
{
	int	aux;

	if (!str || !str1)
		return (str == str1);
	aux = 0;
	while ((str[aux] || str1[aux]) && aux < size)
	{
		if (str[aux] != str1[aux])
			return (0);
		aux++;
	}
	return (1);
}

int	contains(char *str, char C)
{
	int	aux;
	int	cant;

	cant = 0;
	aux = 0;
	while (str[aux])
	{
		if (str[aux] == C)
			cant++;
		aux++;
	}
	return (cant);
}

int	in_str(char *str, char *C)
{
	int	i;
	int	j;

	if (!str || !C)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (C[j] && str[i + j] == C[j])
			j++;
		if (C[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}
