/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:03:43 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/29 19:56:59 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	is_valid_dimension(t_map *map, size_t y_size)
{
	if (map->y_column != y_size)
		p_error("Error: Invalid map dimension\n");
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
	char	*temp_line;

	index = -1;
	y_size = 0;
	temp_line = ft_strtrim(line, " \n");
	split = ft_split(temp_line, ' ');
	while (split[++index] != NULL)
		y_size++;
	if (map->y_column == 0)
		map->y_column = y_size;
	line_read = (int *)malloc(sizeof(int) * y_size);
	if (line_read == NULL)
		p_error("Memory allocation failed\n");
	index = -1;
	while (split[++index] != NULL)
		line_read[index] = ft_atoi(split[index]);
	free_char(split);
	free(temp_line);
	store_input(map, line_read, y_size);
}

static void	read_file(t_map *map, int fd)
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
	ft_lstclear(&map->temp_map, free);
}
