/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/16 20:06:30 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	trans_coord(double **coord, double *matrix[4], size_t dimension,
	size_t map_size)
{
	double	**index;
	double	*transformed;
	size_t	counter;

	index = coord;
	counter = 0;
	while (counter++ < map_size)
	{
		transformed = allocate_vector_memory(dimension);
		matrix_multiply(*index, matrix, transformed, dimension);
		(*index)[xi] = transformed[xi];
		(*index)[yi] = transformed[yi];
		(*index)[zi] = transformed[zi];
		free(transformed);
		index++;
	}
}

void	bresenhams(t_map *map, t_data *img)
{
	size_t	index;
	size_t	map_size;

	map_size = map->x_column * map->y_row;
	trans_coord(map->vector, map->matrices->matrix_xz, map->vector_size,
		map_size);
	index = -1;
	while (++index < map_size - 1)
	{
		if ((index + 1) % map->x_column != 0)
			draw_line(map->vector[index], map->vector[index + 1], img);
		if (index < map_size - map->x_column)
			draw_line(map->vector[index],
				map->vector[index + map->x_column], img);
	}
}
