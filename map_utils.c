/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:35:36 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/08 20:39:16 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_valid_dimension(t_map *map, size_t y_size)
{
	if (map->x_column != y_size)
		p_error("Error: Invalid map dimension\n");
}

void	set_unit_vector(t_map *map)
{
	size_t	map_dimension;
	size_t	img_dimension;

	map_dimension = map->x_column * map->y_row;
	img_dimension = 1440 * 920;
	if (map_dimension / img_dimension >= 1)
		map->unit_vector_size = 5;
	else
		map->unit_vector_size = 15;
}

/* cater the midpoint to maps that are even (whether row * col or any of it ) */
double	*find_img_midpoint(t_map *map)
{
	size_t		row;
	size_t		column;

	column = map->x_column / 2;
	row = map->y_row / 2;
	return (map->vector[(row * map->y_row) + column]);
}
