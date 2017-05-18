/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:21:24 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/11 14:21:28 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	main(int ac, char **av)
{
	t_frct *frct;

	if (ac == 2)
	{
		frct->rgba;
		frct = (t_frct*)(malloc(sizeof(t_frct)));
		frct->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
//		frct->jul = (t_jul*)malloc(sizeof(t_jul));
//		frct->rgba = (t_rgba)malloc(sizeof(t_rgba));
//		frct->hsv = (t_hsv)malloc(sizeof(t_hsv));
		frct->lock = -1;
		frct->cRe = 0.5459;
		frct->cIm = 0.0896;
		frct->zoom = 1;
		frct->moveX = 0;
		frct->moveY = 0;
		frct->maxIter = 50;
		frac_mlx_setup(frct);

		frac_julia_thread_create(frct);
//		frac_julia_thread_join(frct);


//		frac_julia(frct);
//		frac_mandelbrot(mlx);
		frac_first_draw(frct);
//		frct->mouse_x = 0;
//		frct->mouse_y = 0;
		mlx_mouse_hook(frct->mlx->win, frac_core_mouse, frct);
		mlx_hook(frct->mlx->win, 6, 0, track_mouse, frct);
		mlx_hook(frct->mlx->win, 2, 5, frac_core_keyb, frct);
		mlx_loop(frct->mlx->ptr);
	}
	else
		frac_error(USAGE);
}
