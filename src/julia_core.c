#include "fract.h"


void julia_core(void)
{
	t_frct *frct;

	frct = (t_frct*)(malloc(sizeof(t_frct)));
	frct->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	julia_default(frct);
	frac_mlx_setup(frct);
	julia_threads_core(frct);
	frac_first_draw(frct);
	mlx_mouse_hook(frct->mlx->win, frac_core_mouse, frct);
	mlx_hook(frct->mlx->win, 6, 0, track_mouse, frct);
	mlx_hook(frct->mlx->win, 2, 5, frac_core_keyb, frct);
	mlx_loop(frct->mlx->ptr);
}

void julia_default(t_frct *frct)
{
	frct->lock = -1;
	frct->cR = 0.5459;
	frct->cI = 0.0896;
	frct->zoom = 1;
	frct->moveX = 0;
	frct->moveY = 0;
	frct->maxIter = 60;
}