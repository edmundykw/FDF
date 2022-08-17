/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:40:34 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/09 19:49:02 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolute(double num)
{
	int	diff;

	diff = num;
	if (diff < 0)
		diff *= -1;
	return (diff);
}

void	swap(double x_y[4])
{
	double	x0;
	double	y0;
	double	temp;

	x0 = x_y[x_1];
	temp = x_y[x_2];
	x_y[x_1] = temp;
	x_y[x_2] = x0;
	y0 = x_y[y_1];
	temp = x_y[y_2];
	x_y[y_1] = temp;
	x_y[y_2] = y0;
}
