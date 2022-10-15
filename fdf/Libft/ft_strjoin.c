/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:35:54 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:26 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*array;
	int		i;
	int		z;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	array = (char *)malloc(sizeof(char) * (size +1));
	if (array == NULL)
		return (NULL);
	while (s1[++i])
		array[i] = s1[i];
	z = 0;
	while (s2[z])
		array[i++] = s2[z++];
	array[i] = '\0';
	return (array);
}
