/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:55:34 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 13:10:41 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		julia_ui(t_frct *f)
{
	if (f->fractal == JULIA)
	{
		if (f->lock == 1)
			mlx_string_put(f->mlx->ptr, f->mlx->win,
					20, 600, 0x00FFFFFF, "Lock status: On");
		else
			mlx_string_put(f->mlx->ptr, f->mlx->win,
					20, 600, 0x00FFFFFF, "Lock status: Off");
	}
}

void			frac_redraw_ui(t_frct *frct)
{
	mlx_clear_window(frct->mlx->ptr, frct->mlx->win);
	mlx_put_image_to_window(frct->mlx->ptr, frct->mlx->win, frct->mlx->img,
			frct->mlx->imgx, frct->mlx->imgy);
	frac_ui(frct);
}

void			frac_ui(t_frct *f)
{
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 640, 0x00FFFFFF, "Controls:");
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 660, 0x00FFFFFF, "ESC    | Exit");
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 680, 0x00FFFFFF, "+/-    | Number of iterations");
	f->maxiter_str = ft_itoa(f->maxiter);
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			315, 680, 0x00FFFFFF, f->maxiter_str);
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 700, 0x00FFFFFF, "Arrows | Move");
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 720, 0x00FFFFFF, "Scroll | Zoom in/out");
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 740, 0x00FFFFFF, "q key  | Change color scheme");
	mlx_string_put(f->mlx->ptr, f->mlx->win,
			20, 760, 0x00FFFFFF, "Space  | Reset");
	julia_ui(f);
}
