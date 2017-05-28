#include "fract.h"

static void base_values(t_frct *f);
static void escape_and_color(t_frct *f);

void	*mandelbrot_worker(void *arg)
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
			while ((f->sq = (f->sqr_zR = f->zR * f->zR) +
							(f->sqr_zI = f->zI * f->zI)) < 4
				   && f->i < f->maxIter)
				escape_and_color(f);
			if (f->color == 1)
				hsv_color(f);
			fractal_put_pixel(f);
		}
	}
	return (NULL);
}

static void base_values(t_frct *f)
{
	f->cR = 2.0f * ((4 * (float)f->x / WIDTH - 2) / f->zoom) + f->moveX;
	f->cI = ((-4 * (float)f->y / HEIGHT + 2) / f->zoom) + f->moveY;
	f->zR = 0;
	f->zI = 0;
	f->tmp = 0;
	f->i = 0;
	if (f->color == 1)
		f->smooth_col = expf(-fabsf((f->zR * f->zR + f->zI * f->zI)));
}

static void escape_and_color(t_frct *f)
{
	if (f->color == 1)
		f->smooth_col += exp(-fabs(f->sq));
	f->tmp = f->sqr_zR - f->sqr_zI + f->cR;
	f->zI = f->zR * f->zI * 2 + f->cI;
	f->zR = f->tmp;
	f->i++;
}