/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:13:05 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/01/25 17:47:45 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(char *s, char c)
{
	char			*ptr;
	unsigned int	count;

	count = 0;
	ptr = s;
	while (*ptr != '\0')
	{
		while (*ptr == c && *ptr != '\0')
			ptr++;
		if (*ptr != c && *ptr != '\0')
			count++;
		while (*ptr != c && *ptr != '\0')
			ptr++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	k;
	char			**ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char **)ft_calloc(word_count((char *) s, c) + 1, sizeof(ptr));
	if (ptr == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		start = i;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if (start < i)
			ptr[k++] = ft_substr(s + start, 0, i - start);
		if (*(s + i) != '\0')
			i++;
	}
	*(ptr + k) = NULL;
	return (ptr);
}
