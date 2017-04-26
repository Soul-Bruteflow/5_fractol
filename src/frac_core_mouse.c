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

void	frac_zoom_in(t_frct *frct, int x, int y)
{
	int ad_x = 0;
	int ad_y = 0;
	float percentage_x = 0;
	float percentage_y = 0;
	if (x < 750)
	{
		ad_x = 750 - x;
		percentage_x = (float)ad_x * (float)100 / (float)frct->mlx->wcenx;
	}
	if (x > 750)
	{
		ad_x = x - 750;
		percentage_x = (float)ad_x * (float)100 / (float)frct->mlx->wcenx;
	}
	if (y < 450)
	{
		ad_y = 450 - y;
		percentage_y = (float)ad_y * (float)100 / (float)frct->mlx->wceny;
	}
	if (y > 450)
	{
		ad_y = y - 450;
		percentage_y = (float)ad_y * (float)100 / (float)frct->mlx->wceny;
	}
	percentage_x = (float)(1.5 / frct->jul->zoom) * percentage_x / 100.0f;
	percentage_y = (float)(1.0 / frct->jul->zoom) * percentage_y / 100.0f;
	if (x < frct->mlx->wcenx && y < frct->mlx->wceny)
	{
		frct->jul->moveX -= percentage_x;
		frct->jul->moveY -= percentage_y;
	}
	if (x > frct->mlx->wcenx && y > frct->mlx->wceny)
	{
		frct->jul->moveX += percentage_x;
		frct->jul->moveY += percentage_y;
	}
	frct->jul->zoom *= 1.090;
	frac_redraw(frct);
}

void	frac_zoom_out(t_frct *frct, int x, int y)
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
	if (button == 3)
	{
		printf("1\n");
		frac_zoom_in(frct, x , y);
	}
	if (button == 5)
	{
		frac_zoom_out(frct, x , y);
	}
	return (0);
}