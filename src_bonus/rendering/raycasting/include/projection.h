/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodperei <rodperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:52:04 by rodperei          #+#    #+#             */
/*   Updated: 2026/04/12 01:59:45 by rodperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

typedef struct s_defs	t_defs;
typedef struct s_ray	t_ray;

typedef struct s_ival
{
	int	start;
	int	end;
}	t_ival;

void	paint_wall(t_defs *game, t_ray ray, t_ival wall, int i);

#endif
