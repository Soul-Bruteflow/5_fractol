#include "fract.h"

void	fractal_put_pixel(t_frct *frct)
{
	size_t			i;

	i = (size_t)(frct->y * frct->mlx->line_sz +
			(frct->x * (frct->mlx->bit / 8)));
	if (i < frct->mlx->str_size && frct->x > 0 &&
			frct->x < frct->mlx->width)
	{
		if (frct->mlx->end == 1)
		{
			frct->mlx->str[i] = frct->rgba.rgba[0];
			frct->mlx->str[i + 1] = frct->rgba.rgba[1];
			frct->mlx->str[i + 2] = frct->rgba.rgba[2];
		}
		else if (frct->mlx->end == 0)
		{
			frct->mlx->str[i] = frct->rgba.rgba[2];
			frct->mlx->str[i + 1] = frct->rgba.rgba[1];
			frct->mlx->str[i + 2] = frct->rgba.rgba[0];
		}
	}
}