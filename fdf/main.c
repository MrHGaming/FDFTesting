/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:05:32 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/15 19:30:35 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if(x >= 1400 || y >= 800)
		return ;
printf("Am I seg here?\n\n\n");
printf("%d  %d\n", (y * data->line_length), (x * (data->bits_per_pixel / 8)));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	***ft_convert_3dchar_3dint(char ****str, int size, int linenum)
{
	int	***array;
	int	i;
	int	x;

	i = 0;
	ft_printf("done reading \n");
	array = (int ***)malloc(sizeof(int **) * linenum);
	while (i < linenum)
	{
		x = 0;
		array[i] = (int **)malloc(sizeof(int *) * size);
		while (x < size)
		{
			array[i][x] = (int *)malloc(sizeof(int) * 2);
			array[i][x][0] = ft_atoi(str[i][x][0]);
			if (str[i][x][1] == 0)
				array[i][x][1] = 0;
			else
				array[i][x][1] = ft_atoi_base(str[i][x][1], "0123456789abcdef");
			x++;
		}
		i++;
	}
	return (array);
}

char	****ft_convert_3d_to_4d(char ***str, int linenum, char **str2)
{
	int		i;
	int		x;
	char	****array;

	i = 0;
	array = (char ****)malloc(sizeof(char ***) * (linenum + 1));
	while (i < linenum)
	{
		x = 0;
		array[i] = malloc(sizeof(char **) * (ft_word_count(str2[i], ' ') + 1));
		while (x < ft_word_count(str2[i], ' '))
		{
			array[i][x] = ft_split(str[i][x], ',');
			x++;
		}
		i++;
	}
	return (array);
}

int	***ft_convert_string_to_num(char **str, int linenum)
{
	int		i;
	char	***array;
	char	****array2;
	int		***intarray;
	int		size;

	i = 0;
	array = (char ***)malloc(sizeof(char **) * (linenum + 1));
	while (i < linenum)
	{
		array[i] = ft_split(str[i], ' ');
		i++;
	}
	array2 = ft_convert_3d_to_4d(array, linenum, str);
	size = ft_word_count(str[1], ' ');
	ft_printf("%d \n", size);
	intarray = ft_convert_3dchar_3dint(array2, size, linenum);
	return (intarray);
}

int	read_width(char *strt)
{
	int		fd;
	char	*str;
	int		i;
	int		x;

	i = 0;
	x = 0;
	str = NULL;
	fd = open(strt, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	close(fd);
	return (i);
}

int	num_columns(char **str, int linenum)
{
	int		i;
	char	***array;
	char	****array2;
	int		size;

	i = 0;
	array = (char ***)malloc(sizeof(char **) * (linenum + 1));
	while (i < linenum)
	{
		array[i] = ft_split(str[i], ' ');
		i++;
	}
	array2 = ft_convert_3d_to_4d(array, linenum, str);
	size = ft_word_count(str[1],' ');
	return (size);
}
int	read_length(char *strt)
{
	char *str;
	int i;
	char	**array;
	int	x;
	int size;
	int fd;

	i = 0;
	x = 0;
	str = NULL;
	i = read_width(strt);
	array = (char **)malloc(sizeof(char*)*(i + 1));
	fd = open(strt, O_RDONLY);
	while (x < i)
	{
		array[x] = get_next_line(fd);
		x++;
	}
	array[x] = 0;
	size = num_columns(array, i);
	return (size);
}

int ***read_map(char *strt)
{
	int fd;
	char *str;
	int i;
	char	**array;
	int	x;
	int		***intarray;

	i = 0;
	x = 0;
	str = NULL;
	fd = open(strt, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		free(str);
		i++;
	}
	array = (char **)malloc(sizeof(char*)*(i + 1));
	close(fd);
	fd = open(strt, O_RDONLY);
	while (x < i)
	{
		array[x] = get_next_line(fd);
		x++;
	}
	array[x] = 0;
	x = 0;
	intarray = ft_convert_string_to_num(array, i);
	while (x < i)
		free(array[x++]);
	free(array);
	ft_printf("Done\n");
	return (intarray);
}
