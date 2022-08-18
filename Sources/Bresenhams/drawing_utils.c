/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:51:31 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 18:06:35 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* A personal version of pixel put for more efficient rendering of pixel. */

void	my_mlx_pixel_put(t_data *img, int x, int y)
{
	char	*dst;
	int		pixels;

	pixels = x * y;
	if (pixels <= WIND_WIDTH * WIND_HEIGHT
		&& (x >= 0 && x <= WIND_WIDTH) && (y >= 0 && y <= WIND_HEIGHT))
	{
		dst = img->addr + (y * img->line_length
				+ x *(img->bits_per_pixel / 8));
		*(unsigned int *)dst = 0x00FFFFFF;
	}
}

/* Gets the x and y coordinates of the respective points that will
be rendered.
 */

t_coord	*get_coord(double *v1, double *v2)
{
	t_coord	*coord;

	coord = (t_coord *)malloc(sizeof(*coord));
	check_mem(coord);
	coord->x_y[x_1] = v1[xi];
	coord->x_y[y_1] = v1[yi];
	coord->x_y[x_2] = v2[xi];
	coord->x_y[y_2] = v2[yi];
	return (coord);
}

/* This is used to apply all the transformation that has happened
to each x, y, z coordinates before they are retrieved for rendering.
 */

void	trans_coord(double **coord, double *matrix[4], size_t dimension,
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
