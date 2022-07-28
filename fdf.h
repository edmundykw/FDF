/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:16:40 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:32 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct i_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_matrix
{
	int	*i;
	int	*j;
	int	*k;
}				t_matrix;

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}				t_vector;

typedef struct s_data {
	size_t		x_row;
	size_t		y_column;
	t_list		*temp_map;
	t_vector	**vector;
	t_matrix	*rotation;
}				t_map;

/* utils.c */
void	free_char(char **str);
void	p_error(char *str);
int		check_file_status(char *file);
char	*get_file(char **str);

/* parse_map.c*/
void	process_input(t_map *map, char *file);

/* draw_line.c */
void	draw_line(int *x, int *y, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif