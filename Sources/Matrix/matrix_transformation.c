/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:09:27 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:26:01 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

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

/* This is technically a shear in 4D. But to avoid using vector
addition for translation in 3D, the translation in 3D is represented
as a shear in 4D.
 */
void	translate(double *matrix[4], double x, double y, double z)
{
	matrix[wi][xi] = x;
	matrix[wi][yi] = y;
	matrix[wi][zi] = z;
}

void	isometric_projection_matrix(t_map *map)
{
	size_t	col;

	rotate_z(map->matrices->matrix_z, 45);
	rotate_x(map->matrices->matrix_x, 54.74);
	col = -1;
	while (++col < map->vector_size)
	{
		matrix_multiply(map->matrices->matrix_z[col], map->matrices->matrix_x,
			map->matrices->matrix_xz[col], map->vector_size);
	}
	translate(map->matrices->matrix_xz, WIND_WIDTH / 2, WIND_HEIGHT / 3, 0);
}
