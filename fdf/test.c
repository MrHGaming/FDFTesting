/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:15:50 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/15 20:43:40 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	makehorizontal(t_fdf *fdf, t_newvalues *newvalues)
{
	printf("horizontal\n");
	newvalues->x0 = fdf->x;
	newvalues->y0 = fdf->y;
	newvalues->z0 = fdf->z;
	newvalues->x1 = fdf->nextx;
	newvalues->y1 = fdf->y;
	newvalues->z1 = fdf->nextzx;
	printf(" x0 %d y0 %d z0 %d x1 %d y1 %d z1 %d\n", newvalues->x0,newvalues->y0,newvalues->z0,newvalues->x1, newvalues->y1,newvalues->z1);
	
}

void	makevertical(t_fdf *fdf, t_newvalues *newvalues)
{
	printf("vertical\n");
	newvalues->x0 = fdf->x;
	newvalues->y0 = fdf->y;
	newvalues->z0 = fdf->z;
	newvalues->x1 = fdf->x;
	newvalues->y1 = fdf->nexty;
	newvalues->z1 = fdf->nextzy;
	printf(" x0 %d y0 %d z0 %d x1 %d y1 %d z1 %d\n", newvalues->x0,newvalues->y0,newvalues->z0,newvalues->x1, newvalues->y1,newvalues->z1);
	
}

int ft_newx(int maximum_length, int x)
{
	int newx;
	newx = ((800/maximum_length) * x) + 800;
	return (newx);
}

int ft_newy(int maximum_width, int y)
{
	int newy;
	newy = ((800/maximum_width) * y);
	return (newy);
}

void ft_changes(int x, int y, t_fdf *fdf)
{

	fdf->x = ft_newx(fdf->maximum_length, x);
	fdf->y = ft_newy(fdf->maximum_width, y);
	fdf->nextx = ft_newx(fdf->maximum_length, (x + 1));
	fdf->nexty = ft_newy(fdf->maximum_width, (y + 1));

}




void draw_first_corner(t_fdf *fdf)
{
	t_newvalues	newvalues;
	
		printf("here\n");
		printf("printHorizontal\n");
	makehorizontal(fdf, &newvalues);
	plot_line(fdf, &newvalues);
		printf("printvertical\n");
	makevertical(fdf, &newvalues);
	plot_line(fdf, &newvalues);
}

void draw_last_vertical(t_fdf *fdf)
{
	ft_printf("donevertical fdf->x %d  fdf->nextx %d  fdf->y %d  fdf->nexty %d\n", fdf->x, fdf->nextx, fdf->y, fdf->nexty);
	t_newvalues	newvalues;
	makevertical(fdf, &newvalues);
	plot_line(fdf, &newvalues);
}

void draw_last_horizontal(t_fdf *fdf)
{
	t_newvalues	newvalues;
	makehorizontal(fdf, &newvalues);
	plot_line(fdf, &newvalues);
}

void draw_lines(int x, int y, t_fdf *fdf)
{
	if (x < fdf->maximum_length - 1 && y < (fdf->maximum_width - 1))
	{
		draw_first_corner(fdf);
	}
	else if (y < (fdf->maximum_width - 1) && x == (fdf->maximum_length - 1))
	{
		draw_last_vertical(fdf);
		ft_printf("second x %d y %d\n", x , y);
	}
	else if (y == fdf->maximum_width - 1 && x < fdf->maximum_length - 1)
	{
		draw_last_horizontal(fdf);
		ft_printf("third x %d y %d\n", x , y);
	}
	else if (x == fdf->maximum_length - 1 && y == fdf->maximum_width - 1)
		mlx_pixel_put(fdf->mlx, fdf->mlx_win, ft_newy(fdf->maximum_length, fdf->y), ft_newx(fdf->maximum_width, fdf->x), fdf->color);
}

// void draw_square(int x, int y, int color, void *mlx, void *mlx_win)
// {
// 	int i;
// 	int j;
	
// 	i = x *10;
// 	while(i < ((x*10)+10))
// 	{
// 		j = y * 10;
// 		while (j < ((y* 10)+10))
// 		{
// 			mlx_pixel_put(mlx, mlx_win, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
