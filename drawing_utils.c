/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:51:31 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/08 20:49:08 by ekeen-wy         ###   ########.fr       */
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

void	plot_line_low(double x_y[4], double output[3], t_data *img)
{
	int	x_start;
	int	y_start;
	int	yi;

	x_start = x_y[x_1];
	y_start = x_y[y_1];
	yi = 1;
	if (output[dy] < 0)
	{
		yi = -1;
		output[dy] = -1 * output[dy];
	}
	while (x_start < x_y[x_2])
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00FFFFFF);
		if (output[epsilon] > 0)
		{
			y_start += yi;
			output[epsilon] += (2 * (output[dy] - output[dx]));
		}
		else
			output[epsilon] += (2 * output[dy]);
		x_start++;
	}
}

void	plot_line_high(double x_y[4], double output[3], t_data *img)
{
	int	x_start;
	int	y_start;
	int	xi;

	x_start = x_y[x_1];
	y_start = x_y[y_1];
	xi = 1;
	if (output[dx] < 0)
	{
		xi = -1;
		output[dx] = -1 * output[dx];
	}
	while (y_start < x_y[y_2])
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00FFFFFF);
		if (output[epsilon] > 0)
		{
			x_start += xi;
			output[epsilon] += (2 * (output[dx] - output[dy]));
		}
		else
			output[epsilon] += (2 * output[dx]);
		y_start++;
	}
}

void	draw_line(int output[3], double x_y[4], t_data *img)
{
	if (abs(x_y[y_2], x_y[y_1]) < abs(x_y[x_2], x_y[x_1]))
	{
		if (x_y[x_1] > x_y[x_2])
		{
			swap(x_y);
			plot_line_low(x_y, output, img);
		}
		else
			plot_line_low(x_y, output, img);
	}
	else
	{
		if (x_y[y_1] > x_y[y_2])
		{
			swap(x_y);
			plot_line_high(x_y, output, img);
		}
		else
			plot_line_high(x_y, output, img);
	}
}
