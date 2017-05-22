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
# include <pthread.h>

//pthread_mutex_t count_mutex;
#include <stdio.h>

//# include <fcntl.h>

# define TRUE 1
# define FALSE -1
# define HEIGHT 800
# define WIDTH 1600
# define HALF_HEIGHT 400
# define HALF_WIDTH 800
# define N_OF_TREDS 16
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

typedef struct			s_tred
{
}						t_tred;

typedef struct			s_rgba
{
	unsigned char		rgba[3];
}						t_rgba;

typedef struct			s_hsv
{
	float				hsv[3];
	float				r;
	float				g;
	float				b;
	float				f;
	float				p;
	float				q;
	float				t;
}						t_hsv;

typedef struct			s_frct
{
	struct s_mlx		*mlx;
//	struct s_jul		*jul;
	int 				run_flag;

	int start_y[16];
	int end_y[16];
	int start_x[16];
	int end_x[16];



	float				cR;
	float				cI;
	float				zR;
	float				zI;
	float 				rootX;
	float 				rootY;
	float 				sqr_zR;
	float 				sqr_zI;
	float 				sq;
	float				tmp;
	float				zoom;
	float				moveX;
	float				moveY;
	int					maxIter;
	float				smooth_col;
	int 				x;
	int 				y;
	int 				i;
	struct s_rgba		rgba;
	struct s_hsv		hsv;
	int 				lock;
	int 				mouse_x;
	int 				mouse_y;
	pthread_t			*tids;
	int 				tid;

}						t_frct;

//typedef struct			s_jul
//{
//	float				cRe;
//	float				cIm;
//	float				newRe;
//	float				newIm;
//	float				oldRe;
//	float				oldIm;
//	float				zoom;
//	float				moveX;
//	float				moveY;
//	int					maxIter;
//	float				smoothcol;
//	int 				x;
//	int 				y;
//	int 				i;
//	struct s_rgba		*rgba;
//	struct s_hsv		*hsv;
//	int 				lock;
//	int 				mouse_x;
//	int 				mouse_y;
//	pthread_t			*tids;
////	pthread_attr_t		*attrs;
//	int 				tid;
//}						t_jul;

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

void					frac_mandelbrot(t_frct *frct);
void					fractal_put_pixel(t_frct *frct);
t_rgba					ft_hsv_to_rgb(t_hsv hsv);

/*
** Threads
*/


/*
** Fractals
*/

void					julia_core(void);
void					julia_default(t_frct *frct);;
void					julia_threads_core(t_frct *frct);
void					*julia_worker(void *arg);
//void					mandelbrot_core(void);

t_rgba 					MapColor(int i, double r, double c);
#endif
