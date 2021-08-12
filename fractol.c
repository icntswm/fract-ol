#include "fractol.h"

void	initialization_fract(t_fractol *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	fr->x1 = -2.9;
	fr->y1 = -2.7;
	fr->zoom = 200;
	fr->swap_color = 33;
	fr->max_iteration = 40;
}

void	init_mlx(char *name_fract, t_fractol *fr)
{
	fr->mlx = mlx_init();
	if (!fr->mlx)
	{
		ft_putendl("Mlx initialization failed", 1);
		exit (0);
	}
	fr->mlx_win = mlx_new_window(fr->mlx, fr->width, fr->height, name_fract);
	if (!fr->mlx_win)
	{
		ft_putendl("Window creation error", 1);
		exit (0);
	}
	fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
	if (!fr->img)
	{
		ft_putendl("Image creation error", 1);
		exit (0);
	}
	fr->addr = mlx_get_data_addr(fr->img, &fr->bpp, &fr->sz_line, &fr->end);
}

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if (argc < 2 || search_fractal(&fr, argv) == 0)
	{
		ft_putendl("\n     Choose from:\n\n---> Mandelbrot", 1);
		ft_putendl("---> Julia\n---> BurningShip\n---> Spider\n", 1);
		return (0);
	}
	else
		control_panel(argv);
	initialization_fract(&fr);
	init_mlx(argv[1], &fr);
	draw(&fr);
	mlx_key_hook(fr.mlx_win, key_hook, &fr);
	mlx_hook(fr.mlx_win, 17, 0, exit_program, &fr);
	mlx_mouse_hook(fr.mlx_win, mouse_hook, &fr);
	mlx_loop(fr.mlx);
	return (0);
}
