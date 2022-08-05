/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:42 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/04 23:58:50 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	allocate_matrix_memory(double *matrix[4], size_t dimension)
{
	size_t	index;
	double	*temp;

	index = -1;
	while (++index < dimension)
	{
		temp = (double *)malloc(sizeof(*temp));
		if (temp == NULL)
			p_error("Memory allocation failed\n");
		matrix[index] = temp;
	}
}

static void	identity_matrix(double *matrix[4], size_t dimension)
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
			matrix[index][row] = 0;
		}
	}
}

static void	init_matrix(t_map *map)
{
	map->matrices = (t_matrix *)malloc(sizeof(*map->matrices));
	if (map->matrices == NULL)
		p_error("Memory allocation failed\n");
}

void	init_matrices(t_map *map)
{
	init_matrix(map);
	identity_matrix(map->matrices->matrix_x, map->vector_size);
	identity_matrix(map->matrices->matrix_z, map->vector_size);
	identity_matrix(map->matrices->matrix_xz, map->vector_size);
}
