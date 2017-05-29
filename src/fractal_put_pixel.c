/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_put_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:52:06 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:54:05 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		escape_color(t_frct *f)
{
	float			zn;
	float			nu;
	float			j;

	zn = logf(f->sq);
	nu = logf(zn / logf(2)) / logf(2);
	j = f->i + 1 - nu;
	f->rgba.rgba[0] = (unsigned char)(sin(0.016 * j + 4) * 230 + 25);
	f->rgba.rgba[1] = (unsigned char)(sin(0.013 * j + 2) * 230 + 25);
	f->rgba.rgba[2] = (unsigned char)(sin(0.01 * j + 1) * 230 + 25);
}

void			fractal_put_pixel(t_frct *f)
{
	size_t			i;

	if (f->color == 0)
		escape_color(f);
	i = (size_t)(f->y * f->mlx->line_sz +
			(f->x * (f->mlx->bit / 8)));
	if (i < f->mlx->str_size && f->x > 0 &&
			f->x < f->mlx->width)
	{
		if (f->mlx->end == 1)
		{
			f->mlx->str[i] = f->rgba.rgba[0];
			f->mlx->str[i + 1] = f->rgba.rgba[1];
			f->mlx->str[i + 2] = f->rgba.rgba[2];
		}
		else if (f->mlx->end == 0)
		{
			f->mlx->str[i] = f->rgba.rgba[2];
			f->mlx->str[i + 1] = f->rgba.rgba[1];
			f->mlx->str[i + 2] = f->rgba.rgba[0];
		}
	}
}
