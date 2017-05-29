/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:11:38 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 11:18:38 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	thread_init_zones(t_frct *f)
{
	int				x;
	int				y;
	int				i;
	int				j;

	x = 0;
	y = 0;
	i = 0;
	j = 1;
	while (i < N_OF_TREDS)
	{
		f->start_y[i] = y;
		f->start_x[i] = x;
		f->end_y[i] = y + 200;
		f->end_x[i] = x + 400;
		x += 400;
		if (j % 4 == 0)
		{
			y += 200;
			x = 0;
		}
		i++;
		j++;
	}
}

static void	thread_copy_args(t_frct *frct, t_frct *args)
{
	int i;

	i = 0;
	while (i < N_OF_TREDS)
	{
		ft_memcpy(&args[i], frct, sizeof(t_frct));
		i++;
	}
}

static void	threads_create(t_frct *f, t_frct *args, pthread_t *treds,
		void *(*worker)(void *arg))
{
	f->tid = 0;
	while (f->tid < N_OF_TREDS)
	{
		args[f->tid].tid = f->tid;
		pthread_create(&treds[f->tid], NULL, worker, &args[f->tid]);
		f->tid++;
	}
}

static void	threads_join(pthread_t *treds)
{
	int i;

	i = 0;
	while (i < N_OF_TREDS)
	{
		pthread_join(treds[i], NULL);
		i++;
	}
}

void		threads_core(t_frct *f)
{
	pthread_t		*treds;
	t_frct			*args;

	args = (t_frct*)malloc(sizeof(t_frct) * N_OF_TREDS);
	treds = (pthread_t*)malloc(sizeof(pthread_t) * f->mlx->height);
	thread_init_zones(f);
	thread_copy_args(f, args);
	if (f->fractal == JULIA)
		threads_create(f, args, treds, julia_worker);
	else if (f->fractal == MANDELBROT)
		threads_create(f, args, treds, mandelbrot_worker);
	else if (f->fractal == SHIP)
		threads_create(f, args, treds, ship_worker);
	threads_join(treds);
	free(args);
	free(treds);
}
