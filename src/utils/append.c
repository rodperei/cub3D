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
	result = malloc((x + 1) * sizeof(char));
	if (!result)
		return (NULL);
	aux = 0;
	while (aux != x)
	{
		result[aux] = str[aux];
		aux++;
	}
	result[aux] = '\0';
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
