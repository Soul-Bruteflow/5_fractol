#include "fract.h"

void	frac_ui(t_frct *frct)
{
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 740, 0x00FFFFFF, "Controls:");
	mlx_string_put(frct->mlx->ptr, frct->mlx->win,
				   20, 760, 0x00FFFFFF, "Exit: ESC");
}