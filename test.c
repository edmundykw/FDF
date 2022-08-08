/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:01:02 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/07 00:02:27 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	printfmatrix(t_map *map)
{
	double	**temp;
	size_t	count;
	size_t	i;

	count = -1;
	temp = map->matrices->matrix_xz;
	while (++count < map->vector_size)
	{
		i = 0;
		printf("Col: %ld\n", count);
		while (i < map->vector_size)
		{
			printf("Row: %ld\n", i);
			printf("%f \n", temp[count][i]);
			i++;
		}
	}
}

printf("x: %f y: %f, z: %f\n", x_cor, y_cor, *num);