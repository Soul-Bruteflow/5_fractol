#include "fract.h"

void mandelbrot_core(void)
{
	t_frct *f;

	f = (t_frct*)(malloc(sizeof(t_frct)));
	f->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	mandelbrot_default(f);
	frac_mlx_setup(f);
	threads_core(f);
	frac_first_draw(f);
	mlx_mouse_hook(f->mlx->win, frac_core_mouse, f);
	mlx_hook(f->mlx->win, 2, 5, frac_core_keyb, f);
	mlx_loop(f->mlx->ptr);
}

void mandelbrot_default(t_frct *f)
{
	f->fractal = MANDELBROT;
	f->zoom = 0.6;
	f->moveX = -0.5f;
	f->moveY = 0;
	f->maxIter = 60;
}