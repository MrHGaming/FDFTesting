/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:54:57 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/09 18:11:22 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_word_count(const char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (!str[i])
		return (0);
	if (str[i] != c)
		word_count = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			word_count++;
		i++;
	}
	return (word_count);
}

static char	*ft_dup(const char *str, int pos, char c)
{
	int		z;
	int		y;
	char	*array;

	z = pos;
	y = 0;
	while (str[pos] == c && str[pos])
	{
		z++;
		pos++;
	}
	while (str[pos] != c && str[pos])
		pos++;
	array = (char *)malloc(sizeof(char) * (pos - z) + 1);
	if (array == NULL)
		return (0);
	while (z < pos)
	{
		array[y] = str[z];
		z++;
		y++;
	}
	array[y] = '\0';
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**array;
	int		x;

	if (s == NULL)
		return (NULL);
	word_count = ft_word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (0);
	x = 0;
	i = 0;
	while (i < word_count)
	{
		while (s[x] == c && s[x])
			x++;
		array[i] = ft_dup(s, x, c);
		if (array[i] == NULL)
			return (0);
		x = x + ft_strlen(array[i]) + 1;
		i++;
	}
	array[i] = 0;
	return (array);
}
