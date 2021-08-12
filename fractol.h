#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		search_fractol;
	int		width;
	int		height;
	int		bpp;
	int		sz_line;
	int		end;
	int		max_iteration;
	int		swap_color;
	double	zoom;
	double	x;
	double	y;
	double	new_x;
	double	new_y;
	double	x1;
	double	y1;
	double	c_r;
	double	c_im;
}				t_fractol;

int		main(int argc, char **argv);
void	control_panel(char **argv);
void	ft_putendl(char *str, int num);
int		key_hook(int keycode, t_fractol *fr);
int		mouse_hook(int keycode, int x, int y, t_fractol *fr);
int		exit_program(t_fractol *fr);
void	fractal_selection(double i, double j, t_fractol *fr);
void	draw(t_fractol *fr);
int		search_fractal(t_fractol *fr, char **argv);

//compilation linux -> gcc *.c -L /usr/local/bin/ -lmlx -lXext -lX11
//compilation maсos -> gcc -lmlx -framework OpenGL -framework AppKit *.c

#endif