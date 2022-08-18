/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:08:44 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/22 21:20:26 by ekeen-wy         ###   ########.fr       */
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
		num *= -1;
	while (!(num >= 0 && num <= 9))
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	long			num;
	unsigned int	power;
	char			s;

	num = (long) n;
	power = ft_recursive_power(10, count(n));
	if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	while (power > 0)
	{
		s = '0' + (num / power);
		write(fd, &s, 1);
		num -= ((num / power) * power);
		power /= 10;
	}
}
