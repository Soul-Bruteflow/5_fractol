#include "fract.h"

int		track_mouse(int x, int y, t_frct *frct)
{
	if (frct->jul->lock == 0)
	{
		frct->jul->mouse_x = x;
		frct->jul->mouse_y = y;
		frac_redraw(frct);
	}
	return (0);
}

void	frac_zoom_in(t_frct *frct)
{
	frct->jul->zoom *= 1.090;
	frac_redraw(frct);
}

void	frac_zoom_out(t_frct *frct)
{
	frct->jul->zoom /= 1.090;
	frac_redraw(frct);
}

int	frac_core_mouse(int button, int x, int y, t_frct *frct)
{
	if (button == 1)
	{
		if (frct->jul->lock == 1)
		{
			frct->jul->lock = 0;
			frac_redraw_ui(frct);
		}
		else
		{
			frct->jul->lock = 1;
			frac_redraw_ui(frct);
		}
	}
	if (button == 4)
	{
		frac_zoom_in(frct);
	}
	if (button == 5)
	{
		frac_zoom_out(frct);
	}
	return (0);
}