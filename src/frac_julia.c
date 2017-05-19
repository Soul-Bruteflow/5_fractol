#include "fract.h"

static void julia_color(t_frct *frct)
{
	frct->hsv.hsv[0] = 0.95f + 10 * frct->smoothcol;
	frct->hsv.hsv[1] = 0.6f;
	frct->hsv.hsv[2] = 1.0f;
	frct->rgba = hsv_to_rgb(frct->hsv);
}

static void initialize(t_frct *frct)
{
	frct->newRe = 1.5f * (frct->x - WIDTH / 2.0f) /
						  (0.5f * frct->zoom * WIDTH) + frct->moveX;
	frct->newIm = (frct->y - HEIGHT / 2.0f) /
						  (0.5f * frct->zoom * HEIGHT) + frct->moveY;
	frct->smoothcol = (float)exp(-fabs((frct->newRe * frct->newRe
										+ frct->newIm * frct->newIm)));
}

static void escape_and_color(t_frct *frct)
{
	frct->oldRe = frct->newRe;
	frct->oldIm = frct->newIm;
	frct->newRe = frct->oldRe * frct->oldRe -
			frct->oldIm * frct->oldIm + frct->cRe;
	frct->newIm = 2 * frct->oldRe * frct->oldIm + frct->cIm;
	frct->smoothcol += exp(-fabs((frct->newRe * frct->newRe +
			frct->newIm * frct->newIm)));
}

void	*frac_julia(void *arg)
{
	t_frct *frct = (t_frct*)arg;
	frct->y = frct->tid;
	frct->x = -1;
	while(frct->x++ < WIDTH)
	{
		initialize(frct);
		frct->i = -1;
		while(frct->i++ < frct->maxIter)
		{
			escape_and_color(frct);
			if((frct->newRe * frct->newRe + frct->newIm * frct->newIm) > 4)
					break;
		}
		julia_color(frct);
		frac_put_pixel(frct);
	}
	if (frct->run_flag == 0)
		frct->run_flag = 1;
	free(frct);
	return (NULL);
}