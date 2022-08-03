/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:34:50 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/01 12:35:01 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char(char **str)
{
	char	**temp;

	temp = str;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

void	free_struct(t_map *map)
{
	t_vector	**temp;
	size_t		size;

	temp = map->vector;
	size = 0;
	while (size++ < map->x_row * map->y_column)
	{
		free(*temp);
		temp++;
	}
	free(map->vector);
}
