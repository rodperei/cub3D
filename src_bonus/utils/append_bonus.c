/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*append(char *vec, int size_new, char *buff)
{
	char	*new;
	char	*vec_ori;
	char	*new_ori;

	if (vec == NULL)
		vec = z_maloc(size_new);
	vec_ori = vec;
	new = z_maloc(strlen(vec) + size_new);
	new_ori = new;
	while (vec && *vec)
	{
		*new = *vec;
		vec++;
		new++;
	}
	while (buff && *buff && size_new--)
	{
		*new = *buff;
		buff++;
		new++;
	}
	*new = '\0';
	if (vec_ori)
		free(vec_ori);
	return (new_ori);
}

char	*copy_vec(char *str)
{
	int		x;
	char	*result;
	int		aux;

	x = strlen((const char *)str);
	result = z_maloc(x + 1);
	if (!result)
		return (NULL);
	aux = 0;
	while (str[aux])
	{
		result[aux] = str[aux];
		aux++;
	}
	result[aux] = str[aux];
	return (result);
}

char	**append_matriz(char **matriz, char *new_line)
{
	int		aux;
	char	**result;

	if (!matriz)
		matriz = z_maloc_matriz(0);
	result = z_maloc_matriz(len_all(matriz) + 1);
	aux = 0;
	while (matriz && matriz[aux])
	{
		result[aux] = copy_vec(matriz[aux]);
		aux++;
	}
	result[aux] = copy_vec(new_line);
	result[aux + 1] = NULL;
	if (matriz)
		free_all(matriz);
	return (result);
}

char	*append_index(char *vec, char *append, int index_init)
{
	char	*new;
	int		aux;
	int		aux1;
	int		aux3;

	aux = -1;
	aux1 = -1;
	if (vec == NULL)
		vec = z_maloc(strlen(append) + 1);
	new = z_maloc(strlen(vec) + strlen(append) + 1);
	while (++aux != -1 && vec && vec[aux] && ++aux1 != -1)
	{
		aux3 = 0;
		if (aux != index_init)
			new[aux1] = vec[aux];
		else
		{
			while (aux != index_init && (size_t)aux3 != strlen(append))
				new[aux1++] = append[aux3++];
			aux1--;
			aux++;
		}
	}
	return (new);
}

char	*pop_first_caracter(char *vec, char C)
{
	char	*new;
	int		aux;
	int		aux1;

	aux = 0;
	aux1 = 0;
	if (!vec)
		return (NULL);
	new = z_maloc(strlen(vec) + 1);
	while (vec && vec[aux] && vec[aux] == C)
		aux++;
	while (vec && vec[aux])
		new[aux1++] = vec[aux++];
	new[aux1] = '\0';
	free(vec);
	return (new);
}
