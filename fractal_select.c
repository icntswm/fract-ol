#include "fractol.h"

void	mandelbrot(double i, double j, t_fractol *fr)
{
	double	save_i;
	double	save_j;

	save_i = i / fr->zoom + fr->x1;
	save_j = j / fr->zoom + fr->y1;
	fr->x = 0;
	fr->y = 0;
	fr->c_r = save_i;
	fr->c_im = save_j;
}

void	julia(double i, double j, t_fractol *fr)
{
	fr->x = i / fr->zoom + fr->x1;
	fr->y = j / fr->zoom + fr->y1;
	fr->c_r = -0.543;
	fr->c_im = 0.543;
}

void	burningship(double i, double j, t_fractol *fr)
{
	fr->x = 0;
	fr->y = 0;
	fr->c_r = i / fr->zoom + fr->x1;
	fr->c_im = j / fr->zoom + fr->y1;
}

void	spider(double i, double j, t_fractol *fr)
{
	fr->x = i / fr->zoom + fr->x1;
	fr->y = j / fr->zoom + fr->y1;
	fr->c_r = fr->x;
	fr->c_im = fr->y;
}

void	fractal_selection(double i, double j, t_fractol *fr)
{
	if (fr->search_fractol == 1)
		mandelbrot(i, j, fr);
	else if (fr->search_fractol == 2)
		julia(i, j, fr);
	else if (fr->search_fractol == 3)
		burningship(i, j, fr);
	else if (fr->search_fractol == 4)
		spider(i, j, fr);
}
