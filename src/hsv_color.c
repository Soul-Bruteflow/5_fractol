#include "fract.h"

void hsv_color(t_frct *f)
{
	f->hsv.hsv[0] = 0.95f + 5 * f->smooth_col;
	f->hsv.hsv[1] = 0.6f;
	f->hsv.hsv[2] = 1.0f;
	f->rgba = ft_hsv_to_rgb(f->hsv);
}