/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:14:16 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:25:13 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

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

/* Create the required matrices and transformations to render
the map.
 */

static void	render_image(t_map *map, t_data *img, void *mlx, void *mlx_win)
{
	init_matrices(map);
	isometric_projection_matrix(map);
	bresenhams(map, img);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

/* Creates the window and image to be used to render the map as pixels. */

static void	init_windows(t_map *map)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(*img));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIND_WIDTH, WIND_HEIGHT, "FDF!");
	img->img = mlx_new_image(img->mlx, WIND_WIDTH, WIND_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	map->img = img;
}

/*  
The FDF program consists of these major portions:
1. Reading and processing the input used as a map.
2. Creating an image that will be used to draw pixels on it based
on the input map. A window will be created to tell the program 
where to output the image. 
3. Creating the relevant transformation matrices (4 x 4 matrix). 
These matrices are used to apply the appropriate rotation and
translation to achieve the isometric projection.
*/

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		p_error("Error: Please provide only one map\n");
	init_map(&map);
	process_input(&map, argv[1]);
	init_windows(&map);
	render_image(&map, map.img, map.img->mlx, map.img->mlx_win);
	mlx_key_hook(map.img->mlx_win, ft_event_handler, &map);
	mlx_hook(map.img->mlx_win, 17, 0, close_wind, 0);
	mlx_loop(map.img->mlx);
}
