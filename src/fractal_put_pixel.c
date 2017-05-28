#include "fract.h"

void	fractal_put_pixel(t_frct *f)
{
	size_t			i;
	float			zn;
	float			nu;
	float			j;

	if (f->color == 0)
	{
		zn = logf(f->sq);
		nu = logf(zn / logf(2)) / logf(2);
		j = f->i + 1 - nu;

		f->rgba.rgba[0] = (unsigned char)(sin(0.016 * j + 4) * 230 + 25);
		f->rgba.rgba[1] = (unsigned char)(sin(0.013 * j + 2) * 230 + 25);
		f->rgba.rgba[2] = (unsigned char)(sin(0.01 * j + 1) * 230 + 25);
	}

	i = (size_t)(f->y * f->mlx->line_sz +
			(f->x * (f->mlx->bit / 8)));
	if (i < f->mlx->str_size && f->x > 0 &&
			f->x < f->mlx->width)
	{
		if (f->mlx->end == 1)
		{
			f->mlx->str[i] = f->rgba.rgba[0];
			f->mlx->str[i + 1] = f->rgba.rgba[1];
			f->mlx->str[i + 2] = f->rgba.rgba[2];
		}
		else if (f->mlx->end == 0)
		{
			f->mlx->str[i] = f->rgba.rgba[2];
			f->mlx->str[i + 1] = f->rgba.rgba[1];
			f->mlx->str[i + 2] = f->rgba.rgba[0];
		}
//		if (f->i == f->maxIter)
//		{
//			f->mlx->str[i] = 255;
//			f->mlx->str[i + 1] = 255;
//			f->mlx->str[i + 2] = 255;
//		}
//		else
//		{
//			f->mlx->str[i] = 0;
//			f->mlx->str[i + 1] = 0;
//			f->mlx->str[i + 2] = 0;
//		}


//		else if (f->mlx->end == 0)
//		{
//			f->mlx->str[i] = f->rgba.rgba[2];
//			f->mlx->str[i + 1] = f->rgba.rgba[1];
//			f->mlx->str[i + 2] = f->rgba.rgba[0];
//		}
	}
}