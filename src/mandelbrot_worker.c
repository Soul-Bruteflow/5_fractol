/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_worker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/05/29 11:06:11 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 11:07:16 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		base_values(t_frct *f)
{
	f->cr = 2.0f * ((4 * (float)f->x / WIDTH - 2) / f->zoom) + f->movex;
	f->ci = ((-4 * (float)f->y / HEIGHT + 2) / f->zoom) + f->movey;
	f->zr = 0;
	f->zi = 0;
	f->tmp = 0;
	f->i = 0;
	if (f->color == 1)
		f->smooth_col = expf(-fabsf((f->zr * f->zr + f->zi * f->zi)));
}

static void		escape_and_color(t_frct *f)
{
	if (f->color == 1)
		f->smooth_col += exp(-fabs(f->sq));
	f->tmp = f->sqr_zr - f->sqr_zi + f->cr;
	f->zi = f->zr * f->zi * 2 + f->ci;
	f->zr = f->tmp;
	f->i++;
}

void			*mandelbrot_worker(void *arg)
{
	t_frct *f;

	f = (t_frct*)arg;
	f->y = f->start_y[f->tid] - 1;
	while (f->y++ < f->end_y[f->tid])
	{
		f->x = f->start_x[f->tid] - 1;
		while (f->x++ < f->end_x[f->tid])
		{
			base_values(f);
			while ((f->sq =
						(f->sqr_zr = f->zr * f->zr) +
						(f->sqr_zi = f->zi * f->zi)) < 4 && f->i < f->maxiter)
				escape_and_color(f);
			if (f->color == 1)
				hsv_color(f);
			fractal_put_pixel(f);
		}
	}
	return (NULL);
}
