/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnicola <frnicola@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:12 by frnicola          #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by frnicola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cubo3D.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	valid_map(argv[1], &map);
	printf("\n\nMap parsed successfully!\n");
	printf("North Texture: %s\n", map.north_wall_texture);
	printf("South Texture: %s\n", map.south_wall_texture);
	printf("West Texture: %s\n", map.west_wall_texture);
	printf("East Texture: %s\n", map.east_wall_texture);
	printf("Floor Color: %d, %d, %d\n", map.floor_color[0], map.floor_color[1], map.floor_color[2]);
	printf("Ceiling Color: %d, %d, %d\n", map.ceiling_color[0], map.ceiling_color[1], map.ceiling_color[2]);
	return (0);
}
