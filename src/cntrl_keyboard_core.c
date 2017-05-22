#include "fract.h"

void	frac_move(int kcode, t_frct *frct)
{
	if (kcode == UP)
	{
		frct->moveY += 0.0200 / frct->zoom;
	}
	if (kcode == DOWN)
	{
		frct->moveY -= 0.0200 / frct->zoom;
	}
	if (kcode == LEFT)
	{
		frct->moveX += 0.0200 / frct->zoom;
	}
	if (kcode == RIGHT)
	{
		frct->moveX -= 0.0200 / frct->zoom;
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