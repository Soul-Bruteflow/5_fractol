/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:21:24 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 11:05:19 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "julia")))
			julia_core();
		else if (!(ft_strcmp(av[1], "mandelbrot")))
			mandelbrot_core();
		else if (!(ft_strcmp(av[1], "ship")))
			ship_core();
		else
			frac_error(USAGE);
	}
	else
		frac_error(USAGE);
}
