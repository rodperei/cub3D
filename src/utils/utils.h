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
char	*append_index(char *vec, char *append, int index_init);
char	*pop_first_caracter(char *vec, char C);

// death.c
void	death(char *message, int exit_code);

// ft_split.c
char	**ft_split(char *str, char C);
char	**ft_split_is_space(char *str);
char	**ft_split_not_replace(char *str, char C);
int		cont_words(char *str, char C);
int		cont_letter(char *str, char C);

// lens.c
int		len_all(char **str);
int		equal(char *str, char *str1);
int		equaln(char *str, char *str1, int size);
int		contains(char *str, char C);

// read_file.c
char	**read_file(int fd);
char	*read_file_line(int fd);
int		exist_file(char *path);

// string.c
int		is_space(char c);
int		is_digit(char *c);
int		is_all_space(char *c);

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
char	*matriz_for_vec(char **matriz);

#endif