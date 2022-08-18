/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:27:04 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/26 14:37:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (len-- > 0)
	{
		*(ptr + i) = (*f)(i, s[i]);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
