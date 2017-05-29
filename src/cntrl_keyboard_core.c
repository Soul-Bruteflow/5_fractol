/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl_keyboard_core.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:42:27 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:43:06 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	frac_move(int kcode, t_frct *f)
{
	if (kcode == UP)
		f->movey -= 0.0200 / f->zoom;
	if (kcode == DOWN)
		f->movey += 0.0200 / f->zoom;
	if (kcode == LEFT)
		f->movex += 0.0200 / f->zoom;
	if (kcode == RIGHT)
		f->movex -= 0.0200 / f->zoom;
	frac_redraw(f);
}

static void	frac_max_iteration(int kcode, t_frct *frct)
{
	if (kcode == PLUS && frct->maxiter < 500)
	{
		frct->maxiter += 5;
		frac_redraw(frct);
	}
	else if (kcode == MINUS && frct->maxiter > 10)
	{
		frct->maxiter -= 5;
		frac_redraw(frct);
	}
}

static void	frac_reset(t_frct *f)
{
	if (f->fractal == JULIA)
		julia_default(f);
	else if (f->fractal == MANDELBROT)
		mandelbrot_default(f);
	else if (f->fractal == SHIP)
		ship_default(f);
	frac_redraw(f);
}

static void	fractal_color_model(t_frct *f)
{
	if (f->color == 0)
	{
		f->color = 1;
		frac_redraw(f);
		return ;
	}
	else if (f->color == 1)
	{
		f->color = 0;
		frac_redraw(f);
		return ;
	}
}

int			frac_core_keyb(int kcode, t_frct *f)
{
	if (kcode == SPC)
		frac_reset(f);
	if (kcode == PLUS || kcode == MINUS)
		frac_max_iteration(kcode, f);
	if (kcode == ESC)
		exit(0);
	if (kcode == UP || kcode == DOWN || kcode == LEFT || kcode == RIGHT)
		frac_move(kcode, f);
	if (kcode == QKEY)
		fractal_color_model(f);
	return (0);
}
