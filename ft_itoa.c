/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:11:19 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/22 20:24:32 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count(int n)
{
	unsigned int	len;
	long			num;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (!(num >= 0 && num <= 9))
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	long			num;
	unsigned int	len;

	num = (long) n;
	len = count(num) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (num == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		num *= -1;
		ptr[0] = '-';
	}
	while (num > 0)
	{
		ptr[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (ptr);
}
