/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/06 19:48:02 by ekeen-wy         ###   ########.fr       */
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
	output[epsilon] = y_change - x_change;
}

static void	get_coord(double x_y[4], double *p1, double *p2)
{
	x_y[x_1] = p1[xi];
	x_y[y_1] = p1[yi];
	x_y[x_2] = p2[xi];
	x_y[y_2] = p2[yi];
}

static void	draw_line(int output[3], double x_y[4], t_data *img)
{
	int	x_start;
	int	y_start;
	int	decision_param;

	x_start = x_y[x_1];
	y_start = x_y[y_1];
	decision_param = output[epsilon];
	while (x_start < x_y[x_2])
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00FFFFFF);
		if (decision_param >= 0)
		{
			y_start += 1;
			decision_param -= output[dx];
		}
		x_start++;
		decision_param += output[dy];
	}
}

static void	trans_coord(double **coord, double *matrix[4], size_t dimension,
	size_t map_size)
{
	double	**index;
	double	*transformed;
	size_t	counter;

	index = coord;
	counter = -1;
	while (++counter < map_size)
	{
		transformed = allocate_vector_memory(dimension);
		matrix_multiply(*index, matrix, transformed, dimension);
		*index[xi] = transformed[xi];
		*index[yi] = transformed[yi];
		*index[zi] = transformed[zi];
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
	size_t	map_dimension;

	counter = -1;
	index = map->vector;
	map_dimension = map->x_row * map->y_column;
	trans_coord(index, map->matrices->matrix_xz, map->vector_size,
		map_dimension);
	while (++counter < map_dimension - 1)
	{
		get_coord(x_y, *index, *(index + 1));
		get_decision_param(x_y, output);
		draw_line(output, x_y, img);
		if (counter < map_dimension - map->y_column)
		{
			get_coord(x_y, *index, *(index + map->y_column));
			get_decision_param(x_y, output);
			draw_line(output, x_y, img);
		}
		index++;
	}
}
