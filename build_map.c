/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:55:50 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/29 23:12:02 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	allocate_map_memory(t_map *map, size_t vector_size)
{
	map->vector = (t_vector **)malloc(sizeof(map->vector) * vector_size);
	if (map->vector == NULL)
		p_error("Memory allocation failed\n");
}

void	build_map(t_map *map)
{
	t_list		*temp;
	int			*num;
	size_t		index;
	size_t		x_cor;
	size_t		y_cor;

	allocate_map_memory(map, map->x_row * map->y_column);
	temp = map->temp_map;
	x_cor = 0;
	index = 0;
	while (index < map->x_row * map->y_column)
	{
		num = temp->content;
		y_cor = -1;
		while (++y_cor < map->y_column)
		{
			map->vector[index] = (t_vector *)malloc(sizeof(t_vector));
			(map->vector[index])->x = x_cor;
			(map->vector[index])->y = y_cor;
			(map->vector[index])->z = *(num++);
			index++;
		}
		temp = temp->next;
		x_cor++;
	}
}
