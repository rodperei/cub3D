/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matriz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**z_maloc_matriz(int size)
{
	char	**vec;
	int		aux;

	vec = malloc(sizeof(char *) * (size + 1));
	aux = 0;
	while (aux != size)
	{
		vec[aux] = NULL;
		aux++;
	}
	vec[aux] = NULL;
	return (vec);
}

char	**delete_vec_matriz(char **matriz, int index_delete)
{
	int		aux;
	int		aux1;
	char	**result;

	if (!matriz)
		matriz = z_maloc_matriz(1);
	result = z_maloc_matriz(len_all(matriz));
	aux1 = 0;
	aux = 0;
	while (matriz && matriz[aux1])
	{
		if (index_delete == aux1)
			aux1++;
		if (!matriz[aux1])
			break ;
		result[aux] = copy_vec(matriz[aux1]);
		aux++;
		aux1++;
	}
	result[aux] = NULL;
	free_all(matriz);
	return (result);
}

int	len_mat(char **mp, char c)
{
	int	ay;
	int	ax;
	int	result;

	ay = 0;
	ax = 0;
	result = 0;
	while (mp && mp[ay])
	{
		while ((unsigned int)ax != strlen(mp[ay]))
		{
			if (mp[ay][ax] == c)
				result++;
			ax++;
		}
		ay++;
		ax = 0;
	}
	return (result);
}

void	free_all(char **matriz)
{
	int	aux;

	aux = 0;
	while (matriz && matriz[aux])
	{
		free(matriz[aux]);
		aux++;
	}
	if (matriz)
		free(matriz);
	matriz = NULL;
}

void	print_lines(char **matriz)
{
	int	i;
	int	j;

	i = 0;
	while (matriz[i])
	{
		j = 0;
		while (matriz[i][j])
		{
			if (matriz[i][j] != '\n')
				printf("%c", matriz[i][j]);
			else
				printf("%c", matriz[i][j]);
			j++;
		}
		i++;
	}
}
