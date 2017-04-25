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
				   20, 740, 0x00FFFFFF, "Controls:");
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 760, 0x00FFFFFF, "Exit: ESC");
	if(frct->jul->lock == 1)
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 700, 0x00FFFFFF, "Lock status: On");
	else
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 700, 0x00FFFFFF, "Lock status: Off");
}