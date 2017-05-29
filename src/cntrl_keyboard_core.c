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

void	frac_move(int kcode, t_frct *f)
{
	if (kcode == UP)
		f->moveY -= 0.0200 / f->zoom;
	if (kcode == DOWN)
		f->moveY += 0.0200 / f->zoom;
	if (kcode == LEFT)
		f->moveX += 0.0200 / f->zoom;
	if (kcode == RIGHT)
		f->moveX -= 0.0200 / f->zoom;
	frac_redraw(f);
}

void	frac_max_iteration(int kcode, t_frct *frct)
{
	if (kcode == PLUS && frct->maxIter < 500)
	{
		frct->maxIter += 5;
		frac_redraw(frct);
	}
	else if (kcode == MINUS && frct->maxIter > 10)
	{
		frct->maxIter -= 5;
		frac_redraw(frct);
	}
}

void	frac_reset(t_frct *f)
{
	if (f->fractal == JULIA)
		julia_default(f);
	else if (f->fractal == MANDELBROT)
		mandelbrot_default(f);
	else if (f->fractal == SHIP)
		ship_default(f);
	frac_redraw(f);
}

void	fractal_color_model(t_frct *f)
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

int		frac_core_keyb(int kcode, t_frct *f)
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
