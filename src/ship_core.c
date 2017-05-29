/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:09:09 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 11:09:20 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ship_core(void)
{
	t_frct *f;

	f = (t_frct*)(malloc(sizeof(t_frct)));
	if (f == NULL)
		frac_error(MALLCHECK);
	f->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	if (f->mlx == NULL)
		frac_error(MALLCHECK);
	ship_default(f);
	f->color = 0;
	frac_mlx_setup(f);
	threads_core(f);
	frac_first_draw(f);
	mlx_mouse_hook(f->mlx->win, frac_core_mouse, f);
	mlx_hook(f->mlx->win, 2, 5, frac_core_keyb, f);
	mlx_expose_hook(f->mlx->win, expose_hook, f);
	mlx_loop(f->mlx->ptr);
}

void	ship_default(t_frct *f)
{
	f->fractal = SHIP;
	f->zoom = 0.6;
	f->movex = -0.5f;
	f->movey = 0;
	f->maxiter = 60;
}
