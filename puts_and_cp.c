#include "fractol.h"

void	ft_putendl(char *str, int num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (num == 1)
		write(1, "\n", 1);
}

void	control_panel(char **argv)
{
	ft_putendl("\n                Control panel for fractal << ", 0);
	ft_putendl(argv[1], 0);
	ft_putendl(" >>\n", 1);
	ft_putendl("----->  Key [I] - increasing iterations", 1);
	ft_putendl("----->  Key [O] - return the original number of iterations", 1);
	ft_putendl("----->  Key [U] - return to original scale", 1);
	ft_putendl("----->  Key [L.SHIFT] - color change", 1);
	ft_putendl("----->  Key [Z] - return the original color", 1);
	ft_putendl("----->  Key [MOUSE WHEEL] - zooming", 1);
	ft_putendl("----->  Key [←][→][↑][↓] - moving", 1);
	ft_putendl("----->  Key [ESC] - exit the program\n", 1);
}
