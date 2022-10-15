/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:15:05 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:39 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	int		len;

	d = (char *)s;
	len = ft_strlen(d);
	if ((unsigned char)c == '\0')
		return (d + len);
	len = len - 1;
	while (len >= 0)
	{
		if (d[len] == (unsigned char)c)
			return (d + len);
		len--;
	}
	return (NULL);
}
