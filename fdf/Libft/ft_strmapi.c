/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:50 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 21:18:50 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*array;
	int		len;

	if (!s)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	array = (char *)malloc(sizeof(char) * (len +1));
	if (array == NULL)
		return (NULL);
	while (++i < len)
		array[i] = f(i, s[i]);
	array[i] = '\0';
	return (array);
}
