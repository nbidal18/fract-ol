#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)	
		fractal->iterations_definition -= 10;
	// zoom with keyboard
	/*
	else if (keysym == XK_i)	
		fractal->zoom *= 0.95;
	else if (keysym == XK_o)	
		fractal->zoom *= 1.05;
	*/
	//refresh the image
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	//zoom in
	if (button == Button5)
		fractal->zoom *= 0.95;
	//zoom out
	else if (button == Button4)
		fractal->zoom *= 1.05;
	//refresh the image
	fractal_render(fractal);
	return (0);
}
