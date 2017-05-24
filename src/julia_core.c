#include "fract.h"


void julia_core(void)
{
	t_frct *f;

	f = (t_frct*)(malloc(sizeof(t_frct)));
	f->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	julia_default(f);
	frac_mlx_setup(f);
	threads_core(f);
	frac_first_draw(f);
	mlx_mouse_hook(f->mlx->win, frac_core_mouse, f);
	mlx_hook(f->mlx->win, 6, 0, track_mouse, f);
	mlx_hook(f->mlx->win, 2, 5, frac_core_keyb, f);
	mlx_loop(f->mlx->ptr);
}

void julia_default(t_frct *f)
{
	f->fractal = JULIA;
	f->lock = 1;
	f->cR = 0.5459;
	f->cI = 0.0896;
	f->zoom = 1;
	f->moveX = 0;
	f->moveY = 0;
	f->maxIter = 60;
}