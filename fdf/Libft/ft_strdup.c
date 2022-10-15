/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:59:33 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:24 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*array;
	int		z;

	i = 0;
	z = 0;
	i = ft_strlen(src);
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (array == NULL)
		return (NULL);
	while (src[z] != '\0')
	{
		array[z] = src[z];
		z++;
	}
	array[z] = '\0';
	return (array);
}
