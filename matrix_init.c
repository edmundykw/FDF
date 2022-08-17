/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:42 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/17 20:55:44 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_matrix(t_map *map)
{
	map->matrices = (t_matrix *)malloc(sizeof(*map->matrices));
	check_mem(map->matrices);
}

void	init_matrices(t_map *map)
{
	init_matrix(map);
	identity_matrix(map->matrices->matrix_x, map->vector_size);
	identity_matrix(map->matrices->matrix_z, map->vector_size);
	identity_matrix(map->matrices->matrix_xz, map->vector_size);
}
