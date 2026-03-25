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

#include "../../include/Cubo3D.h"

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