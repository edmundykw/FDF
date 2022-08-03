/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:03:43 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/03 13:54:21 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_coord(t_map *map)
{
	size_t		index;
	t_vector	**coord;

	index = 0;
	coord = map->vector;
	while (++index < map->x_row * map->y_column)
	{
		(coord[index])->x = (coord[index])->x + map->unit_vector_size;
		(coord[index])->y = (coord[index])->y + map->unit_vector_size;
	}
}

static void	store_input(t_map *map, double *line_read, size_t y_size)
{
	t_list	*new;

	if (map->temp_map != NULL)
		is_valid_dimension(map, y_size);
	new = ft_lstnew(line_read);
	ft_lstadd_back(&map->temp_map, new);
}

static void	convert_line(t_map *map, char *line)
{
	size_t	y_size;
	size_t	index;
	double	*line_read;
	char	**split;
	char	*temp_line;

	index = -1;
	y_size = 0;
	temp_line = ft_strtrim(line, " \n");
	split = ft_split(temp_line, ' ');
	while (split[++index] != NULL)
		y_size++;
	if (map->y_column == 0)
		map->y_column = y_size;
	line_read = (double *)malloc(sizeof(*line_read) * y_size);
	if (line_read == NULL)
		p_error("Memory allocation failed\n");
	index = -1;
	while (split[++index] != NULL)
		line_read[index] = (double)ft_atoi(split[index]);
	free_char(split);
	free(temp_line);
	store_input(map, line_read, y_size);
}

void	read_file(t_map *map, int fd)
{
	char	*line;
	size_t	x_size;

	line = get_next_line(fd);
	if (line == NULL)
		p_error("Error: File is empty\n");
	x_size = 0;
	while (line != NULL)
	{
		convert_line(map, line);
		free(line);
		line = get_next_line(fd);
		x_size++;
	}
	map->x_row = x_size;
}

void	process_input(t_map *map, char *file)
{
	int		fd;

	fd = check_file_status(file);
	read_file(map, fd);
	build_map(map);
	set_unit_vector(map);
	transform_coord(map);
	ft_lstclear(&map->temp_map, free);
}
