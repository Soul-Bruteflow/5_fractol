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
	int ad_x = 0;
	int ad_y = 0;
	float percentage_x = 0;
	float percentage_y = 0;
	if (x < HALF_WIDTH)
	{
		ad_x = HALF_WIDTH - x;
		percentage_x = (float)ad_x * (float)100 / (float)frct->mlx->wcenx;
	}
	if (x > HALF_WIDTH)
	{
		ad_x = x - HALF_WIDTH;
		percentage_x = (float)ad_x * (float)100 / (float)frct->mlx->wcenx;
	}
	if (y < HALF_HEIGHT)
	{
		ad_y = HALF_HEIGHT - y;
		percentage_y = (float)ad_y * (float)100 / (float)frct->mlx->wceny;
	}
	if (y > HALF_HEIGHT)
	{
		ad_y = y - HALF_HEIGHT;
		percentage_y = (float)ad_y * (float)100 / (float)frct->mlx->wceny;
	}
	percentage_x = (float)(1.2 / frct->zoom) * percentage_x / 100.0f;
	percentage_y = (float)(1.2 / frct->zoom) * percentage_y / 100.0f;
	if (x < frct->mlx->wcenx && y < frct->mlx->wceny)
	{
		frct->moveX -= (percentage_x / 5);
		frct->moveY -= (percentage_y / 5);
	}
	if (x > frct->mlx->wcenx && y > frct->mlx->wceny)
	{
		frct->moveX += (percentage_x / 5);
		frct->moveY += (percentage_y / 5);
	}
	if (x > frct->mlx->wcenx && y < frct->mlx->wceny)
	{
		frct->moveX += (percentage_x / 5);
		frct->moveY -= (percentage_y / 5);
	}
	if (x < frct->mlx->wcenx && y > frct->mlx->wceny)
	{
		frct->moveX -= (percentage_x / 5);
		frct->moveY += (percentage_y / 5);
	}
	frct->zoom *= 1.090;
	frac_redraw(frct);
}

void	frac_zoom_out(t_frct *frct, int x, int y)
{
	frct->zoom /= 1.090;
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