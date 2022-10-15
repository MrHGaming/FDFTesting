/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:02:28 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/03 17:10:56 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_hex(unsigned int nbr, const char c)
{
	if (nbr >= 16)
	{
		print_hex((nbr / 16), c);
		print_hex((nbr % 16), c);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((nbr + 'a' - 10), 1);
			else if (c == 'X')
				ft_putchar_fd((nbr + 'A' - 10), 1);
		}
	}
}

int	ft_print_hex(unsigned int nbr, const char c)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += write(1, "0", 1);
	else
		print_hex(nbr, c);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
