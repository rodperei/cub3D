/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_not_replace_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:17 by frnicola          #+#    #+#             */
/*   Updated: 2025/09/02 12:43:27 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	cont_words_not_replace(char *str, char C)
{
	int	cant;
	int	aux;

	cant = 0;
	aux = 0;
	while (str && str[aux])
	{
		while (str[aux] == C)
			aux++;
		if (str[aux] != C && str[aux])
			cant++;
		while (str[aux] != C && str[aux])
			aux++;
	}
	return (cant);
}

int	cont_letter_not_replace(char *str, char C)
{
	int	aux;

	aux = 0;
	while (str[aux] == C)
		aux++;
	while (str[aux] != C && str[aux])
		aux++;
	return (aux + 1);
}

char	**ft_split_not_replace(char *str, char C)
{
	char	**result;
	int		cant;
	int		aux;
	int		aux1;
	int		letter;

	cant = cont_words_not_replace(str, C);
	aux = 0;
	letter = 0;
	result = malloc((1 + cant) * sizeof(char *));
	while (cant != aux)
	{
		letter = cont_letter_not_replace(str, C);
		result[aux] = malloc(letter * (sizeof(char) + 1));
		aux1 = 0;
		while (letter != aux1)
			result[aux][aux1++] = *(str++);
		result[aux][aux1] = '\0';
		aux++;
	}
	result[aux] = NULL;
	return (result);
}
