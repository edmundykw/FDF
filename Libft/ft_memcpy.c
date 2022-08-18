/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:18:24 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/29 17:08:48 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = dest;
	if (dest == src)
		return (dest);
	while (n-- != 0)
	{
		*ptr = *(unsigned char *) src;
		ptr++;
		src++;
	}
	return (dest);
}
