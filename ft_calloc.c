/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:35:29 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/07/21 13:28:33 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned long	i;

	i = nmemb * size;
	if (i > INT_MAX || (size > INT_MAX && nmemb > INT_MAX))
		return (NULL);
	ptr = (char *) malloc(i);
	if (ptr == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	ft_bzero(ptr, i);
	return (ptr);
}
