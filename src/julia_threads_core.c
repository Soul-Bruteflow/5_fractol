#include "fract.h"

static void init_thread_zones(t_frct *frct);

void	julia_threads_core(t_frct *frct)
{
	int i;
	pthread_t* threads;

	init_thread_zones(frct);
	threads = (pthread_t*)malloc(frct->mlx->height * sizeof(pthread_t));
	for (frct->tid = 0; frct->tid < N_OF_TREDS; frct->tid++)
	{
		t_frct *arg = (t_frct*)malloc(sizeof(t_frct));
		memcpy(arg, frct, sizeof(t_frct));
		pthread_create(&threads[frct->tid], NULL, julia_worker, arg);
	}
	for (i = 0; i < N_OF_TREDS; i++)
		pthread_join(threads[i], NULL);
}

static void init_thread_zones(t_frct *frct)
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