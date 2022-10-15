/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:37:20 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/25 19:41:57 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_long(long b, long a)
{
	while (b >= 10)
	{
		b = b / 10;
		a ++;
	}
	return (a);
}

long	ft_count2_long(long x, long count)
{
	while (count > 1)
	{
		x = x * 10;
		count --;
	}
	return (x);
}

void	ft_write_long(long nb2, long x2, long count2, int fd)
{
	long	num;

	while (count2 >= 1)
	{
		num = (nb2 / x2) + 48;
		write (fd, &num, 1);
		nb2 = nb2 % x2;
		x2 = x2 / 10;
		count2 --;
	}
}

int	ft_putnbr_long_fd(long n, int fd)
{
	int		count;
	long	x;
	long	nb2;

	count = 1;
	nb2 = n;
	if (fd < 0)
		return (0);
	if (n == -2147483648)
		return (write (fd, "-2147483648", 11));
	if (n >= 0)
	{
		count = ft_count_long(n, count);
		x = 1;
		x = ft_count2_long(x, count);
		ft_write_long (nb2, x, count, fd);
	}
	else
	{
		write (fd, "-", 1);
		n = n * -1;
		count = ft_putnbr_long_fd(n, fd);
		count++;
	}
	return (count);
}
