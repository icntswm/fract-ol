#include "fractol.h"

int	exit_program(t_fractol *fr)
{
	mlx_destroy_window (fr->mlx, fr->mlx_win);
	exit (0);
}

void	key_moving(int keycode, t_fractol *fr)
{
	if (keycode == 123)
		fr->x1 += 0.05;
	else if (keycode == 124)
		fr->x1 += -0.05;
	else if (keycode == 126)
		fr->y1 += 0.05;
	else if (keycode == 125)
		fr->y1 += -0.05;
}

void	key_color_change(int keycode, t_fractol *fr)
{
	if (keycode == 257)
	{
		fr->swap_color += 144;
		if (fr->swap_color > 3000)
			fr->swap_color = 33;
	}
	else if (keycode == 6)
		fr->swap_color = 33;
}

int	key_hook(int keycode, t_fractol *fr)
{
	if (keycode == 53)
		exit_program(fr);
	else if (keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126)
		key_moving(keycode, fr);
	else if (keycode == 257 || keycode == 6)
		key_color_change(keycode, fr);
	else if (keycode == 34 || keycode == 31)
	{
		if (keycode == 34)
			fr->max_iteration += 1;
		else
			fr->max_iteration = 40;
	}
	else if (keycode == 32)
	{
		fr->width = 1000;
		fr->height = 1000;
		fr->x1 = -2.9;
		fr->y1 = -2.7;
		fr->zoom = 200;
	}
	draw(fr);
	return (0);
}
