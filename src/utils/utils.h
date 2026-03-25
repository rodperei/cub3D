/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE_BUF 1024

// append.c
char	*append(char *vec, int size_new, char *buff);
char	*copy_vec(char *str);
char	**append_matriz(char **matriz, char *new_line);

// death.c
void	death(char *message, int exit_code);

// ft_split.c
char	**ft_split(char *str, char C);
int		cont_words(char *str, char C);
int		cont_letter(char *str, char C);

// lens.c
int		len_all(char **str);
int		equal(char *str, char *str1);
int		equaln(char *str, char *str1, int size);

// read_file.c
char	**read_file(int fd, char c);

// utils_matriz.c
char	**z_maloc_matriz(int size);
char	**delete_vec_matriz(char **matriz, int index_delete);
int		count_caracter_matriz(char **mp, char c);
void	free_all(char **matriz);
void	print_lines(char **matriz);

// utils_vec.c
char	*z_maloc(int size);
int		count_caracter(char *mp, char c);
int		include(char *str_long, char *str_small);

#endif