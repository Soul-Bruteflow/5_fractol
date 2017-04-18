#include "fract.h"

t_rgba	hsv_to_rgb(t_hsv hsv)
{
	double r = 0, g = 0, b = 0;

	if (hsv.hsv[1] == 0)
	{
		r = hsv.hsv[2];
		g = hsv.hsv[2];
		b = hsv.hsv[2];
	}
	else
	{
		int i;
		double f, p, q, t;
		if (hsv.hsv[0] == 360)
			hsv.hsv[0] = 0;
		else
			hsv.hsv[0] = hsv.hsv[0] / 60;
		i = (int)trunc(hsv.hsv[0]);
		f = hsv.hsv[0] - i;
		p = hsv.hsv[2] * (1.0 - hsv.hsv[1]);
		q = hsv.hsv[2] * (1.0 - (hsv.hsv[1] * f));
		t = hsv.hsv[2] * (1.0 - (hsv.hsv[1] * (1.0 - f)));

		switch (i)
		{
			case 0:
				r = hsv.hsv[2];
				g = t;
				b = p;
				break;

			case 1:
				r = q;
				g = hsv.hsv[2];
				b = p;
				break;

			case 2:
				r = p;
				g = hsv.hsv[2];
				b = t;
				break;

			case 3:
				r = p;
				g = q;
				b = hsv.hsv[2];
				break;

			case 4:
				r = t;
				g = p;
				b = hsv.hsv[2];
				break;

			default:
				r = hsv.hsv[2];
				g = p;
				b = q;
				break;
		}

	}
	t_rgba ret_rgb;
	ret_rgb.rgba[0] = r * 255;
	ret_rgb.rgba[1] = g * 255;
	ret_rgb.rgba[2] = b * 255;
	ret_rgb.rgba[3] = '\0';
	ret_rgb.rgba[4] = '\0';
	return (ret_rgb);
}