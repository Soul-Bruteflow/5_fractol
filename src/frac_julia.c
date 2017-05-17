#include "fract.h"

static void	julia_init(t_frct *frct)
{
	if (!(frct->run_flag == 0 || frct->jul->lock == -1))
	{
		frct->jul->cRe = (frct->jul->mouse_x) * 4.0f / frct->mlx->width - 2;
		frct->jul->cIm = (frct->jul->mouse_y) * 4.0f / frct->mlx->height - 2;
	}
}

void julia_color(t_frct *frct)
{
	frct->jul->hsv->hsv[0] = 0.95f + 10 * frct->jul->smoothcol;
	frct->jul->hsv->hsv[1] = 0.6f;
	frct->jul->hsv->hsv[2] = 1.0f;
	*frct->jul->rgba = hsv_to_rgb(*frct->jul->hsv);
}

void	*frac_julia(void *arg)
{
	t_frct *frct = (t_frct*)arg;
	julia_init(frct);
	frct->jul->y = frct->jul->tid;
	frct->jul->x = -1;
	while(frct->jul->x++ < frct->mlx->width)
	{
		frct->jul->newRe = 1.5f * (frct->jul->x - frct->mlx->width / 2) / (0.5f * frct->jul->zoom * frct->mlx->width) + frct->jul->moveX;
		frct->jul->newIm = (frct->jul->y - frct->mlx->height / 2) / (0.5f * frct->jul->zoom * frct->mlx->height) + frct->jul->moveY;
		frct->jul->smoothcol = (float)exp(-fabs((frct->jul->newRe * frct->jul->newRe + frct->jul->newIm * frct->jul->newIm)));
		frct->jul->i = -1;
		while(frct->jul->i++ < frct->jul->maxIter)
		{
			frct->jul->oldRe = frct->jul->newRe;
			frct->jul->oldIm = frct->jul->newIm;
			frct->jul->newRe = frct->jul->oldRe * frct->jul->oldRe - frct->jul->oldIm * frct->jul->oldIm + frct->jul->cRe;
			frct->jul->newIm = 2 * frct->jul->oldRe * frct->jul->oldIm + frct->jul->cIm;
			frct->jul->smoothcol += exp(-fabs((frct->jul->newRe * frct->jul->newRe + frct->jul->newIm * frct->jul->newIm)));
			if((frct->jul->newRe * frct->jul->newRe + frct->jul->newIm * frct->jul->newIm) > 4)
			{
					break;
			}
		}
		pthread_mutex_lock(&count_mutex);
		julia_color(frct);
		frac_put_pixel(frct);
		pthread_mutex_unlock(&count_mutex);
//		free(frct->jul->hsv);
//		free(frct->jul->rgba);
	}
	if (frct->run_flag == 0)
		frct->run_flag = 1;
	return (NULL);
}