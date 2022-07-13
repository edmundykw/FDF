/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:14:16 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/13 12:04:54 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
1. Assuming I have the input read from the text file. Using GNL, splitting it and
converting it to actual integers. What about hexa address for colors?
And input in the form of int, hex?
(*Need to take care of colors and varying length
of rows and columns)
2. Handle for missing values in map when reading
(output as error is there's a missing value in a line). The long string of num is
broken (e.g. 0 0 1 0   0 1 0)
3. I need to have a window open. How to determine the size of the window?
As long as the window is bigger than the required map and the image is the same
size as the required map.
Don't print out the portion of map if it exceeds the size of the window.
4. Come up with the size of the image based on the number of points. Also consider
how many pixels can fit into an area of the image (number of squares produced by
multiplying width and height).
5. Draw pixels to this image. Handle both tve and -ve integers for elevations.
Handle for transformation of camera's view (bonus).
6. Output it in a loop. 
*/

/* 
Data structure for the project.

For the map, I would need to store the (x, y) coordinates based on the
width and col provided. And also store the altitude. Either a 4x1 matrix
or a vector.

How does a vector and a matrix apply for this project?
Assumption: each number represents a point. I connect each number to 
the next to form a line and so forth until a straight line is formed.

29/06/2022
Figure out the relationship vectors, matrices for this project.
Learn how to draw a square, a triangle and a star. Check on line drawing
algo.

Bonus: learn how to render 2D in 3D


int	*transformed(int x, int y)
{
	int	*trans_codnate;

	trans_codnate = (int *)malloc(sizeof(int *) * 2);
	trans_codnate[0] = (x * 1) + (y * -1);
	trans_codnate[1] = (x * 0.5) + (y * 0.5);
	return (trans_codnate);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		*trans;

	trans = transformed(x, y);
	dst = data->addr + (trans[1] * data->line_length
			+ trans[0] * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	free(trans);
}*/

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc < 2)
		p_error("Error: Map not provided\n");
	img.map = NULL;
	img.y_dimension = 0;
	process_input(&img, argv[1]);
	ft_lstclear(&img.map, free);
}
