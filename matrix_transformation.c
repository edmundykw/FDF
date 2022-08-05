/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:09:27 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/05 11:48:37 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Find the center point of rotation for the image */

double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180));
}

void	rotate_z(double *matrix[4], double degree)
{
	double	radian;

	radian = degree_to_radian(degree);
	matrix[x][x] = cos(radian);
	matrix[x][y] = sin(radian);
	matrix[y][x] = -sin(radian);
	matrix[y][y] = cos(radian);
}

void	rotate_x(double *matrix[4], double degree)
{
	double	radian;

	radian = degree_to_radian(degree);
	matrix[y][y] = cos(radian);
	matrix[y][z] = sin(radian);
	matrix[z][y] = -sin(radian);
	matrix[z][z] = cos(radian);
}

void	matrix_multiplication(double *matrix_1[4], double *matrix_2[4])
{
	
}
