/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:21:24 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/11 14:21:28 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	main(int ac, char **av)
{
	t_frct *frct;

	if (ac == 2)
	{
		frct = (t_frct*)(malloc(sizeof(t_frct)));
		frct->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
		frac_mlx_setup(frct);
		frac_julia(frct);
//		frac_mandelbrot(mlx);
		frac_first_draw(frct);
//		frct->mouse_x = 0;
//		frct->mouse_y = 0;
		mlx_mouse_hook(frct->mlx->win, frac_core_mouse, frct);
		mlx_hook(frct->mlx->win, 6, 0, track_mouse, frct);
		mlx_hook(frct->mlx->win, 2, 5, frac_core_keyb, frct);
		mlx_loop(frct->mlx->ptr);
	}
	else
		frac_error(USAGE);
}
