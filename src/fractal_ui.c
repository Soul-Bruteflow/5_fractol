#include "fract.h"

void	frac_redraw_ui(t_frct *frct)
{
	mlx_clear_window(frct->mlx->ptr, frct->mlx->win);
	mlx_put_image_to_window(frct->mlx->ptr, frct->mlx->win, frct->mlx->img,
							frct->mlx->imgx, frct->mlx->imgy);
	frac_ui(frct);
}

void	frac_ui(t_frct *frct)
{
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 640, 0x00FFFFFF, "Controls:");
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 660, 0x00FFFFFF, "Exit: ESC");
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 680, 0x00FFFFFF, "Number of iteration: +/-");
	frct->maxIter_str = ft_itoa(frct->maxIter);
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   270, 680, 0x00FFFFFF, frct->maxIter_str);
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 700, 0x00FFFFFF, "Move: arrow keys");
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 720, 0x00FFFFFF, "Zoom in/out: scroll wheel");
	if (frct->fractal == JULIA)
	{
		if(frct->lock == 1)
			mlx_string_put(frct->mlx->ptr, frct->mlx->win,
						   20, 600, 0x00FFFFFF, "Lock status: On");
		else
			mlx_string_put(frct->mlx->ptr, frct->mlx->win,
						   20, 600, 0x00FFFFFF, "Lock status: Off");
	}
}