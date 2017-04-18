#include "fract.h"

void	frac_put_pixel(int x, int y, int f, t_m *mlx, double newR, double newI)
{
	size_t			i;
	int				rgb[3];
	t_hsv			hsv;
	t_rgba			rgba;


	rgba = MapColor(f, newR, newI);

	rgb[0] = rgba.rgba[0];
	rgb[1] = rgba.rgba[1];
	rgb[2] = rgba.rgba[2];

//	double zn = sqrt(x * x + y * y);
//	double zn = sqrt(newR + newI);

	http://stackoverflow.com/questions/369438/smooth-spectrum-for-mandelbrot-set-rendering

//	double zn = sqrt(newR * newR + newI * newI);
//
//	double con_in = f + 1 - log(log(zn)) / log(2.0);



//	double con_in = f + 1 - (log(2) / zn) / log (2);
//	double con_in = log(log(zn) * log (2.0)) * log (2.0);

//	printf("%lf\n", con_in);

//	int colorI = (int)(sqrt(f + 1 - con_in) * 256 + 0) % colors.Length;
//	Color color = colors[colorI];

//	hsv.hsv[0] = f % 256;
//	hsv.hsv[1] = f % 255;
//	hsv.hsv[2] = f % 255 * (f < 300);

//	rgba = hsv_to_rgb(hsv);

////	double zn = sqrt(x * x + y * y);
//	double zn = sqrt(newR * newR + newI * newI);


//	double con_in = f + 1 - (log(2.0) / zn) / log (2.0);

//	double con_in = f - (log (log (zn)))/ log (2.0);

//	rgb[0] = (0 - 255) * con_in + 255;
//	rgb[1] = (0 - 79) * con_in + 79;
//	rgb[2] = (0 - 91) * con_in + 91;

	i = (y * mlx->line_sz + (x * (mlx->bit / 8)));
	if (i < mlx->str_size && x > 0 && x < mlx->width)
	{
//		rgb[0] = (unsigned char)(2 * (1 - con_in) * (con_in * con_in * con_in) * (255 - 127) + 127);
//		rgb[1] = (unsigned char)(4 * (1 - con_in * con_in) * (con_in * con_in) * (255 - 127) + 127);
//		rgb[2] = (unsigned char)(8 * (1 - con_in * con_in * con_in) * (con_in) * (255 - 127) + 127);


//		rgb[0] = (unsigned char)((0.016 * con_in + 4) * (255 - 200) + 200);
//		rgb[1] = (unsigned char)((0.013 * con_in + 2) * (255 - 200) + 200);
//		rgb[2] = (unsigned char)((0.01 * con_in + 1) * (255 - 200) + 200);

//		rgb[0] = (unsigned char)(sin(0.1 * con_in + 6) * 230 + 25);
//		rgb[1] = (unsigned char)(sin(0.2 * con_in + 3) * 230 + 25);
//		rgb[2] = (unsigned char)(sin(0.3 * con_in + 1) * 230 + 25);

//		rgb[0] = (unsigned char)(255 + (int)(0 * con_in) % (256 - 255));
//		rgb[1] = (unsigned char)(0 + (int)(16 * con_in) % (255 - 0));
//		rgb[2] = (unsigned char)(0 + (int)(0 * con_in) % (255 - 0));

//		rgb[0] = (unsigned char)(sin(0.016 * con_in + 4) * (255 - 127) + 127);
//		rgb[1] = (unsigned char)(sin(0.013 * con_in + 2) * (255 - 127) + 127);
//		rgb[2] = (unsigned char)(sin(0.01 * con_in + 1) * (255 - 127) + 127);

//		rgb[0] = (unsigned char)(sin(0.0006 * con_in + 4) * 127.5 + 127.5);
//		rgb[1] = (unsigned char)(sin(0.0006 * con_in + 2) * 127.5 + 127.5);
//		rgb[2] = (unsigned char)(sin(0.0006 * con_in + 0) * 127.5 + 127.5);

//		rgb[0] = (unsigned char)((0.01 * con_in + 0) * (255 - 127) + 127);
//		rgb[1] = (unsigned char)((0.22 * con_in + 0) * (255 - 127) + 127);
//		rgb[2] = (unsigned char)((0.09 * con_in + 0) * (255 - 127) + 127);
//		rgb[0] = f % 255 * f;
//		rgb[1] = f % 255 * f;
//		rgb[2] = f % 255 * f;
//		rgb[0] = 255;
//		rgb[1] = 13;
//		rgb[2] = 40;
		if (mlx->end == 1)
		{
			mlx->str[i] = rgb[0];
			mlx->str[i + 1] = rgb[1];
			mlx->str[i + 2] = rgb[2];
		}
		else if (mlx->end == 0)
		{
			mlx->str[i] = rgb[2];
			mlx->str[i + 1] = rgb[1];
			mlx->str[i + 2] = rgb[0];
		}
	}
}

void	frac_draw(void)
{
	return;
}