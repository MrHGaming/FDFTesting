/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:24:51 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/03 17:11:02 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(int nbr, int fd)
{
	int	len;

	len = 0;
	if (nbr >= 0)
		len += ft_putnbr_fd(nbr, fd);
	else if (nbr < 0)
		len += ft_putnbr_long_fd((4294967296 + nbr), fd);
	return (len);
}
