/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:51:31 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/17 16:08:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
