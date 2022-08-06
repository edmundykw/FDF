/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:35:36 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/06 19:50:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x <= 1440 && y <= 920)
	{
		dst = img->addr + (y * img->line_length
				+ x *(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	is_valid_dimension(t_map *map, size_t y_size)
{
	if (map->y_column != y_size)
		p_error("Error: Invalid map dimension\n");
}

void	set_unit_vector(t_map *map)
{
	size_t	map_dimension;
	size_t	img_dimension;

	map_dimension = map->x_row * map->y_column;
	img_dimension = 1440 * 920;
	if (map_dimension / img_dimension >= 1)
		map->unit_vector_size = 5;
	else
		map->unit_vector_size = 15;
}

double	*find_img_midpoint(t_map *map)
{
	size_t		row;
	size_t		column;

	row = map->x_row / 2;
	column = map->y_column / 2;
	return (map->vector[(row * map->x_row) + column]);
}
