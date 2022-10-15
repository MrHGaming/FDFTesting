/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:09:50 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/24 18:16:10 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int b, int a)
{
	while (b >= 10)
	{
		b = b / 10;
		a ++;
	}
	return (a);
}

int	ft_count2(int x, int count)
{
	while (count > 1)
	{
		x = x * 10;
		count --;
	}
	return (x);
}

void	ft_write(int nb2, int x2, int count2, int fd)
{
	int	num;

	while (count2 >= 1)
	{
		num = (nb2 / x2) + 48;
		write (fd, &num, 1);
		nb2 = nb2 % x2;
		x2 = x2 / 10;
		count2 --;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	x;
	int	nb2;

	count = 1;
	nb2 = n;
	if (fd < 0)
		return (0);
	if (n == -2147483648)
		return (write (fd, "-2147483648", 11));
	if (n >= 0)
	{
		count = ft_count(n, count);
		x = 1;
		x = ft_count2(x, count);
		ft_write (nb2, x, count, fd);
	}
	else
	{
		write (fd, "-", 1);
		n = n * -1;
		count = ft_putnbr_fd(n, fd);
		count++;
	}
	return (count);
}
