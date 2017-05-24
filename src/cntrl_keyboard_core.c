#include "fract.h"

void	frac_move(int kcode, t_frct *frct)
{
	if (kcode == UP)
	{
		frct->moveY -= 0.0200 / frct->zoom;
	}
	if (kcode == DOWN)
	{
		frct->moveY += 0.0200 / frct->zoom;
	}
	if (kcode == LEFT)
	{
		frct->moveX += 0.0200 / frct->zoom;
	}
	if (kcode == RIGHT)
	{
		frct->moveX -= 0.0200 / frct->zoom;
	}
	frac_redraw(frct);
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

	return (0);
}