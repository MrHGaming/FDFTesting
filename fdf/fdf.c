/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:43:16 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/15 22:41:19 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setting_up_image(t_fdf *fdf, char **av)
{
	int		i;
	t_data	img_struct;

	i = 0;
	fdf->mlx = mlx_init();
	fdf->maximum_length = read_length(av[1]);
	fdf->maximum_width = read_width(av[1]);
	fdf->mlx_win = mlx_new_window(fdf->mlx, 1400, 800, "FDF");
	img_struct.img = mlx_new_image(fdf->mlx, 1400, 800);
	img_struct.addr = mlx_get_data_addr(img_struct.img,
			&img_struct.bits_per_pixel, &img_struct.line_length,
			&img_struct.endian);
	fdf->img_struct = img_struct;
}

void	fdf_setup_color(int color, t_fdf *fdf)
{
	if (color != 0)
		fdf->color = color;
	else
		fdf->color = 0xffa572;
}

void	fdf_setup_heights(t_fdf *fdf, int x, int y, int ***array)
{
	fdf->z = array[y][x][0];
	if (x < fdf->maximum_length - 1)
		fdf->nextzx = array[y][x + 1][0];
	if (y < fdf->maximum_width - 1)
		fdf->nextzy = array[y + 1][x][0];
}

void	start_draw(int ***array, t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->maximum_width)
	{
		x = 0;
		while (x < fdf->maximum_length)
		{
			fdf_setup_color(array[y][x][1], fdf);
			fdf_setup_heights(fdf, x, y, array);
			ft_changes(x, y, fdf);
			draw_lines(x, y, fdf);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	int		***array;
	t_fdf	fdf;

	if (ac == 2)
	{
		setting_up_image(&fdf, av);
		array = read_map(av[1]);
		start_draw(array, &fdf);
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img_struct.img, 0, 0);
	mlx_loop(fdf.mlx);
}
