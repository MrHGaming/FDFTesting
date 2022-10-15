/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:23:22 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/03 17:10:50 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_adr(long long unsigned nbr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_ptr(nbr, 'x');
	return (len);
}
