/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:26:49 by mohouhou          #+#    #+#             */
/*   Updated: 2022/09/21 18:37:40 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*array;
	size_t	size;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (ft_strrchr(set, s1[size]) && size != 0)
		size--;
	array = ft_substr(s1, 0, (size + 1));
	return (array);
}
