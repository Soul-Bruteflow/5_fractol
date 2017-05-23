#include "fract.h"

static void thread_init_zones(t_frct *frct);
static void threads_create(t_frct *frct, t_frct *args, pthread_t* treds);
static void threads_join(pthread_t* treds);
static void thread_copy_args(t_frct *frct, t_frct *args);

void	julia_threads_core(t_frct *frct)
{
	pthread_t *treds;
	t_frct *args;

	args = (t_frct*)malloc(sizeof(t_frct) * N_OF_TREDS);
	treds = (pthread_t*)malloc(sizeof(pthread_t) * frct->mlx->height);
	thread_init_zones(frct);
	thread_copy_args(frct, args);
	threads_create(frct, args, treds);
	threads_join(treds);
	free(args);
	free(treds);
}

static void threads_create(t_frct *frct, t_frct *args, pthread_t* treds)
{
	frct->tid = 0;
	while (frct->tid < N_OF_TREDS)
	{
		args[frct->tid].tid = frct->tid;
		pthread_create(&treds[frct->tid], NULL, julia_worker, &args[frct->tid]);
		frct->tid++;
	}
}

static void threads_join(pthread_t* treds)
{
	int i;

	i = 0;
	while (i < N_OF_TREDS)
	{
		pthread_join(treds[i], NULL);
		i++;
	}
}

static void thread_copy_args(t_frct *frct, t_frct *args)
{
	int i;

	i = 0;
	while (i < N_OF_TREDS)
	{
		ft_memcpy(&args[i], frct, sizeof(t_frct));
		i++;
	}
}

static void thread_init_zones(t_frct *frct)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = 0;
	j = 1;
	while (i < N_OF_TREDS)
	{
		frct->start_y[i] = y;
		frct->start_x[i] = x;
		frct->end_y[i] = y + 200;
		frct->end_x[i] = x + 400;
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