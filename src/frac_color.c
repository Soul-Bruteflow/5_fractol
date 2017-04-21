#include "fract.h"

//int *hsv_to_rgb_t(int h, float s, float v)
//{
//	if ( v > 1.0 ) v = 1.0;
//	double hp = h/60.0;
//	float c = v * s;
//	float x = c*(1 - abs(((int)hp % 2) - 1));
//	int rgb[3] = [0];
//
//	if ( 0<=hp && hp<1 ) rgb = [c, x, 0];
//	if ( 1<=hp && hp<2 ) rgb = [x, c, 0];
//	if ( 2<=hp && hp<3 ) rgb = [0, c, x];
//	if ( 3<=hp && hp<4 ) rgb = [0, x, c];
//	if ( 4<=hp && hp<5 ) rgb = [x, 0, c];
//	if ( 5<=hp && hp<6 ) rgb = [c, 0, x];
//
//	float m = v - c;
//	rgb[0] += m;
//	rgb[1] += m;
//	rgb[2] += m;
//
//	rgb[0] *= 255;
//	rgb[1] *= 255;
//	rgb[2] *= 255;
//
//	rgb[0] = parseInt ( rgb[0] );
//	rgb[1] = parseInt ( rgb[1] );
//	rgb[2] = parseInt ( rgb[2] );
//
//	return rgb;
//}

// http://stackoverflow.com/questions/369438/smooth-spectrum-for-mandelbrot-set-rendering
// alex russel : http://stackoverflow.com/users/2146829/alex-russell
//
//t_rgba MapColor(int i, double r, double c)
//{
//	int di= i;
//	double zn;
//	double hue;
//
//	zn = sqrt(r + c);
//	hue = di + 1.0 - log(log(abs(zn))) / log(2.0);  // 2 is escape radius
//	hue = 0.95 + 20.0 * hue; // adjust to make it prettier
//	// the hsv function expects values from 0 to 360
//	while (hue > 360.0)
//		hue -= 360.0;
//	while (hue < 0.0)
//		hue += 360.0;
//
//	t_rgba	rgb_t;
//	t_hsv	hsv;
//
//	hsv.hsv[0] = hue;
//	hsv.hsv[0] = 0.8;
//	hsv.hsv[0] = 1.0;
//	rgb_t = hsv_to_rgb(hsv);
//
//	return (rgb_t);
//}