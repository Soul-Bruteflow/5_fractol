/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:49:28 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:50:20 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

/*
** error_exit
** Outputs taken argument string, to the standard output.
** And terminates the program.
*/

static void		error_exit(char *s)
{
	char			*use;

	use = s;
	write(1, use, ft_strlen(use));
	exit(0);
}

/*
** fdf_error
** Takes an typedef int and sends the corresponding error line to error_exit.
*/

void			frac_error(int n)
{
	if (n == USAGE)
		error_exit("Usage: ./fractol <fractal>\nAvalible fractals:\n1. "
				"julia\n2. mandelbrot\n3. ship");
}
