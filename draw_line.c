/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:45 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/22 14:38:06 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(int *x, int *y, t_data *img)
{
	int	dy;
	int	dx;
	int	x_start;
	int	y_start;
	int	decision_param;

	dy = y[1] - y[0];
	dx = x[1] - x[0];
	x_start = x[0];
	y_start = y[0];
	decision_param = dy - dx;
	while (x_start < x[1])
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00FF0000);
		if (decision_param >= 0)
		{
			y_start += 1;
			decision_param -= dx;
		}
		x_start++;
		decision_param += dy;
	}
}
