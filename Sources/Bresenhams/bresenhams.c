/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:25:36 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* 
The following algorithm is adapted into C from the following Wikipedia page:
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#
*/

void	plot_line_low(t_coord *coord, t_data *img)
{
	int	yi;

	yi = 1;
	coord->dx = coord->x_y[x_2] - coord->x_y[x_1];
	coord->dy = coord->x_y[y_2] - coord->x_y[y_1];
	if (coord->dy < 0)
	{
		yi = -1;
		coord->dy = -1 * coord->dy;
	}
	coord->epsilon = (2 * coord->dy) - coord->dx;
	while (coord->x_y[x_1] < coord->x_y[x_2])
	{
		my_mlx_pixel_put(img, coord->x_y[x_1], coord->x_y[y_1]);
		if (coord->epsilon > 0)
		{
			coord->x_y[y_1] += yi;
			coord->epsilon += (2 * (coord->dy - coord->dx));
		}
		else
			coord->epsilon += (2 * coord->dy);
		coord->x_y[x_1]++;
	}
}

void	plot_line_high(t_coord *coord, t_data *img)
{
	int	xi;

	xi = 1;
	coord->dx = coord->x_y[x_2] - coord->x_y[x_1];
	coord->dy = coord->x_y[y_2] - coord->x_y[y_1];
	if (coord->dx < 0)
	{
		xi = -1;
		coord->dx = -1 * coord->dx;
	}
	coord->epsilon = (2 * coord->dx) - coord->dy;
	while (coord->x_y[y_1] <= coord->x_y[y_2])
	{
		my_mlx_pixel_put(img, coord->x_y[x_1], coord->x_y[y_1]);
		if (coord->epsilon > 0)
		{
			coord->x_y[x_1] += xi;
			coord->epsilon += (2 * (coord->dx - coord->dy));
		}
		else
			coord->epsilon += (2 * coord->dx);
		coord->x_y[y_1]++;
	}
}

void	draw_line(double *v1, double *v2, t_data *img)
{
	t_coord	*coord;

	coord = get_coord(v1, v2);
	if (absolute(coord->x_y[y_2] - coord->x_y[y_1])
		< absolute(coord->x_y[x_2] - coord->x_y[x_1]))
	{
		if (coord->x_y[x_1] > coord->x_y[x_2])
		{
			swap(coord->x_y);
			plot_line_low(coord, img);
		}
		else
			plot_line_low(coord, img);
	}
	else
	{
		if (coord->x_y[y_1] > coord->x_y[y_2])
		{
			swap(coord->x_y);
			plot_line_high(coord, img);
		}
		else
			plot_line_high(coord, img);
	}
	free(coord);
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
