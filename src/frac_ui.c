#include "fract.h"

void	frac_ui(t_m *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 20, 740, 0x00FFFFFF, "Controls:");
	mlx_string_put(mlx->ptr, mlx->win, 20, 760, 0x00FFFFFF, "Exit: ESC");
}