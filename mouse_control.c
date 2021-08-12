#include "fractol.h"

void	zooming(int keycode, int x, int y, t_fractol *fr)
{
	double	x_n;
	double	y_n;

	x_n = (x / fr->zoom) + fr->x1;
	y_n = (y / fr->zoom) + fr->y1;
	if (keycode == 4)
		fr->zoom *= 1.1;
	else
		fr->zoom /= 1.1;
	fr->x1 = x_n - (x / fr->zoom);
	fr->y1 = y_n - (y / fr->zoom);
	draw(fr);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fr)
{
	if (keycode == 4 || keycode == 5)
		zooming(keycode, x, y, fr);
	return (0);
}
