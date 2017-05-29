/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:59:44 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:59:57 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	julia_core(void)
{
	t_frct	*f;

	f = (t_frct*)(malloc(sizeof(t_frct)));
	if (f == NULL)
		frac_error(MALLCHECK);
	f->mlx = (t_mlx*)(malloc(sizeof(t_mlx)));
	if (f->mlx == NULL)
		frac_error(MALLCHECK);
	julia_default(f);
	f->color = 0;
	frac_mlx_setup(f);
	threads_core(f);
	frac_first_draw(f);
	mlx_mouse_hook(f->mlx->win, frac_core_mouse, f);
	mlx_hook(f->mlx->win, 6, 0, track_mouse, f);
	mlx_hook(f->mlx->win, 2, 5, frac_core_keyb, f);
	mlx_expose_hook(f->mlx->win, expose_hook, f);
	mlx_loop(f->mlx->ptr);
}

void	julia_default(t_frct *f)
{
	f->fractal = JULIA;
	f->lock = 1;
	f->cr = 0.5459;
	f->ci = 0.0896;
	f->zoom = 1;
	f->movex = 0;
	f->movey = 0;
	f->maxiter = 60;
}
