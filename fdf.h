/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:16:40 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/17 20:28:03 by ekeen-wy         ###   ########.fr       */
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
# define WIND_WIDTH 1440
# define WIND_HEIGHT 920
# define VECTOR_SIZE 4

enum e_xy_pair
{
	x_1 = 0,
	y_1 = 1,
	x_2 = 2,
	y_2 = 3
};

enum e_dx_dy
{
	dy = 0,
	dx = 1,
	epsilon = 2
};

enum e_coordinate
{
	xi = 0,
	yi = 1,
	zi = 2,
	wi = 3
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
	double	*matrix_z[4];
	double	*matrix_x[4];
	double	*matrix_xz[4];
}				t_matrix;

typedef struct s_coordinates
{
	double	x_y[4];
	double	dy;
	double	dx;
	double	epsilon;
}				t_coord;

typedef struct s_data {
	size_t		x_column;
	size_t		y_row;
	t_list		*temp_map;
	double		**vector;
	t_matrix	*matrices;
	t_coord		*coord;
	size_t		vector_size;
	double		unit_vector_size;
}				t_map;

/* error_utils.c */
void		p_error(char *str);
int			check_file_status(char *file);
void		check_mem(void	*ptr);

/* general_utils.c */
int			absolute(double num);
void		swap(double x_y[4]);

/* map_utils.c */
void		is_valid_dimension(t_map *map, size_t y_size);
void		set_unit_vector(t_map *map);

/* memory_utils.c */
void		free_char(char **str);
void		free_vector(t_map *map);
void		free_matrix(t_map *map);
double		*allocate_vector_memory(size_t dimension);

/* parse_map.c*/
void		process_input(t_map *map, char *file);

/* build_map.c*/
void		build_map(t_map *map);

/* bresenhams.c */
void		bresenhams(t_map *map, t_data *img);

/* drawing_utils.c */
void		my_mlx_pixel_put(t_data *img, int x, int y);
void		plot_line_low(t_coord *coord, t_data *img);
void		plot_line_high(t_coord *coord, t_data *img);
void		draw_line(double *v1, double *v2, t_data *img);

/* matrix_init.c */
void		init_matrices(t_map *map);

/* matrix_transformation.c */
void		scale(double *matrix[4], double x, double y, double z);
void		rotate_z(double *matrix[4], double degree);
void		rotate_x(double *matrix[4], double degree);
void		translate(double *matrix[4], double x, double y, double z);
void		isometric_projection_matrix(t_map *map);

/* matrix_utils.c */
double		degree_to_radian(double degree);
void		matrix_multiply(double *vector, double *matrix[4],
				double *transformed, size_t dimension);
void		identity_matrix(double *matrix[4], size_t dimension);
#endif