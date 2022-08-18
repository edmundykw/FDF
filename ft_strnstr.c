/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:17:15 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/27 21:39:39 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	i;

	h = 0;
	if (*(char *) little == '\0')
		return ((char *) big);
	if ((int) len < 0)
		len = ft_strlen(big);
	while (*(big + h) != '\0' && big + h <= big + len - 1)
	{
		i = 0;
		if (*(big + h) == *(little + i))
		{
			while (*(little + i) != '\0')
			{
				if (*(big + h + i) == *(little + i)
					&& big + h + i <= big + len - 1)
					if (i + 1 == ft_strlen(little))
						return ((char *)(big + h));
				i++;
			}
		}
		h++;
	}
	return (NULL);
}
