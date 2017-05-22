#include "fract.h"

void	frac_redraw(t_frct *frct)
{
	mlx_clear_window(frct->mlx->ptr, frct->mlx->win);

	ft_memset(frct->mlx->str,'\0', frct->mlx->str_size);
//	ft_bzero(frct->mlx->str, frct->mlx->str_size);
	julia_threads_core(frct);
//	frac_julia(frct);
//	fdf_draw(mlx);
	mlx_put_image_to_window(frct->mlx->ptr, frct->mlx->win, frct->mlx->img,
							frct->mlx->imgx, frct->mlx->imgy);
	frac_ui(frct);
}

void	frac_first_draw(t_frct *frct)
{
//	frac_draw(mlx);
	frct->mlx->win = mlx_new_window(frct->mlx->ptr, frct->mlx->width,
									frct->mlx->height, "Fractol");
	if (frct->mlx->win == NULL)
		exit(0);
	mlx_put_image_to_window(frct->mlx->ptr, frct->mlx->win, frct->mlx->img,
							frct->mlx->imgx, frct->mlx->imgy);
	frac_ui(frct);
}

void	frac_mlx_setup(t_frct *frct)
{
	frct->run_flag = 0;
	frct->mlx->imgx = 0;
	frct->mlx->imgy = 0;
	frct->mlx->width = WIDTH;
	frct->mlx->height = HEIGHT;
	frct->mlx->wcenx = frct->mlx->width / 2;
	frct->mlx->wceny = frct->mlx->height / 2;
	frct->mlx->wcurx = frct->mlx->wcenx;
	frct->mlx->wcury = frct->mlx->wceny;
	frct->mlx->ptr = mlx_init();
	if (frct->mlx->ptr == NULL)
		exit(0);
	frct->mlx->img = mlx_new_image(frct->mlx->ptr,
								   frct->mlx->width, frct->mlx->height);
	if (frct->mlx->img == NULL)
		exit(0);
	frct->mlx->str = mlx_get_data_addr(frct->mlx->img, &frct->mlx->bit,
									   &frct->mlx->line_sz, &frct->mlx->end);
	if (frct->mlx->str == NULL)
		exit(0);
	frct->mlx->str_size = (size_t)frct->mlx->width * frct->mlx->height
						  * (frct->mlx->bit / 8);
}