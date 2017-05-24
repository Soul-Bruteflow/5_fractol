#include "fract.h"

static void base_values(t_frct *f);
static void escape_and_color(t_frct *f);

void *ship_worker(void *arg)
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
							(f->sqr_zI = f->zI * f->zI)) <= 4
				   && f->i < f->maxIter)
				escape_and_color(f);
			if (f->i == f->maxIter)
				continue;
			else
				fractal_put_pixel(f);
		}
	}
	return (NULL);
}

static void base_values(t_frct *f)
{
	f->cR = 2.0f * ((4 * (float)f->x / WIDTH - 2) / f->zoom) + f->moveX;
	f->cI = ((-4 * (float)f->y / HEIGHT + 2) / f->zoom) + f->moveY;
	f->zR = f->cR;
	f->zI = f->cI;
	f->i = 0;
}

static void escape_and_color(t_frct *f)
{
	f->zI = fabsf(f->zR * f->zI + f->zR * f->zI - f->cI);
	f->zR = fabsf(f->sqr_zR - f->sqr_zI - f->cR);
	f->i++;
}