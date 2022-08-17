/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:14:16 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/17 19:06:39 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map)
{
	map->y_row = 0;
	map->x_column = 0;
	map->temp_map = NULL;
	map->vector = NULL;
	map->matrices = NULL;
	map->vector_size = VECTOR_SIZE;
	map->coord = NULL;
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	map;
	void	*mlx;
	void	*mlx_win;

	if (argc < 2)
		p_error("Error: Map not provided\n");
	init_map(&map);
	process_input(&map, argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIND_WIDTH, WIND_HEIGHT, "FDF!");
	img.img = mlx_new_image(mlx, WIND_WIDTH, WIND_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	init_matrices(&map);
	isometric_projection_matrix(&map);
	bresenhams(&map, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free_vector(&map);
	free_matrix(&map);
}
