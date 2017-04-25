#include "fract.h"

void	frac_move(int kcode, t_frct *frct)
{
	if (kcode == UP)
	{
		frct->jul->moveY += 0.0200 / frct->jul->zoom;
	}
	if (kcode == DOWN)
	{
		frct->jul->moveY -= 0.0200 / frct->jul->zoom;
	}
	if (kcode == LEFT)
	{
		frct->jul->moveX += 0.0200 / frct->jul->zoom;
	}
	if (kcode == RIGHT)
	{
		frct->jul->moveX -= 0.0200 / frct->jul->zoom;
	}
	frac_redraw(frct);
}

int		frac_core_keyb(int kcode, t_frct *frct)
{
//	printf("%d\n", kcode);
	if (kcode == SPC)
	{

	}
	if (kcode == ESC)
		exit(0);
	if (kcode == UP || kcode == DOWN || kcode == LEFT || kcode == RIGHT)
		frac_move(kcode, frct);

	return (0);
}