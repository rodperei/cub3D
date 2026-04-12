/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v');
}

int	is_all_space(char *c)
{
	while (*c)
	{
		if (!is_space(*c))
			return (0);
		c++;
	}
	return (1);
}

int	is_digit(char *c)
{
	if (!c || !*c)
		return (0);
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}
