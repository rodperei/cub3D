/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../include/cubo3D.h"

void	valid_params(char *path, t_defs *game)
{
	char	**lines;

	if (!check_ext(path))
		death("Error\nInvalid file extension. Expected .cub", 1);
	if (!exist_file(path))
		death("Error\nFailed to open file", 1);
	lines = read_file(open(path, O_RDONLY));
	if (!lines)
		death("Error\nFailed to read file", 1);
	parse_path(lines, game);
	parse_color_line(lines, game);
	free_all(lines);
	check_path(game);
	game->mlx = mlx_init();
	load_images(game);
}

void	valid_map(char *path, t_defs *game)
{
	char	**lines;
	char	*line;

	line = read_file_line(open(path, O_RDONLY));
	lines = ft_split_not_replace(line, '\n');
	free(line);
	lines = clean_file_only_map(lines);
	if (!parsing_map_eliminate_new_line(lines) || !check_caracter_map(lines))
	{
		free_all(lines);
		close_game(game);
	}
	game->map.map = lines;
	if (!shear_player(game))
	{
		printf("Error:\nPlayer not found in the map\n");
		close_game(game);
	}
}

t_defs	parsing(char *path, t_defs *game)
{
	valid_params(path, game);
	valid_map(path, game);
	return (*game);
}
