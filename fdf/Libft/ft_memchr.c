/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:58:13 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:08 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const	void	*s, int c, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (i == (n - 1))
			return (NULL);
		s++;
		i++;
	}
	return ((void *)s);
}
