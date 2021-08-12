#include "fractol.h"

void	equation(t_fractol *fr)
{
	fr->new_x = fr->x * fr->x - fr->y * fr->y;
	if (fr->search_fractol == 3)
		fr->new_y = fabs(2 * fr->y * fr->x);
	else
		fr->new_y = 2 * fr->y * fr->x;
	fr->x = fr->new_x + fr->c_r;
	fr->y = fr->new_y + fr->c_im;
	if (fr->search_fractol == 4)
	{
		fr->c_r = fr->c_r / 2 + fr->x;
		fr->c_im = fr->c_im / 2 + fr->y;
	}
}

int	iter_and_color(double i, double j, t_fractol *fr)
{
	int	iter_counter;
	int	color;

	color = 0;
	iter_counter = 0;
	fractal_selection(i, j, fr);
	while (iter_counter < fr->max_iteration)
	{
		equation(fr);
		if ((fr->x * fr->x + fr->y * fr->y) > 4)
			break ;
		iter_counter++;
	}
	if (iter_counter == fr->max_iteration || iter_counter == 0)
		color = 0;
	else if (iter_counter != 0 && iter_counter < fr->max_iteration)
		color = fr->swap_color * iter_counter * 10000;
	return (color);
}

void	my_mlx_pixel_put(t_fractol *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->sz_line + x * (fr->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_fractol *fr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < fr->width)
	{
		j = 0;
		while (j < fr->height)
		{
			my_mlx_pixel_put(fr, i, j, iter_and_color(i, j, fr));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
}
