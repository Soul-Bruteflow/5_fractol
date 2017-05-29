/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:46:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 11:46:34 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACT_H
# define _FRACT_H

# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "libft.h"
# include "get_next_line.h"

/*
** General
*/
# define HEIGHT 800
# define WIDTH 1600
# define N_OF_TREDS 16

/*
** Fractals
*/
# define JULIA 0
# define MANDELBROT 1
# define SHIP 2

/*
** Errors
*/
# define USAGE 0
# define MALLCHECK 1

/*
** Keys
*/
# define ESC 53
# define SPC 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define QKEY 12

typedef struct				s_rgba
{
	unsigned char			rgba[3];
}							t_rgba;

typedef struct				s_hsv
{
	float					hsv[3];
	float					r;
	float					g;
	float					b;
	float					f;
	float					p;
	float					q;
	float					t;
}							t_hsv;

typedef struct				s_frct
{
	struct s_mlx			*mlx;
	struct s_rgba			rgba;
	struct s_hsv			hsv;
	float					cr;
	float					ci;
	float					zr;
	float					zi;
	float					rootx;
	float					rooty;
	float					sqr_zr;
	float					sqr_zi;
	float					sq;
	float					tmp;
	float					tmp2;
	float					zoom;
	float					movex;
	float					movey;
	float					smooth_col;
	int						maxiter;
	int						x;
	int						y;
	int						i;
	int						start_y[N_OF_TREDS];
	int						end_y[N_OF_TREDS];
	int						start_x[N_OF_TREDS];
	int						end_x[N_OF_TREDS];
	char					lock;
	int						tid;
	char					fractal;
	char					color;
	char					*maxiter_str;
}							t_frct;

/*
** Minilibx
** imgx, imgy - upper left corner of image string.
** wcenx, wceny - x, y center of the window.
** str_size - size of image string.
*/
typedef struct				s_mlx
{
	void					*ptr;
	void					*win;
	void					*img;
	char					*str;
	int						bit;
	int						line_sz;
	int						end;
	int						width;
	int						height;
	int						imgx;
	int						imgy;
	int						wcenx;
	int						wceny;
	size_t					str_size;
}							t_mlx;
/*
** Minilibx
*/
void						frac_mlx_setup(t_frct *frct);
void						frac_first_draw(t_frct *frct);
void						frac_redraw(t_frct *frct);
int							expose_hook(void *param);
/*
** Control
*/
int							frac_core_keyb(int kcode, t_frct *frct);
int							frac_core_mouse(int buttn, int x, int y, t_frct *f);
int							track_mouse(int x, int y, t_frct *frct);
/*
** Error management.
*/
void						frac_error(int n);
/*
** UI.
*/
void						frac_ui(t_frct *frct);
void						frac_redraw_ui(t_frct *frct);
/*
** Draw and color
*/
void						fractal_put_pixel(t_frct *frct);
t_rgba						ft_hsv_to_rgb(t_hsv hsv);
void						hsv_color(t_frct *f);
/*
** Threads
*/
void						threads_core(t_frct *frct);
/*
** Fractals
*/
void						julia_core(void);
void						julia_default(t_frct *frct);
void						*julia_worker(void *arg);
void						mandelbrot_core(void);
void						mandelbrot_default(t_frct *frct);
void						*mandelbrot_worker(void *arg);
void						ship_core(void);
void						ship_default(t_frct *f);
void						*ship_worker(void *arg);
#endif
