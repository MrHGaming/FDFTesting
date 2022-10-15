/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:02:07 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/24 16:30:21 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	l;

	i = (size_t)start;
	l = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		c = (char *)malloc(sizeof(char));
		if (c == NULL)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (c == NULL)
		return (NULL);
	while (i < (len + start) && s[i])
		c[l++] = s[i++];
	c[l] = '\0';
	return (c);
}
