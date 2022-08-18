/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:48:56 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/08/18 17:26:30 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

/* Catches the keys pressed and proccess it accordingly. */

int	close_wind(void)
{
	ft_putstr_fd("Closed window.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_event_handler(int key)
{
	if (key == ESC)
		close_wind();
	return (0);
}
