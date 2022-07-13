/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:16:40 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/13 00:10:21 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
//# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	t_list	*map;
	int		y_dimension;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* utils.c */
int		check_file_status(char *file);
void	free_char(char **str);
void	p_error(char *str);

/* parse_map.c*/
void	process_input(t_data *img, char *file);
#endif