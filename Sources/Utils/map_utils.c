/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:35:36 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:26:40 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Checks is the map as the right column size for each row. */

void	is_valid_dimension(t_map *map, size_t y_size)
{
	if (map->x_column != y_size)
		p_error("Error: Invalid map dimension\n");
}

/*  Determine the gap between each coordinates. More pixels to 
render means smaller gaps between each coordinates.
*/

void	set_unit_vector(t_map *map)
{
	size_t	map_dimension;

	map_dimension = map->x_column * map->y_row;
	if (map_dimension <= 900)
		map->unit_vector_size = 30;
	else if (map_dimension <= 2000)
		map->unit_vector_size = 25;
	else if (map_dimension <= 4000)
		map->unit_vector_size = 20;
	else if (map_dimension <= 10000)
		map->unit_vector_size = 10;
	else if (map_dimension <= 100000)
		map->unit_vector_size = 5;
	else
		map->unit_vector_size = 2;
}
