/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:03:43 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/28 15:41:25 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	is_valid_dimension(t_map *map, size_t y_size)
{
	if (map->y_column != y_size)
	{
		p_error("Error: Invalid map dimension\n");
		exit(EXIT_FAILURE);
	}
}

static void	store_input(t_map *map, int *line_read, size_t y_size)
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
	int		*line_read;
	char	**split;

	index = -1;
	y_size = 0;
	split = ft_split(line, ' ');
	while (split[++index] != NULL)
		y_size++;
	if (map->y_column == 0)
		map->y_column = y_size;
	line_read = (int *)malloc(sizeof(int) * y_size);
	index = -1;
	while (split[++index] != NULL)
		line_read[index] = ft_atoi(split[index]);
	free_char(split);
	store_input(map, line_read, y_size);
}

static void	read_file(t_map *map, int fd)
{
	char	*line;
	size_t	x_size;

	line = get_next_line(fd);
	if (line == NULL)
		p_error("Error: File is empty\n");
	x_size = 1;
	while (line != NULL)
	{
		convert_line(map, line);
		free(line);
		line = get_next_line(fd);
		x_size++;
	}
	map->x_row = x_size;
}

void	process_input(t_map *map, char *path)
{
	int		fd;
	char	*file;
	char	**process_path;

	process_path = ft_split(path, '/');
	file = get_file(process_path);
	fd = check_file_status(file);
	free_char(process_path);
	read_file(map, fd);
}
