/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:55:50 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 19:28:45 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static void	allocate_map_memory(t_map *map, size_t map_size)
{
	map->vector = (double **)malloc(sizeof(*map->vector) * map_size);
	check_mem(map->vector);
}

/* Creates each coordinate on the map with its resepective
x, y, and z value. A double pointer data type is used to 
store each coordinate for easy access.
 */

void	build_map(t_map *map)
{
	t_list		*temp;
	double		*num;
	size_t		index;
	double		x_cor;
	double		y_cor;

	allocate_map_memory(map, map->x_column * map->y_row);
	temp = map->temp_map;
	y_cor = -1;
	index = 0;
	while (index < map->x_column * map->y_row && ++y_cor < map->y_row)
	{
		num = temp->content;
		x_cor = -1;
		while (++x_cor < map->x_column)
		{
			map->vector[index] = allocate_vector_memory(map->vector_size);
			(map->vector[index][xi]) = x_cor;
			(map->vector[index][yi]) = y_cor;
			(map->vector[index][zi]) = *(num++);
			(map->vector[index][wi]) = 1;
			index++;
		}
		temp = temp->next;
	}
}
