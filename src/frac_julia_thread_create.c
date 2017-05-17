#include "fract.h"

void	frac_julia_thread_create(t_frct *frct)
{
	int i;
	pthread_t* threads;

	threads = (pthread_t*)malloc(frct->mlx->height * sizeof(pthread_t));

	for (frct->jul->tid = 0; frct->jul->tid < frct->mlx->height; frct->jul->tid++)
	{
		t_frct *arg = (t_frct*)malloc(sizeof(t_frct));
		memcpy(arg, frct, sizeof(t_frct));
		pthread_create(&threads[frct->jul->tid], NULL, frac_julia, arg);
	}

	for (i = 0; i < frct->mlx->height; i++)
		pthread_join(threads[i], NULL);
}