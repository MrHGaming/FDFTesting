/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:12:12 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/24 16:29:49 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void	*s1, const	void	*s2, size_t n)
{
	size_t				i;
	const unsigned char	*d;
	const unsigned char	*s;

	i = 0;
	d = (const unsigned char *)s1;
	s = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && d[i] == s[i])
	{
		i++;
	}
	return ((d[i] - s[i]));
}
