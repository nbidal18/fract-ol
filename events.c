/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:33:27 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 16:58:37 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	quit_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	keyboard_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		quit_handler(fractal);
	if (keysym == XK_plus)
		fractal->definition += 10;
	else if (keysym == XK_minus)
		fractal->definition -= 10;
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	render_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
		fractal->zoom *= 1.05;
	else if (button == Button5)
		fractal->zoom *= 0.95;
	render_fractal(fractal);
	return (0);
}

int	julia_mouse_handler(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (scale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (scale(y, 2, +2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
	}
	render_fractal(fractal);
	return (0);
}
