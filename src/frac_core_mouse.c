#include "fract.h"

int		track_mouse(int x, int y, t_frct *frct)
{
	if (frct->lock == 0)
	{
		frct->mouse_x = x;
		frct->mouse_y = y;
		printf("%d\n", frct->mouse_x);
	}
	return (0);
}

int	frac_core_mouse(int button, int x, int y, t_frct *frct)
{
	if (button == 1)
	{
		if (frct->lock == 1)
			frct->lock = 0;
		else
			frct->lock = 1;
		printf("%d\n", frct->lock);
	}
	return (0);
}