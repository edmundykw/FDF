/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/08 20:55:10 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_decision_param(double x_y[4], int *output)
{
	int	y_change;
	int	x_change;

	y_change = x_y[y_2] - x_y[y_1];
	x_change = x_y[x_2] - x_y[x_1];
	output[dy] = y_change;
	output[dx] = x_change;
	output[epsilon] = (2 * y_change) - x_change;
	//printf("dx: %d dy: %d epsilon: %d\n", output[dx], output[dy], output[epsilon]);
}

static void	get_coord(double x_y[4], double *p1, double *p2)
{
	x_y[x_1] = p1[xi];
	printf("Coord x1: %f ", x_y[x_1]);
	x_y[y_1] = p1[yi];
	printf("Coord y1: %f\n", x_y[y_1]);
	x_y[x_2] = p2[xi];
	printf("Coord x2: %f ", x_y[x_2]);
	x_y[y_2] = p2[yi];
	printf("Coord y2: %f\n", x_y[y_2]);
}

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
		//printf("Transformed x: %f y: %f z: %f w: %f\n", (*index)[xi], (*index)[yi],
			//(*index)[zi], (*index)[wi]);
		free(transformed);
		index++;
	}
}

void	bresenhams(t_map *map, t_data *img)
{
	double	x_y[4];
	int		output[3];
	size_t	counter;
	double	**index;
	size_t	map_size;

	counter = -1;
	index = map->vector;
	map_size = map->x_column * map->y_row;
	trans_coord(index, map->matrices->matrix_xz, map->vector_size,
		map_size);
	while (++counter < map_size - 1)
	{
		get_coord(x_y, *index, *(index + 1));
		get_decision_param(x_y, output);
		draw_line(output, x_y, img);
		if (counter < map_size - map->x_column)
		{
			get_coord(x_y, *index, *(index + map->x_column));
			get_decision_param(x_y, output);
			draw_line(output, x_y, img);
		}
		index++;
	}
}
