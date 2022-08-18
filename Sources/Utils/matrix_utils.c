/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:16:16 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:26:45 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Converts degree to radian for the math library. */

double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180));
}

/* Multiplies the vector with the matrix specified. The result is kept
in the transformed pointer.
 */

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

static void	allocate_matrix_memory(double *matrix[4], size_t dimension)
{
	size_t	index;
	double	*temp;

	index = -1;
	while (++index < dimension)
	{
		temp = allocate_vector_memory(dimension);
		check_mem(temp);
		matrix[index] = temp;
	}
}

/* Creates an identity matrix. */

void	identity_matrix(double *matrix[4], size_t dimension)
{
	size_t	index;
	size_t	row;

	index = -1;
	allocate_matrix_memory(matrix, dimension);
	while (++index < dimension)
	{
		row = -1;
		while (++row < dimension)
		{
			if (index == row)
				matrix[index][row] = 1;
			else
				matrix[index][row] = 0;
		}
	}
}
