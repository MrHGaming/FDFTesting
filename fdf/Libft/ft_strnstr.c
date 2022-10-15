/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:55:08 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:37 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	z;
	char	*h;
	char	*n;

	i = 0;
	if (len == 0 && !haystack)
		return (0);
	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == '\0')
		return (h);
	while (h[i] && ft_strlen(n) <= len--)
	{
		z = 0;
		while (h[i + z] == n[z])
		{
			if (n[z + 1] == '\0')
				return (h + i);
		z++;
		}
		i++;
	}
	return (NULL);
}
