/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:16:40 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/03 19:16:50 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

enum e_coordinates
{
	x1 = 0,
	y1 = 1,
	x2 = 2,
	y2 = 3
};

enum e_dx_dy
{
	dy = 0,
	dx = 1,
	epsilon = 2
};

enum e_unit_vector
{
	x = 0,
	y = 1,
	z = 2,
	w = 3
};

typedef struct i_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_matrix
{
	double	**i;
	double	**j;
	double	**k;
	double	**w;
}				t_matrix;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vector;

typedef struct s_data {
	size_t		x_row;
	size_t		y_column;
	t_list		*temp_map;
	t_vector	**vector;
	t_matrix	*rotation_coord;
	int			unit_vector_size;
}				t_map;

/* error_utils.c */
void	p_error(char *str);
int		check_file_status(char *file);

/* map_utils.c */
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	is_valid_dimension(t_map *map, size_t y_size);
void	set_unit_vector(t_map *map);

/* memory_utils.c */
void	free_char(char **str);
void	free_struct(t_map *map);

/* parse_map.c*/
void	process_input(t_map *map, char *file);

/* build_map.c*/
void	build_map(t_map *map);

/* bresenhams.c */
void	bresenhams(t_map *map, t_data *img);
#endif