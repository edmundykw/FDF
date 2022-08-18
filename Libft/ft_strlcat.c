/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:47:24 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/26 16:01:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	int				i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = size - ft_strlen(dest) - 1;
	if (size < ft_strlen(dest) + 1 || size == 0)
		return (size + ft_strlen(src));
	else
	{
		while (*src != '\0' && j-- != 0)
		{
			*(dest + i) = *src;
			i++;
			src++;
		}
		*(dest + i) = '\0';
	}
	return (ft_strlen(dest) + ft_strlen(src));
}
