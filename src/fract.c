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
	t_m	*mlx;

	if (ac == 2)
	{
		mlx = (t_m*)(malloc(sizeof(t_m)));
		frac_mlx_setup(mlx);
		frac_julia(mlx);
//		frac_mandelbrot(mlx);
		frac_first_draw(mlx);
		mlx_hook(mlx->win, 2, 5, &frac_key_core, &mlx);
		mlx_loop(mlx->ptr);
	}
	else
		frac_error(USAGE);
}
