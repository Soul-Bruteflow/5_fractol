#include "fract.h"

int		track_mouse(int x, int y, t_frct *frct)
{
	if (frct->lock == 0)
	{
		frct->cR = x * 4.0f / WIDTH - 2;
		frct->cI = y * 4.0f / HEIGHT - 2;
		frac_redraw(frct);
	}
	return (0);
}

void	frac_zoom_in(t_frct *frct, int x, int y)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	frct->zoom *= 1.050;
	frct->moveX += x / frct->zoom / WIDTH / 1.8;
	frct->moveY -= y / frct->zoom / HEIGHT / 1.8;
	frac_redraw(frct);
}

void	frac_zoom_out(t_frct *frct, int x, int y)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	frct->zoom /= 1.050;
	frct->moveX += x / frct->zoom / WIDTH / 1.8;
	frct->moveY -= y / frct->zoom / HEIGHT / 1.8;
	frac_redraw(frct);
}

int	frac_core_mouse(int button, int x, int y, t_frct *frct)
{
	if (button == 1)
	{
		if (frct->lock == 1 || frct->lock == -1)
		{
			frct->lock = 0;
			frac_redraw_ui(frct);
		}
		else
		{
			frct->lock = 1;
			frac_redraw_ui(frct);
		}
	}
	if (button == 4)
	{
		frac_zoom_in(frct, x , y);
	}
	if (button == 5)
	{
		frac_zoom_out(frct, x , y);
	}
	return (0);
}