#include "fract.h"

static void julia_color(t_frct *f)
{
	f->hsv.hsv[0] = 0.95f + 10 * f->smooth_col;
	f->hsv.hsv[1] = 0.6f;
	f->hsv.hsv[2] = 1.0f;
	f->rgba = ft_hsv_to_rgb(f->hsv);
}

static void base_values(t_frct *f)
{
	f->zR = 2.0f * ((4 * (float)f->x / WIDTH - 2) / f->zoom) + f->moveX;
	f->zI = ((-4 * (float)f->y / HEIGHT + 2) / f->zoom) + f->moveY;
	f->smooth_col = expf(-fabsf((f->zR * f->zR + f->zI * f->zI)));
}

static void escape_and_color(t_frct *f)
{
	f->smooth_col += exp(-fabs(f->sq));
	f->tmp = f->sqr_zR - f->sqr_zI + f->cR;
	f->zI = f->zR * f->zI * 2 + f->cI;
	f->zR = f->tmp;
}

void	*julia_worker(void *arg)
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
			f->i = -1;
			while ((f->sq = (f->sqr_zR = f->zR * f->zR) +
					(f->sqr_zI = f->zI * f->zI)) <= 4 && f->i++ < f->maxIter)
				escape_and_color(f);
//			if (f->i == f->maxIter)
//				continue;
//			else
//			{
				julia_color(f);
				fractal_put_pixel(f);
//			}
		}
	}
	if (f->run_flag == 0)
		f->run_flag = 1;
	return (NULL);
}