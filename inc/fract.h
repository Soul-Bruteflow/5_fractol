/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:21:01 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/11 14:21:05 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"


#include <stdio.h>

//# include <fcntl.h>

# define TRUE 1
# define FALSE -1
# define HEIGHT 900
# define WIDTH 1500
# define USAGE 0

/*
** Minilibx
** imgx, imgy - upper left corner of image string.
** wcenx, wceny - x, y center of the window.
** wcurx, wcury - current x, y center of the window.
** str_size - size of image string.
*/

typedef struct			s_m
{
	void				*ptr;
	void				*win;
	void				*img;
	char				*str;
	int					bit;
	int					line_sz;
	int					end;
	int					width;
	int					height;
	int					imgx;
	int					imgy;
	int					wcenx;
	int					wceny;
	int					wcurx;
	int					wcury;
	size_t				str_size;
}						t_m;

typedef struct			s_rgba
{
	unsigned char		rgba[5];
}						t_rgba;

typedef struct			s_hsv
{
	double				hsv[3];
}						t_hsv;

/*
** Mlx.
*/

void					frac_mlx_setup(t_m *mlx);
void					frac_first_draw(t_m *mlx);
void					frac_redraw(t_m *mlx);

/*
** Keys.
*/

int						frac_key_core(int kcode, t_m *mlx);

/*
** Error management.
*/

void					frac_error(int n);

/*
** UI.
*/
void					frac_ui(t_m *mlx);

/*
** Draw
*/

void					frac_julia(t_m *mlx);
void					frac_mandelbrot(t_m *mlx);
void					frac_put_pixel(int x, int y, int f, t_m *mlx, double newR, double newI, double smoothcolor);
t_rgba					hsv_to_rgb(t_hsv hsv);

t_rgba 					MapColor(int i, double r, double c);
#endif
