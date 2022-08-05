/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/04 11:34:53 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_decision_param(int x_y[4], int *output)
{
	int	y_change;
	int	x_change;

	y_change = x_y[y_2] - x_y[y_1];
	x_change = x_y[x_2] - x_y[x_1];
	output[dy] = y_change;
	output[dx] = x_change;
	output[epsilon] = y_change - x_change;
}

static void	get_coord(int x_y[4], t_vector *p1, t_vector *p2)
{
	x_y[x_1] = p1->x;
	printf("%d ", x_y[x_1]);
	x_y[y_1] = p1->y;
	printf("%d\n", x_y[y_1]);
	x_y[x_2] = p2->x;
	printf("%d ", x_y[x_2]);
	x_y[y_2] = p2->y;
	printf("%d\n", x_y[y_2]);
}

static void	draw_line(int output[3], int x_y[4], t_data *img)
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

void	bresenhams(t_map *map, t_data *img)
{
	int			x_y[4];
	int			output[3];
	size_t		counter;
	t_vector	**index;
	size_t		map_dimension;

	counter = 0;
	index = map->vector;
	map_dimension = map->x_row * map->y_column;
	while (counter++ < map_dimension)
	{
		if (counter < map_dimension - map->y_column)
		{
			get_coord(x_y, *index, *(index + map->y_column));
			get_decision_param(x_y, output);
			draw_line(output, x_y, img);
			if (counter % map->y_column != 0)
			{
				get_coord(x_y, *index, *(index + 1));
				get_decision_param(x_y, output);
				draw_line(output, x_y, img);
			}
		}
		index++;
	}
}
