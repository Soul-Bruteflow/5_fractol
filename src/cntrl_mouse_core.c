/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl_mouse_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:43:23 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:47:58 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	frac_zoom_in(t_frct *frct, int x, int y)
{
	x -= frct->mlx->wcenx;
	y -= frct->mlx->wceny;
	frct->zoom *= 1.050;
	frct->movex += x / frct->zoom / WIDTH / 1.8;
	frct->movey -= y / frct->zoom / HEIGHT / 1.8;
	frac_redraw(frct);
}

static void	frac_zoom_out(t_frct *frct, int x, int y)
{
	x -= frct->mlx->wcenx;
	y -= frct->mlx->wceny;
	frct->zoom /= 1.050;
	frct->movex += x / frct->zoom / WIDTH / 1.8;
	frct->movey -= y / frct->zoom / HEIGHT / 1.8;
	frac_redraw(frct);
}

int			track_mouse(int x, int y, t_frct *frct)
{
	if (frct->lock == 0)
	{
		frct->cr = x * 4.0f / WIDTH - 2;
		frct->ci = y * 4.0f / HEIGHT - 2;
		frac_redraw(frct);
	}
	return (0);
}

int			frac_core_mouse(int button, int x, int y, t_frct *frct)
{
	if (frct->fractal == JULIA)
		if (button == 1)
		{
			if (frct->lock == 1 || frct->lock == -1)
			{
				frct->lock = 0;
				frac_redraw_ui(frct);
			}
			else
			{
				frct->lock = 1;
				frac_redraw_ui(frct);
			}
		}
	if (button == 4)
		frac_zoom_in(frct, x, y);
	if (button == 5)
		frac_zoom_out(frct, x, y);
	return (0);
}
