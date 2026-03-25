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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    valid_map(argv[1]);

    // Initialize game, load map, etc.
    
    return 0;
}