/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:42 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/03 19:28:53 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_matrix_memory(t_map *map)
{
	t_matrix	*matrix;
	double		**coordinates;

	matrix = map->rotation_coord;
	coordinates = map->rotation_coord->i;
	matrix->i = (t_matrix **)malloc(sizeof(*coordinates) * 4);
	matrix->j = (t_matrix **)malloc(sizeof(*coordinates) * 4);
	matrix->k = (t_matrix **)malloc(sizeof(*coordinates) * 4);
	matrix->w = (t_matrix **)malloc(sizeof(*coordinates) * 4);
	if (matrix-> i == NULL || matrix->j == NULL
		|| matrix->k == NULL || matrix->w == NULL)
	{
		p_error("Memory allocation failed\n");
	}
}

static void	init_matrix_coord_mem(t_map *map)
{
	size_t	index;

	index = 0;
	while (map->rotation_coord)
	{
		
	}
}

void	rotate_z(t_map *map, double radian)
{
	double	*num;

	map->rotation_coord->i[x] = cos(radian);
}

void	rotation_matrix(t_map *map, double radian)
{
	size_t	index;

	init_matrix_memory(map);
}
