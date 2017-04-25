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
# define CRE(x) ((x) * 4.0 / WIDTH - 2)
# define CIM(x) ((x) * 4.0 / HEIGHT - 2)

/*
** Keys
*/
# define ESC 53
# define SPC 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

/*
** Minilibx
** imgx, imgy - upper left corner of image string.
** wcenx, wceny - x, y center of the window.
** wcurx, wcury - current x, y center of the window.
** str_size - size of image string.
*/

typedef struct			s_frct
{
	struct s_mlx		*mlx;
	struct s_jul		*jul;
	int 				run_flag;
//	int 				lock;
//	int 				mouse_x;
//	int 				mouse_y;
}						t_frct;

typedef struct			s_jul
{
	double				cRe;
	double				cIm;
	double				newRe;
	double				newIm;
	double				oldRe;
	double				oldIm;
	double				zoom;
	double				moveX;
	double				moveY;
	int					maxIter;
	double				smoothcol;
	int 				x;
	int 				y;
	int 				i;
	struct s_rgba		*rgba;
	struct s_hsv		*hsv;
	int 				lock;
	int 				mouse_x;
	int 				mouse_y;
}						t_jul;

typedef struct			s_mlx
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
}						t_mlx;

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

void					frac_mlx_setup(t_frct *frct);
void					frac_first_draw(t_frct *frct);
void					frac_redraw(t_frct *frct);

/*
** Control
*/

int						frac_core_keyb(int kcode, t_frct *frct);
int						frac_core_mouse(int button, int x, int y, t_frct *frct);
int						track_mouse(int x, int y, t_frct *frct);

/*
** Error management.
*/

void					frac_error(int n);

/*
** UI.
*/
void					frac_ui(t_frct *frct);
void					frac_redraw_ui(t_frct *frct);

/*
** Draw
*/

void					frac_julia(t_frct *frct);
void					frac_mandelbrot(t_frct *frct);
void					frac_put_pixel(t_frct *frct);
t_rgba					hsv_to_rgb(t_hsv hsv);

t_rgba 					MapColor(int i, double r, double c);
#endif
