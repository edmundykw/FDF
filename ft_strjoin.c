/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:08:39 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/01/11 11:35:04 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2 != '\0')
		ptr[i++] = *s2++;
	*(ptr + len) = '\0';
	return (ptr);
}
