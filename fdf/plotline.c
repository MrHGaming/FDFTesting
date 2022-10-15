/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:02:25 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/15 19:29:52 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_ploty(int x, int y, int z)
{
	int cy;
	// cy = (x+(2*y)+z)/sqrt(6);
	// cy = y + ((x + z) * sin(0.523599));
	cy = -z + (x + y) * sin(0.523599);
	return (cy);
	
}

int	ft_plotx(int x, int y, int z)
{
	int cx;
	(void)z;
	cx = (x - y) * cos(0.523599);
	// cx = (x-z)/sqrt(2);
	// cx = (x - z) * cos(0.523599);
	return (cx);
}

void	plotLineLow(t_plotingvalues *ploting,t_fdf *fdf)
{
	int dx;
	int	dy;
	int	yi;
	int D;
	int	x;
	int	y;
    dx = ploting->x1 - ploting->x0;
    dy = ploting->y1 - ploting->y0;
    yi = 1;
    if (dy < 0)
	{
        yi = -1;
        dy = -dy;
	}
    D = (2 * dy) - dx;
    y = ploting->y0;
	x = ploting->x0;
    while (x < ploting->x1)
	{
		
		my_mlx_pixel_put(&fdf->img_struct, x,y, fdf->color);
        // mlx_pixel_put(fdf->mlx, fdf->mlx_win, x, y, fdf->color);
        if (D > 0)
		{
            y = y + yi;
            D = D + (2 * (dy - dx));
		}
        else
            D = D + 2*dy;
		x++;
	}
}

void	plotLineHigh(t_plotingvalues *ploting,t_fdf *fdf)
{
    ploting->dx = ploting->x1 - ploting->x0;
    ploting->dy = ploting->y1 - ploting->y0;
    ploting->xi = 1;
    if (ploting->dx < 0)
	{
        ploting->xi = -1;
        ploting->dx = -ploting->dx;
	}
    ploting->D = (2 * ploting->dx) - ploting->dy;
    ploting->x = ploting->x0;
	ploting->y = ploting->y0;
    while(ploting->y < ploting->y1)
	{
		my_mlx_pixel_put(&fdf->img_struct, ploting->x,ploting->y, fdf->color);
        // mlx_pixel_put(fdf->mlx, fdf->mlx_win, ploting->x,ploting->y, fdf->color);
        if (ploting->D > 0)
		{
            ploting->x = ploting->x + ploting->xi;
            ploting->D = ploting->D + (2 * (ploting->dx - ploting->dy));
		}
        else
            ploting->D = ploting->D + 2 * ploting->dx;
		ploting->y++;
	}
}

void	plot_line(t_fdf *fdf, t_newvalues *newvalues)
{
	t_plotingvalues	ploting;
	
	newvalues->x0 = ft_plotx(newvalues->x0, newvalues->y0, newvalues->z0);
	newvalues->y0 = ft_ploty(newvalues->x0, newvalues->y0, newvalues->z0);
	newvalues->x1 = ft_plotx(newvalues->x1, newvalues->y1, newvalues->z1);
	newvalues->y1 = ft_ploty(newvalues->x1, newvalues->y1, newvalues->z1);
	if (abs(newvalues->y1 - newvalues->y0) < abs(newvalues->x1 - newvalues->x0))
	{
		if (newvalues->x0 > newvalues->x1)
		{
			ploting.x0 = newvalues->x1;
			ploting.y0 = newvalues->y1;
			ploting.x1 = newvalues->x0;
			ploting.y1 = newvalues->y0;
			plotLineLow(&ploting, fdf);
		}
		else
		{
			ploting.x0 = newvalues->x0;
			ploting.y0 = newvalues->y0;
			ploting.x1 = newvalues->x1;
			ploting.y1 = newvalues->y1;
			plotLineLow(&ploting, fdf);
		}
	}
	else
	{
		if (newvalues->y0 > newvalues->y1)
		{
			ploting.x0 = newvalues->x1;
			ploting.y0 = newvalues->y1;
			ploting.x1 = newvalues->x0;
			ploting.y1 = newvalues->y0;
			plotLineHigh(&ploting, fdf);
		}
		else
		{
			ploting.x0 = newvalues->x0;
			ploting.y0 = newvalues->y0;
			ploting.x1 = newvalues->x1;
			ploting.y1 = newvalues->y1;
			plotLineHigh(&ploting, fdf);
		}
	}
}