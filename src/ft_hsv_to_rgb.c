/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:57:05 by mvlad             #+#    #+#             */
/*   Updated: 2017/05/29 10:57:18 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		rgb_assign(t_hsv *hsv, float n1, float n2, float n3)
{
	hsv->r = n1;
	hsv->g = n2;
	hsv->b = n3;
}

static void		rgb_condition(t_hsv *hsv, int i)
{
	if (i == 0)
		rgb_assign(hsv, hsv->hsv[2], hsv->t, hsv->p);
	else if (i == 1)
		rgb_assign(hsv, hsv->q, hsv->hsv[2], hsv->p);
	else if (i == 2)
		rgb_assign(hsv, hsv->p, hsv->hsv[2], hsv->t);
	else if (i == 3)
		rgb_assign(hsv, hsv->p, hsv->q, hsv->hsv[2]);
	else if (i == 4)
		rgb_assign(hsv, hsv->t, hsv->p, hsv->hsv[2]);
	else
		rgb_assign(hsv, hsv->hsv[2], hsv->p, hsv->q);
}

t_rgba			ft_hsv_to_rgb(t_hsv hsv)
{
	int				i;
	t_rgba			ret_rgb;

	hsv.r = 0;
	hsv.g = 0;
	hsv.b = 0;
	if (hsv.hsv[1] == 0)
		rgb_assign(&hsv, hsv.hsv[2], hsv.hsv[2], hsv.hsv[2]);
	else
	{
		if (hsv.hsv[0] == 360)
			hsv.hsv[0] = 0;
		else
			hsv.hsv[0] = hsv.hsv[0] / 60;
		i = (int)trunc(hsv.hsv[0]);
		hsv.f = hsv.hsv[0] - i;
		hsv.p = hsv.hsv[2] * (1.0f - hsv.hsv[1]);
		hsv.q = hsv.hsv[2] * (1.0f - (hsv.hsv[1] * hsv.f));
		hsv.t = hsv.hsv[2] * (1.0f - (hsv.hsv[1] * (1.0f - hsv.f)));
		rgb_condition(&hsv, i);
	}
	ret_rgb.rgba[0] = (unsigned char)(hsv.r * 255);
	ret_rgb.rgba[1] = (unsigned char)(hsv.g * 255);
	ret_rgb.rgba[2] = (unsigned char)(hsv.b * 255);
	return (ret_rgb);
}
