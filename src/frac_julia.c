#include "fract.h"

static void	julia_init(t_frct *frct)
{
	frct->jul = (t_jul*)malloc(sizeof(t_jul));
	frct->jul->cRe = 0.8;
	frct->jul->cIm = 0;
	frct->jul->zoom = 1;
	frct->jul->moveX = 0;
	frct->jul->moveY = 0;
	frct->jul->maxIter = 300;
	frct->jul->lock = 1;
	frct->jul->mouse_x = 0;
	frct->jul->mouse_y = 0;
}

void julia_color(t_frct *frct)
{
	frct->jul->rgba = (t_rgba*)malloc(sizeof(t_rgba));
	frct->jul->hsv = (t_hsv*)malloc(sizeof(t_hsv));
	frct->jul->hsv->hsv[0] = 0.95f + 10 * frct->jul->smoothcol;
	frct->jul->hsv->hsv[1] = 0.6f;
	frct->jul->hsv->hsv[2] = 1.0f;
	*frct->jul->rgba = hsv_to_rgb(*frct->jul->hsv);
}

void	frac_julia(t_frct *frct)
{
	julia_init(frct);
	frct->jul->y = -1;
	while(frct->jul->y++ < frct->mlx->height)
	{
		frct->jul->x = -1;
		while(frct->jul->x++ < frct->mlx->width)
		{
			frct->jul->newRe = 1.5 * (frct->jul->x - frct->mlx->width / 2) / (0.5 * frct->jul->zoom * frct->mlx->width) + frct->jul->moveX;
			frct->jul->newIm = (frct->jul->y - frct->mlx->height / 2) / (0.5 * frct->jul->zoom * frct->mlx->height) + frct->jul->moveY;
			frct->jul->smoothcol = exp(-fabs((frct->jul->newRe * frct->jul->newRe + frct->jul->newIm * frct->jul->newIm)));
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
			julia_color(frct);
			frac_put_pixel(frct);
//			free(frct->jul->hsv);
//			free(frct->jul->rgba);
		}
	}
}