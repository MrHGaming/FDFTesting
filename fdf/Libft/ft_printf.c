/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:50:34 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/03 17:11:06 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_check(const char c, va_list argument)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(argument, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(argument, char *), 1);
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	else if (c == 'i' || c == 'd')
		len += ft_putnbr_fd(va_arg(argument, int), 1);
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(argument, unsigned int), c);
	else if (c == 'p')
		len += ft_print_adr(va_arg(argument, long long unsigned));
	else if (c == 'u')
		len += ft_print_u(va_arg(argument, int), 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	argument;

	i = 0;
	len = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += print_check(str[i + 1], argument);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(argument);
	return (len);
}
