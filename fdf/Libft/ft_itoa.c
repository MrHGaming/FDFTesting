/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:32:51 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/22 17:47:34 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_len(long nbr)
{
	long	len;

	if (nbr == 0)
		return (2);
	len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

long	ft_power(long len)
{
	long	result;

	result = 1;
	while (len - 1 > 1)
	{
		result = result * 10;
		len--;
	}
	return (result);
}

char	*itoa_sup(long len, long nbr, long sign)
{
	char	*result;
	int		i;
	long	power;

	i = 0;
	power = 1;
	len = len + ft_len(nbr);
	result = (char *)malloc(sizeof(char) * (len));
	if (result == NULL)
		return (NULL);
	power = ft_power(len);
	if (sign < 0)
	{
		result[i++] = '-';
		power = power / 10;
	}
	while (i < len && power != 0)
	{
		result[i++] = (nbr / power) + '0';
		nbr = nbr % power;
		power = power / 10;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int nbr)
{
	int		sign;
	long	len;
	char	*result;
	long	longnbr;

	len = 0;
	sign = 1;
	longnbr = nbr;
	if (longnbr < 0)
	{
		len++;
		sign = -1;
		longnbr *= sign;
	}
	result = itoa_sup(len, longnbr, sign);
	return (result);
}
