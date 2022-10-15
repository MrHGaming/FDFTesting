/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:53:37 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:35 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*d;
	const unsigned char	*s;

	i = 0;
	d = (const unsigned char *)s1;
	s = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (d[i] && s[i] && d[i] == s[i] && i < (n - 1))
		i++;
	return (d[i] - s[i]);
}
