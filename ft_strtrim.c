/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:50:50 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/21 14:59:28 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	end = ft_strchr(s1, '\0') - 1;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	ptr = ft_substr(s1, 0, end - s1 + 1);
	return (ptr);
}
