/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:16:54 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/31 21:49:09 by ekeen-wy         ###   ########.fr       */
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

void	p_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	check_file_status(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x <= 720 && y <= 1080)
	{
		dst = img->addr + (y * img->line_length
				+ x *(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
