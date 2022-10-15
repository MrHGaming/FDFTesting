/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:48:38 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/25 17:37:14 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkerror(char *str)
{
	size_t	c;
	size_t	cf;
	size_t	l;

	l = ft_strlen(str);
	c = 0;
	if (str[0] == '\0' || l == 1)
		return (0);
	while (str[c] != '\0')
	{
		if (str[c] <= 32 || str[c] == 127 || str[c] == 43 || str[c] == 45)
			return (0);
		cf = c + 1;
		while (cf < ft_strlen(str))
		{
			if (str[c] == str[cf])
				return (0);
			cf++;
		}
		c++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, int fd)
{
	int		lnt;
	int		eror;
	long	nb;

	lnt = ft_strlen(base);
	eror = checkerror(base);
	nb = nbr;
	if (eror == 1)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb < lnt)
		{
			ft_putchar_fd(base[nb], fd);
		}
		if (nb >= lnt)
		{
			ft_putnbr_base(nb / lnt, base, fd);
			ft_putnbr_base(nb % lnt, base, fd);
		}
	}
}
