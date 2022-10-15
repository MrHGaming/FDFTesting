/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohouhou <mohouhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:01:27 by mohouhou          #+#    #+#             */
/*   Updated: 2022/10/15 22:49:42 by mohouhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>

#ifndef	BUFFER_SIZE
# define	BUFFER_SIZE	4096
#endif

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
    int x;
    int y;
    int nextx;
    int nexty;
    void    *mlx;
    void    *mlx_win;
    int maximum_length;
    int maximum_width;
    int color;
    int z;
    int nextzx;
    int nextzy;
    t_data  img_struct;
}   t_fdf;

typedef struct s_newvalues
{
    int x0;
    int y0;
    int z0;
    int x1;
    int y1;
    int z1;
    
}   t_newvalues;

typedef struct s_plotingvalues
{
    int x0;
    int y0;
    int x1;
    int y1;
    int dx;
	int	dy;
	int	xi;
	int D;
	int	x;
	int	y;
    
}   t_plotingvalues;

char	*gl_strchr(const char *s, int c);
int		gl_strlen2(char *str);
char	*gl_strjoin(char *s1, char *s2);
char	*gl_substr(char *s, int start, int len);
char	*get_next_line(int fd);
char	*gl_strdup(char *src);
int     ***read_map(char *strt);
int ***ft_convert_string_to_num(char **str, int linenum);
int	read_length(char *strt);
int	read_width(char *strt);
void	plot_line(t_fdf *fdf,t_newvalues *newvalues);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ft_changes(int x, int y, t_fdf *fdf);
void draw_lines(int x, int y, t_fdf *fdf);
void	setting_up_image(t_fdf *fdf, char **av);

#endif