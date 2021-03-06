/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:50:36 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:51:47 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		expose_hook(void *param)
{
	frac_redraw(param);
	return (0);
}

void	frac_redraw(t_frct *frct)
{
	mlx_clear_window(frct->mlx->ptr, frct->mlx->win);
	ft_memset(frct->mlx->str, '\0', frct->mlx->str_size);
	threads_core(frct);
	mlx_put_image_to_window(frct->mlx->ptr, frct->mlx->win, frct->mlx->img,
							frct->mlx->imgx, frct->mlx->imgy);
	frac_ui(frct);
}

void	frac_first_draw(t_frct *frct)
{
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
	frct->mlx->imgx = 0;
	frct->mlx->imgy = 0;
	frct->mlx->width = WIDTH;
	frct->mlx->height = HEIGHT;
	frct->mlx->wcenx = frct->mlx->width / 2;
	frct->mlx->wceny = frct->mlx->height / 2;
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
