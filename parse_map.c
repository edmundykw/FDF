/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:03:43 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/13 11:54:26 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	is_valid_dimension(t_data *img, int y_height)
{
	if (img->y_dimension != y_height)
	{
		ft_lstclear(&img->map, free);
		p_error("Error: Invalid map dimension\n");
	}
}

static void	create_map(t_data *img, int *line_read, int y_height)
{
	t_list	*new;

	if (img->map != NULL)
		is_valid_dimension(img, y_height);
	new = ft_lstnew(line_read);
	ft_lstadd_back(&img->map, new);
}

static void	convert_line(t_data *img, char *line)
{
	size_t	y_height;
	size_t	index;
	int		*line_read;
	char	**split;

	index = -1;
	y_height = 0;
	split = ft_split(line, ' ');
	while (split[++index] != NULL)
		y_height++;
	if (img->y_dimension == 0)
		img->y_dimension = y_height;
	line_read = (int *)malloc(sizeof(int) * y_height);
	index = -1;
	while (split[++index] != NULL)
		line_read[index] = ft_atoi(split[index]);
	free_char(split);
	create_map(img, line_read, y_height);
}

static void	read_file(t_data *img, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		p_error("Error: File is empty\n");
	while (line != NULL)
	{
		convert_line(img, line);
		free(line);
		line = get_next_line(fd);
	}
}

void	process_input(t_data *img, char *file)
{
	int	fd;

	fd = check_file_status(file);
	read_file(img, fd);
}
