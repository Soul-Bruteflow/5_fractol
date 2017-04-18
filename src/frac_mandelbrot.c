#include "fract.h"

void	frac_mandelbrot(t_m *mlx)
{
	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	double zoom = 0.6, moveX = -0.5, moveY = 0;
//	ColorRGB color;
	int maxIterations = 300;
	int h = 900;
	int w = 1500;

	for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++)
		{
			pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			pi = (y - h / 2) / (0.5 * zoom * h) + moveY;
			newRe = newIm = oldRe = oldIm = 0;
			int i;
			for(i = 0; i < maxIterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if((newRe * newRe + newIm * newIm) > 4) break;
			}
//			color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
			int vcolor = 0;
			if (i == maxIterations)
				vcolor = 200;
			frac_put_pixel(x, y, i, mlx, newRe, newIm);
		}
}