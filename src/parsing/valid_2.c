/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../lib/minilibx-linux/mlx.h"

void	load_images(t_defs *def)
{
	def->nw_tex.img.inst = mlx_xpm_file_to_image(def->mlx, def->nw_tex.path, \
&def->nw_tex.width, &def->nw_tex.height);
	def->sw_tex.img.inst = mlx_xpm_file_to_image(def->mlx, def->sw_tex.path, \
&def->sw_tex.width, &def->sw_tex.height);
	def->ww_tex.img.inst = mlx_xpm_file_to_image(def->mlx, def->ww_tex.path, \
&def->ww_tex.width, &def->ww_tex.height);
	def->ew_tex.img.inst = mlx_xpm_file_to_image(def->mlx, def->ew_tex.path, \
&def->ew_tex.width, &def->ew_tex.height);
	if (def->nw_tex.img.inst)
		def->nw_tex.img.data = mlx_get_data_addr(def->nw_tex.img.inst, \
&def->nw_tex.img.bpp, &def->nw_tex.img.len, &def->nw_tex.img.end);
	if (def->sw_tex.img.inst)
		def->sw_tex.img.data = mlx_get_data_addr(def->sw_tex.img.inst, \
&def->sw_tex.img.bpp, &def->sw_tex.img.len, &def->sw_tex.img.end);
	if (def->ww_tex.img.inst)
		def->ww_tex.img.data = mlx_get_data_addr(def->ww_tex.img.inst, \
&def->ww_tex.img.bpp, &def->ww_tex.img.len, &def->ww_tex.img.end);
	if (def->ew_tex.img.inst)
		def->ew_tex.img.data = mlx_get_data_addr(def->ew_tex.img.inst, \
&def->ew_tex.img.bpp, &def->ew_tex.img.len, &def->ew_tex.img.end);
	if (!def->nw_tex.img.inst)
		printf("Error\nFailed to load north texture\n");
	if (!def->sw_tex.img.inst)
		printf("Error\nFailed to load south texture\n");
	if (!def->ww_tex.img.inst)
		printf("Error\nFailed to load west texture\n");
	if (!def->ew_tex.img.inst)
		printf("Error\nFailed to load east texture\n");
	if (!def->nw_tex.img.inst || !def->sw_tex.img.inst || \
!def->ww_tex.img.inst || !def->ew_tex.img.inst)
	{
		close_game(def);
		death("", 1);
	}
}

char	**clean_file_only_map(char **lines)
{
	int		y;
	char	**line;

	y = 0;
	while (y <= len_all(lines))
	{
		line = ft_split_is_space(lines[y]);
		if (len_all(line) == 2)
		{
			if (equal(line[0], "NO") || equal(line[0], "F") \
|| equal(line[0], "SO") || equal(line[0], "C") \
|| equal(line[0], "WE") || equal(line[0], "EA"))
			{
				lines = delete_vec_matriz(lines, y);
				y = -1;
			}
		}
		else if (y >= 0 && lines[y] && is_all_space(lines[y]))
		{
			lines = delete_vec_matriz(lines, y);
			y = -1;
		}
		free_all(line);
		y++;
	}
	return (lines);
}

int	parsing_map_eliminate_new_line(char **ls)
{
	int		y;
	char	*init;

	y = -1;
	init = NULL;
	while (++y != len_all(ls))
	{
		if ((contains(ls[y], '1') || contains(ls[y], '0')) && init == NULL)
		{
			ls[y] = pop_first_caracter(ls[y], '\n');
			init = ls[y];
		}
		if ((contains(ls[y], '\n') > 1 && init) \
|| (init && contains(ls[y], '1') == 0 && contains(ls[y], '0') == 0))
		{
			printf("Error\nInvalid map, contains newline\n");
			return (0);
		}
	}
	if (init == NULL)
	{
		printf("Error\nMap not found\n");
		return (0);
	}
	return (1);
}

int	space_map(char **lines)
{
	int		y;

	y = -1;
	while (++y != len_all(lines))
	{
		if (contains(lines[y], '\t'))
		{
			printf("Error\nMap, invalid caracter, only space is allowed.");
			return (0);
		}
	}
	return (1);
}

int	check_caracter_map(char **lines)
{
	int		y;
	int		j;
	char	c;

	y = -1;
	while (++y != len_all(lines))
	{
		j = -1;
		while (lines[y] && (size_t)++j != strlen(lines[y]))
		{
			c = lines[y][j];
			if (c != WALL && c != FLOOR && c != SPACE && c != 'N' \
&& c != 'S' && c != 'E' && c != 'O' && c != '\n')
			{
				printf("Error\nMap, invalid caracter:%d L:%d C:%d\n", c, y, j);
				return (0);
			}
		}
	}
	return (1);
}
