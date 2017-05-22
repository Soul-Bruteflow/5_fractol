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
	f->zR = 2.0f * (f->x - WIDTH / 2.0f) / (0.5f * f->zoom * WIDTH) + f->moveX;
	f->zI = (f->y - HEIGHT / 2.0f) / (0.5f * f->zoom * HEIGHT) + f->moveY;
	f->smooth_col = expf(-fabsf((f->zR * f->zR + f->zI * f->zI)));
}

static void escape_and_color(t_frct *f)
{
	f->tmp = f->zR * f->zR - f->zI * f->zI + f->cR;
	f->zI = f->zR * f->zI * 2 + f->cI;
	f->zR = f->tmp;
	f->smooth_col += exp(-fabs((f->zR * f->zR + f->zI * f->zI)));
}

void	*julia_worker(void *arg)
{
	t_frct *f = (t_frct*)arg;
	f->y = f->start_y[f->tid] - 1;
	while (f->y++ < f->end_y[f->tid])
	{
		f->x = f->start_x[f->tid] - 1;
		while (f->x++ < f->end_x[f->tid])
		{
			base_values(f);
			f->i = -1;
			while(f->i++ < f->maxIter)
			{
				escape_and_color(f);
				if(f->zR * f->zR + f->zI * f->zI >= 4)
					break;
			}
			julia_color(f);
			fractal_put_pixel(f);
		}
	}
	if (f->run_flag == 0)
		f->run_flag = 1;
	free(f);
	return (NULL);
}