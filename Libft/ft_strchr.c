/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:21:15 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/01/13 14:15:21 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		*temp;

	i = ft_strlen(s);
	temp = (char *) s;
	while (i + 1 != 0)
	{
		if (*temp == (char) c)
			return ((char *) temp);
		temp++;
		i--;
	}
	return (NULL);
}
