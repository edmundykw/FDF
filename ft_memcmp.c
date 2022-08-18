/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:14:59 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/03 16:10:50 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr;
	const char	*ptr2;

	ptr = s1;
	ptr2 = s2;
	while (n-- != 0)
	{
		if (*ptr != *ptr2)
		{
			return ((unsigned char)(*ptr) - (unsigned char)(*ptr2));
		}
		ptr++;
		ptr2++;
	}
	return (0);
}
