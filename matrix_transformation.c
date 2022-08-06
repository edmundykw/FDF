/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:09:27 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/06 19:38:48 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(double *matrix[4], double degree)
{
	double	radian;

	radian = degree_to_radian(degree);
	matrix[xi][xi] = cos(radian);
	matrix[xi][yi] = sin(radian);
	matrix[yi][xi] = -sin(radian);
	matrix[yi][yi] = cos(radian);
}

void	rotate_x(double *matrix[4], double degree)
{
	double	radian;

	radian = degree_to_radian(degree);
	matrix[yi][yi] = cos(radian);
	matrix[yi][zi] = sin(radian);
	matrix[zi][yi] = -sin(radian);
	matrix[zi][zi] = cos(radian);
}

void	matrix_multiply(double *vector, double *matrix[4],
		double *transformed, size_t dimension)
{
	size_t	col;
	size_t	row;
	size_t	v_row;
	double	value;

	row = 0;
	while (row < dimension)
	{
		col = 0;
		v_row = 0;
		value = 0;
		while (col < dimension)
		{
			value += vector[v_row] * matrix[col][row];
			col++;
			v_row++;
		}
		transformed[row] = value;
		row++;
	}
}

/* This is to translate the center of the image to the origin (0,0) and
perform the needed rotation for isometric projection, and then translate
the center of the image to its intial location.
*/
void	translate(double *vector, double *matrix[4], size_t dimension)
{
	double	*transformed;

	transformed = allocate_vector_memory(dimension);
	matrix_multiply(vector, matrix, transformed, dimension);
	matrix[wi][xi] = vector[xi] - transformed[xi];
	matrix[wi][yi] = vector[yi] - transformed[yi];
	matrix[wi][zi] = vector[zi] - transformed[zi];
	free(transformed);
}

void	isometric_projection_matrix(t_map *map)
{
	size_t	col;
	double	*img_midpoint;

	init_matrices(map);
	rotate_z(map->matrices->matrix_z, 45);
	rotate_x(map->matrices->matrix_x, 54.74);
	col = -1;
	while (++col < map->vector_size)
	{
		matrix_multiply(map->matrices->matrix_z[col], map->matrices->matrix_x,
			map->matrices->matrix_xz[col], map->vector_size);
	}
	img_midpoint = find_img_midpoint(map);
	translate(img_midpoint, map->matrices->matrix_xz, map->vector_size);
}
