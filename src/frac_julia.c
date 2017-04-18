#include "fract.h"

void	frac_julia(t_m *mlx)
{
//	screen(400, 300, 0, "Julia Set");

	double cRe, cIm;
	double newRe, newIm, oldRe, oldIm;
	double zoom = 1, moveX = 0, moveY = 0;
//	ColorRGB color;
	int h = 900;
	int w = 1500;
	int maxIterations = 300;


	cRe = 0.8;
	cIm = 0;
	for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++)
		{
			newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
			int i;
			for(i = 0; i < maxIterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				if((newRe * newRe + newIm * newIm) > 4) break;
			}
			int vcolor = 200;
			if (i == maxIterations)
				vcolor = 0;
//			color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
//			int collor = (i % 122, 255, 255 * (i < maxIterations));
//			mlx_pixel_put(mlx->ptr, mlx->win, x, y, collor);
			frac_put_pixel(x, y, i, mlx, newRe, newIm);
		}
}