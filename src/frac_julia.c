#include "fract.h"

//static void	julia_init(t_frct *frct)
//{
//	if (!(frct->run_flag == 0 || frct->lock == -1))
//	{
//		frct->cRe = (frct->mouse_x) * 4.0f / WIDTH - 2;
//		frct->cIm = (frct->mouse_y) * 4.0f / HEIGHT - 2;
//	}
//}

void julia_color(t_frct *frct)
{
	frct->hsv.hsv[0] = 0.95f + 10 * frct->smoothcol;
	frct->hsv.hsv[1] = 0.6f;
	frct->hsv.hsv[2] = 1.0f;
	frct->rgba = hsv_to_rgb(frct->hsv);
}

void	*frac_julia(void *arg)
{
	t_frct *frct = (t_frct*)arg;
//	julia_init(frct);
	frct->y = frct->tid;
	frct->x = -1;
	while(frct->x++ < WIDTH)
	{
		frct->newRe = 1.5f * (frct->x - WIDTH / 2) / (0.5f * frct->zoom * WIDTH) + frct->moveX;
		frct->newIm = (frct->y - HEIGHT / 2) / (0.5f * frct->zoom * HEIGHT) + frct->moveY;
		frct->smoothcol = (float)exp(-fabs((frct->newRe * frct->newRe + frct->newIm * frct->newIm)));
		frct->i = -1;
		while(frct->i++ < frct->maxIter)
		{
			frct->oldRe = frct->newRe;
			frct->oldIm = frct->newIm;
			frct->newRe = frct->oldRe * frct->oldRe - frct->oldIm * frct->oldIm + frct->cRe;
			frct->newIm = 2 * frct->oldRe * frct->oldIm + frct->cIm;
			frct->smoothcol += exp(-fabs((frct->newRe * frct->newRe + frct->newIm * frct->newIm)));
			if((frct->newRe * frct->newRe + frct->newIm * frct->newIm) > 4)
			{
					break;
			}
		}
//		pthread_mutex_lock(&count_mutex);
		julia_color(frct);
		frac_put_pixel(frct);
//		pthread_mutex_unlock(&count_mutex);
//		free(frct->jul->hsv);
//		free(frct->jul->rgba);
	}
	if (frct->run_flag == 0)
		frct->run_flag = 1;
	return (NULL);
}