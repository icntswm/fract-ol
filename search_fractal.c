#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (!str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	search_fractal(t_fractol *fr, char **argv)
{
	fr->search_fractol = 0;
	if (ft_strcmp(argv[1], "Mandelbrot"))
		fr->search_fractol = 1;
	else if (ft_strcmp(argv[1], "Julia"))
		fr->search_fractol = 2;
	else if (ft_strcmp(argv[1], "BurningShip"))
		fr->search_fractol = 3;
	else if (ft_strcmp(argv[1], "Spider"))
		fr->search_fractol = 4;
	if (fr->search_fractol != 0)
		return (1);
	else
		return (0);
}
