#include "fract.h"

void	frac_redraw(t_m *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_bzero(mlx->str, mlx->str_size);
//	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
//	fdf_ui(mlx);
}

void	frac_first_draw(t_m *mlx)
{
//	frac_draw(mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "Fractol");
	if (mlx->win == NULL)
		exit(0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
	frac_ui(mlx);
}

void	frac_mlx_setup(t_m *mlx)
{
	mlx->imgx = 0;
	mlx->imgy = 0;
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->wcenx = mlx->width / 2;
	mlx->wceny = mlx->height / 2;
	mlx->wcurx = mlx->wcenx;
	mlx->wcury = mlx->wceny;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(0);
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (mlx->img == NULL)
		exit(0);
	mlx->str = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->line_sz, &mlx->end);
	if (mlx->str == NULL)
		exit(0);
	mlx->str_size = mlx->width * mlx->height * (mlx->bit / 8);
}